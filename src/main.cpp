#include <Arduino.h>
#include <Wire.h>
#include "raven_display.h"
#include "raven_sound.h"
#include "raven_DisplayConfig.h"
#include "raven_pins.h"
#include "raven_boot.h"
#include "raven_screen_demo.h"
#include <WiFi.h>
#include <esp_now.h>

// Display Setup
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
DisplayManager dm(&display);
BootScreen bootScreen(&dm);
ScreenDemo screenDemo(&dm);

// Sound Setup
SoundManager sound(PIN_BUZZER, PWM_CHANNEL_SOUND);

uint8_t roverMAC[] = {0x58, 0x2A, 0xBD, 0x7E, 0x2A, 0x1C}; // replace with your rover's MAC address

#pragma pack(push, 1)
struct ControlData {
  int16_t throttle;
  int16_t steering;
  uint8_t mode;
  uint8_t buttons;   // used for LED toggle
};
#pragma pack(pop)

ControlData data;

const int DEADZONE = 15;

//  LED toggle state
bool ledState = false;
bool lastButtonState = HIGH;   // pull‑up → HIGH when not pressed

int16_t applyDeadzone(int16_t v) {
  if (abs(v) < DEADZONE) return 0;

  if (v > 0)
    return map(v, DEADZONE, 127, 0, 127);
  else
    return map(v, -DEADZONE, -127, 0, -127);
}

void setup() {
    Serial.begin(115200);
    Wire.begin();
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    sound.ravenSoundInit();

    // Boot screen
    bootScreen.show();
    screenDemo.update();
    pinMode(LED_STATUS, OUTPUT);
    pinMode(BTN_PIN, INPUT_PULLUP);
    pinMode(TOGGLE_PIN, INPUT_PULLUP);

    WiFi.mode(WIFI_STA);
    WiFi.disconnect();

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW init failed");
    return;
  }

  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, roverMAC, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed adding peer");
    return;
  }

  Serial.println("CONTROLLER READY");
}


// Loop — Input Test + Status Bar
void loop() {
    int rawX = analogRead(JOY_X);
  int rawY = analogRead(JOY_Y);

  int16_t steering = -map(rawY, 0, 4095, 127, -128);
  int16_t throttle = -map(rawX, 0, 4095, -128, 127);


  steering = applyDeadzone(steering);
  throttle = applyDeadzone(throttle);

  //  LED toggle logic
  bool currentButton = digitalRead(TOGGLE_PIN);

  if (currentButton == LOW && lastButtonState == HIGH) {
    ledState = !ledState;   // toggle ON/OFF
  }

  lastButtonState = currentButton;

  //  Send LED state in packet
  data.buttons = ledState ? 1 : 0;

  // Fill packet
  data.throttle = throttle;
  data.steering = steering;
  data.mode = 0;

  // Debug
  Serial.print("THR: ");
  Serial.print(throttle);
  Serial.print("  STR: ");
  Serial.print(steering);
  Serial.print("  LED: ");
  Serial.println(ledState);
  // Send data
  esp_now_send(roverMAC, (uint8_t *)&data, sizeof(data));

  digitalWrite(LED_STATUS, LOW);
  delay(20);
}

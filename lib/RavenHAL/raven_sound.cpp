#include "raven_sound.h"

/*
   Stores the buzzer GPIO pin and LEDC PWM channel.
*/
SoundManager::SoundManager(int buzzerPin, int pwmChannel) {
    _pin = buzzerPin;
    _channel = pwmChannel;
}

/*
   Initializes the LEDC PWM hardware for tone generation.
   Default: 2 kHz base frequency, 10-bit resolution.
*/
void SoundManager::ravenSoundInit() {
    ledcSetup(_channel, 2000, 10);
    ledcAttachPin(_pin, _channel);
}

void SoundManager::ravenPlayTone(int freq, int ms) {
    ledcWriteTone(_channel, freq); //Plays a tone at the specified frequency (Hz) for a duration (ms).
    delay(ms);
    ledcWriteTone(_channel, 0);
}

void SoundManager::ravenStopSound() {
    ledcWriteTone(_channel, 0); //Immediately stops any tone output.
}

/*
   SYSTEM SOUND EFFECTS
   Core OS feedback tones for UI and system events.
*/

/* Boot sequence — dark ascending pattern */
void SoundManager::ravenSoundBoot() {
    ravenPlayTone(440, 150);
    ravenPlayTone(349, 150);
    ravenPlayTone(293, 180);
    ravenPlayTone(261, 200);

    delay(120);

    ravenPlayTone(293, 150);
    ravenPlayTone(349, 150);
    ravenPlayTone(415, 250);
}

/* Simple short beep */
void SoundManager::ravenSoundBeep() {
    ravenPlayTone(1000, 80);
}

/* Error tone — low, harsh pattern */
void SoundManager::ravenSoundError() {
    ravenPlayTone(200, 150);
    ravenPlayTone(120, 200);
}

/* Task complete — bright ascending confirmation */
void SoundManager::ravenSoundTaskComplete() {
    ravenPlayTone(750, 70);
    ravenPlayTone(900, 70);
    ravenPlayTone(1200, 90);
}

/* Shutdown — descending tones */
void SoundManager::ravenSoundShutdown() {
    ravenPlayTone(700, 120);
    ravenPlayTone(500, 120);
}

/* Notification — short high ping */
void SoundManager::ravenSoundNotify() {
    ravenPlayTone(1200, 80);
}

/* UI click — fast, sharp tap */
void SoundManager::ravenSoundClick() {
    ravenPlayTone(1500, 30);
}


/*
   PAIRING / CONNECTIVITY MELODIES
   Used for NFC, ESP-NOW, and WiFi pairing events.
*/

/* NFC pairing — dark ascending minor pattern */
void SoundManager::ravenSoundNfcPairing() {
    ravenPlayTone(349, 120);
    ravenPlayTone(392, 120);
    ravenPlayTone(440, 150);

    delay(120);

    ravenPlayTone(392, 120);
    ravenPlayTone(440, 120);
    ravenPlayTone(523, 180);

    // Extra flourish
    ravenPlayTone(349, 120);
    ravenPlayTone(392, 120);
    ravenPlayTone(440, 150);
}

/* ESP-NOW pairing — fast digital ascent */
void SoundManager::ravenSoundEspNowPairing() {
    ravenPlayTone(659, 80);
    ravenPlayTone(740, 80);
    ravenPlayTone(880, 100);

    delay(80);

    ravenPlayTone(740, 80);
    ravenPlayTone(880, 80);
    ravenPlayTone(988, 140);
}

/* WiFi pairing — smooth ascending handshake */
void SoundManager::ravenSoundWifiPairing() {
    ravenPlayTone(523, 110);
    ravenPlayTone(587, 110);
    ravenPlayTone(659, 130);

    delay(100);

    ravenPlayTone(587, 110);
    ravenPlayTone(659, 110);
    ravenPlayTone(784, 160);
}


/*
   VEHICLE / FPV / ROBOTICS SOUNDS
   Used by Raven Wraith UGV, future UAVs, and robotic systems.
*/

/* Arm — classic FPV rising confirmation */
void SoundManager::ravenSoundArm() {
    ravenPlayTone(523, 90);
    ravenPlayTone(659, 90);
    ravenPlayTone(784, 120);

    delay(100);

    ravenPlayTone(880, 160);
}

/* Disarm — descending safe pattern */
void SoundManager::ravenSoundDisarm() {
     ravenPlayTone(784, 120);
    ravenPlayTone(659, 120);
    ravenPlayTone(523, 150);

    delay(80);

    ravenPlayTone(392, 200);
}

/* Beacon — repeating locator pulse */
void SoundManager::ravenSoundBeacon() {
    ravenPlayTone(880, 180);
    delay(120);
    ravenPlayTone(523, 200);
    delay(300);

    ravenPlayTone(880, 180);
    delay(120);
    ravenPlayTone(523, 200);
    delay(300);
}

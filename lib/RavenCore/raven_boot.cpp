#include "raven_boot.h"

// instantiate sound manager used by the boot screen
static SoundManager sound(PIN_BUZZER, PWM_CHANNEL_SOUND);

BootScreen::BootScreen(DisplayManager* display) {
    _display = display;
}

void BootScreen::show() {  //shows the boot screen

    _display->ravenClearDisplay();
    _display->ravenDrawBitmap(30, 8, raven_logo, 64, 64);
    _display->ravenSetTextColor(SSD1306_WHITE);
    _display->ravenHeaderText("RavenOS", 42);
    _display->ravenRefresh();
    sound.ravenSoundBoot(); // Play boot sound sequence
    delay(1000); 
    _display->ravenClearDisplay();
    _display->ravenThemeInvertOn();
    _display ->ravenDrawBitmap(30, 8, raven_logo, 64, 64);
    _display->ravenHeaderText("WHISPER", 47);
    _display->ravenRefresh();
    delay(2000);
    _display->ravenThemeInvertOff();
    _display->ravenClearDisplay();
    _display->ravenRefresh();
}
#ifndef RAVEN_SCREEN_DEMO_H
#define RAVEN_SCREEN_DEMO_H

#include <Arduino.h>
#include <raven_display.h>
#include <icons/raven_full_battery.h>
#include <icons/raven_no_battery.h>
#include <icons/raven_wifi_connected.h>
#include <icons/raven_sound_on.h>
#include <icons/settings_icon.h>
#include <icons/raven_wifi_disconnected.h>
#include <icons/info_icon.h>
#include <icons/settings_icon.h>
#include <icons/sub_ghz_icon.h>

class ScreenDemo {
public:
    ScreenDemo(DisplayManager* display);

    void begin();
    void update();                 // Draw the battery icon

private:
    DisplayManager* _display;
    void drawIcons();
};

#endif

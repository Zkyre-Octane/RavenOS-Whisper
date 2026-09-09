#pragma once

#include "raven_display.h"
#include "raven_display.h"
#include "images/raven_Logo.h"
#include "raven_sound.h"
#include "raven_pins.h"

class BootScreen {
public:
    BootScreen(DisplayManager* display);
    void show();

private:
    DisplayManager* _display;
};
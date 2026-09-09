#include <raven_screen_demo.h>

/*
NOTE: this class is only used for testing in this version of RavenOS,
      it will be removed or reworked in future versions, for the moment it is used 
      as a placeholder to show the battery, wifi and other icons on the screen.
*/
ScreenDemo::ScreenDemo(DisplayManager* display) {
    _display = display;
}

void ScreenDemo::begin() {
}

void ScreenDemo::update() { //redraws the status bar 
    drawIcons();
}

void ScreenDemo::drawIcons() { //this functions draws the main icons on the top of the screen
        _display->ravenDrawBitmap(0, 0, full_battery_icon, 24, 16);
        _display->ravenDrawBitmap(85, 0, wifi_connected_icon, 19, 16);
        _display->ravenDrawBitmap(108, 0, sound_on_icon, 20, 16);
        _display->ravenSetTextWrap(false);
        _display->ravenSetPicopixelFont();
        _display->ravenShowMessage("Wraith", 50, 59, 2);
        _display->ravenRefresh();
}

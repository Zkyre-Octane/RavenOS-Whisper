#include <raven_display.h>

DisplayManager::DisplayManager(Adafruit_SSD1306* display) { // Constructor to initialize the display manager with the provided display object
    _display = display; // Initialize the display object
}


// System display

void DisplayManager::ravenShowMessage(const char* msg, int x, int y, int size) { // Show message on specific line
    _display->setCursor(x, y); // set the cursor at the indicated position
    _display->print(msg); // print the specified message 
}

void DisplayManager::ravenClearDisplay() {
    _display->clearDisplay(); // Clear the display 
}

void DisplayManager::ravenRefresh() {
    _display->display(); // Refresh the display with current buffer content
}

void DisplayManager::ravenSetTextColor(int color) {
    _display->setTextColor(color); // Set the drawing color (SSD1306_WHITE or SSD1306_BLACK)
}

// Header System
void DisplayManager::ravenDrawHeader() {
    _display->drawRect(0, 0, 128, 16, SSD1306_WHITE); // Draw a rectangle at the top of the screen
}

void DisplayManager::ravenHeaderText(const char* text, int x) {
    _display->setCursor(x, 4); // Set the cursor to the top of the screen
    _display->print(text); // Print the header text
}

void DisplayManager::ravenHeaderIcon(const uint8_t* bitmap, int width, int height, int x, int y) {
    _display->drawBitmap(x, y, bitmap, width, height, SSD1306_WHITE); // Draw the header icon at the specified position
}

// Display control functions
void DisplayManager::ravenThemeInvertOn() {
    _display->invertDisplay(true); // Invert the display colors
}

void DisplayManager::ravenThemeInvertOff() {
    _display->invertDisplay(false); // Revert the display colors to normal
}

// Drawing primitives
void DisplayManager::ravenPixel(int x, int y) {
    _display->drawPixel(x, y, SSD1306_WHITE); // Draw a pixel at the specified coordinates
}

void DisplayManager::ravenHorizontalLine(int y, int length) {
    _display->drawFastHLine(0, y, length, SSD1306_WHITE); // Draw a horizontal line at the specified coordinates
}

void DisplayManager::ravenVerticalLine(int x, int length) {
    _display->drawFastVLine(x, 0, length, SSD1306_WHITE); // Draw a vertical line at the specified coordinates
}

void DisplayManager::ravenDrawRect(int x, int y, int width, int height) {
    _display->drawRect(x, y, width, height, SSD1306_WHITE); // Draw a rectangle at the specified coordinates
}

void DisplayManager::ravenFillRect(int x, int y, int width, int height) {
    _display->fillRect(x, y, width, height, SSD1306_WHITE); // Fill a rectangle at the specified coordinates
}

void DisplayManager::ravenRoundRect(int x, int y, int width, int height, int radius) {
    _display->drawRoundRect(x, y, width, height, radius, SSD1306_WHITE); // Draw a rounded rectangle at the specified coordinates
}

void DisplayManager::ravenFillRoundRect(int x, int y, int width, int height, int radius) {
    _display->fillRoundRect(x, y, width, height, radius, SSD1306_WHITE); // Fill a rounded rectangle at the specified coordinates
}

void DisplayManager::ravenSetCursor(int x, int y) {
    _display->setCursor(x, y); // Set the cursor position
}

void DisplayManager::ravenDrawBitmap(int x, int y, const uint8_t* bitmap, int width, int height) {
    _display->drawBitmap(x, y, bitmap, width, height, SSD1306_WHITE); // Draw a bitmap at the specified coordinates
}

// Text helpers

void DisplayManager::ravenSetTextSize(int size) {
    _display->setTextSize(size); // Set the text size
}

void DisplayManager::ravenCenterText(const char* text, int y) {
    int16_t x1, y1; // Variables to hold the bounding box coordinates
    uint16_t w, h; // Variables to hold the width and height of the text
    _display->getTextBounds(text, 0, y, &x1, &y1, &w, &h); // Get the bounding box of the text
    int x = (128 - w) / 2; // Calculate the x position to center the text
    _display->setCursor(x, y); // Set the cursor to the calculated position
    _display->print(text); // Print the centered text
}

void DisplayManager::ravenSetPicopixelFont(){
    _display->setFont(&Picopixel); // Set the Picopixel font for text rendering
}

void DisplayManager::ravenSetTextWrap(bool wrap) {
    _display->setTextWrap(wrap); // Set text wrapping behavior
}


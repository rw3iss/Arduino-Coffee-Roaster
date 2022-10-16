#include "Screen.h"

Screen::Screen() {
    //screen = TFT_HX8357();  // Invoke custom library
}

void Screen::setup() {
    tft = TFT_HX8357();  // Invoke custom library

    tft.init();
    tft.setRotation(1);

    width = tft.width();
    height = tft.height();

    tft.fillScreen(HX8357_BLACK);
    tft.setTextColor(HX8357_WHITE, HX8357_BLACK);
}


void Screen::write(char s[], int x, int y, int fontSize) {
    //screen.write("Started", 5, 5, 4);
    // char ts[32];
    // snprintf(ts, sizeof(ts), "TARGET TEMP = %d", currentTemp);
    tft.drawString(s, x, y, fontSize);
}
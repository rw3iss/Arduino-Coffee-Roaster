#pragma once

#include <TFT_HX8357.h>

class Screen {
   public:
    Screen();
    void setup();
    void write(char s[], int x, int y, int fontSize);

   private:
    TFT_HX8357 tft;
    int width;
    int height;
};

Screen::Screen(){
    // screen = TFT_HX8357();  // Invoke custom library
};

void Screen::setup() {
    tft = TFT_HX8357();  // Invoke custom library

    tft.init();
    tft.setRotation(1);

    width = tft.width();
    height = tft.height();

    tft.fillScreen(HX8357_BLACK);
    tft.setTextColor(HX8357_WHITE, HX8357_BLACK);
};

void Screen::write(char s[], int x, int y, int fontSize) {
    // screen.write("Started", 5, 5, 4);
    //  char ts[32];
    //  snprintf(ts, sizeof(ts), "TARGET TEMP = %d", currentTemp);
    tft.drawString(s, x, y, fontSize);
};

// // Manages an arbitrary view state to be drawn/updated on demand, in other words a stack of views in memory, essentially.
// // The views override the pin modes and handlers (must receive AppIOConfig)
// class ViewManager {
// /* ie:
// addView(id, view);
// showView(id);

// */
// };

// class View {

//     public:
//       //draw(something);
//       //clear;

//     private:
//       // Button powerButton;
//       // Button heaterButton;
//       // Button tempUpButton;
//       // Button tempDownButton;
//       // Button motorButton;
//       // Button ejectButton;

//       // Thermo heaterTemp;
//       // Thermo ambientTemp;

// };
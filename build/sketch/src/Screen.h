#line 1 "C:\\Users\\rw3iss\\Documents\\Arduino\\Projects\\Roaster\\src\\Screen.h"
#ifndef Screen_h
#define Screen_h

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

#endif;
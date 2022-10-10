#line 1 "C:\\Users\\rw3iss\\Documents\\Arduino\\Projects\\roaster\\app\\App.h"
#ifndef App_h
#define App_h

#include "./IOConfig.h";
#include "./Screen.h";
#include "./UI.h";
#include "./Roast.h";
#include "./RoastProfile.h";

class App {

    public:
        App();
        void setup();
        void loop();

    private:
        UI ui;
        Screen screen;

};

#endif
#ifndef App_h
#define App_h

#include "./UI.h";
#include "./Screen.h";
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
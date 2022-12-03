#ifndef UI_h
#define UI_h

// #include "./Button.h"
// #include "max6675.h"

class ViewManager {
   public:
    ViewManager();
    ~ViewManager();

    void setup();
    void loop();

   private:
    void init();
    void onEvent();
    void onStateChange();

    // Button powerBtn;
    // Button heaterBtn;
    // Button motorBtn;
    // Button ejectBtn;
    // Button tempUpBtn;
    // Button tempDownBtn;

    // MAX6675 thermoHeater(PIN_THERMO1_CLK, PIN_THERMO1_CS, PIN_THERMO1_DO);

    // Screen screen;
    // profiles;
};

ViewManager::ViewManager(){};

void ViewManager::setup() {
    this->init();
};

/** Sets up pages, columns, app views */
void ViewManager::init(){};

// void UI::loop(){};

void ViewManager::onEvent() {
    // handle a control/interface/hardware event.
}

void ViewManager::onStateChange() {
    //: tell the Renderer to redraw the app state to the screen.
}

ViewManager::~ViewManager(){};

#endif
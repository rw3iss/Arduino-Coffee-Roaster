#pragma once

#include <ArduinoSTL.h>
#include <stdlib.h>

#include <functional>
#include <map>
#include <string>
#include <vector>

#include "Arduino.h"
#include "Screen.h"
#include "ViewManager.h"

using namespace std;

/**
 * App - Manages the main application setup and event loop. Delegates other responsibilities to:
 * UI - manages the UI/view state, passes off updates to a ViewRenderer
 */
class App {
   public:
    App();
    ~App();

    void setup(void (*cb)(/* pass config */));
    void start();
    void loop();

   private:
    bool isStarted = false;
    ViewManager viewManager;
    Screen screen;
};

App::App() {
    // setup hardware controls
    this->screen = Screen();
    // setup app UI/views
    this->viewManager = ViewManager();
};

App::~App() {
    delete &this->viewManager;
    delete &this->screen;
}

void App::setup(void (*cb)(/* pass config? */)) {
    this->screen.setup();
    this->viewManager.setup();

    // todo: listen for control and state change events... ie. from viewManager and controlManager, etc...
    cb();
};

void App::start() {
    this->isStarted = true;
    // screen.write("App started!", 5, 5, 4);
    // Serial.println("App started.");
};

void App::loop() {
    if (this->isStarted) {
        // ui.loop();
    }
}
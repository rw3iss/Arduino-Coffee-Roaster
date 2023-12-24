#pragma once

#include "App.h"
#include "views/HomeView.h"

/**
 * RoasterApp - Main Roaster Arduino application.
 */
class RoasterApp : public App {
    public:
        RoasterApp() : App(){};
        ~RoasterApp(){};

        virtual void setup();
        virtual void start();
        virtual void loop();

    private:
        HomeView *homeView;
};

void RoasterApp::setup() {
    debug("RoasterApp::setup()");
    screen->setup();
    viewManager->setup();
};

void RoasterApp::start() {
    debug("RoasterApp::start()");
    isStarted = true;
    screen->write("Roaster App v1.0", 5, 5, 4);

    homeView = new HomeView();
    viewManager->setView(homeView);
};

void RoasterApp::loop() {
    debug("RoasterApp::loop()");
    delay(1000);

    // if (appLoop % 2 == 0) {
    //     screen.write("even", 4, 4, 2);
    // } else {
    //     screen.write("odd", 7, 7, 3);
    // }

    if (isStarted) {
        // ui.loop();
    }
};

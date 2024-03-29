#pragma once

#include <Arduino.h>
#include <ArduinoSTL.h>
#include "IOConfig.h"
#include "Debug.h"
// #include <SoftwareSerial.h>
#include "Screen.h"
#include "ScreenDebug.h"
#include "StringUtils.h"
#include "views/View.h"
#include "views/ViewRenderer.h"
#include "views/ViewManager.h"

// SoftwareSerial softSerial(0, 1);

// namespace std {
// ohserialstream cout(mySerial);
// ihserialstream cin(mySerial);
// }  // namespace std

using namespace std;

int appLoop = 0;

/**
 * App - Manages the main application setup and event loop. Delegates other
 * responsibilities to: UI - manages the UI/view state, passes off updates to a
 * ViewRenderer
 */
class App {
    public:
        App();
        ~App();

        void setup();  // void (*cb)(/* pass config */));
        void start();
        void loop();
        void debug(char s[]);

        bool isStarted = false;
        Screen *screen; // TFT sceen interface
        ViewRenderer *viewRenderer;
        ViewManager *viewManager;
        ScreenDebug *screenDebug;
};

App::App() {
    Serial.begin(9600);
    // softSerial.begin(9600);
    // ArduinoSTL_Serial.connect(softSerial);
    debug("App::App()");

    screen = new Screen();
    screenDebug = new ScreenDebug(screen);
    viewRenderer = new ViewRenderer(screen);
    viewManager = new ViewManager(viewRenderer); // manage current view data/state... updates should send to renderer, which draws to screen
};

App::~App() {
    // delete &viewManager;
    // delete &screen;
    // delete &screenDebug;
}

void App::setup() {  // void (*cb)(/* pass config? */)) {
    debug("App::setup()");

    screen->setup();
    viewManager->setup();

    // debug("App setup complete.");

    // todo: listen for control and state change events... ie. from viewManager
    // and controlManager, etc...
    // cb();
};

void App::start() {
    debug("App::start()");
    isStarted = true;
    screen->write("App v1.0", 5, 5, 4);
};

void App::loop() {
    debug("App::loop()");
    delay(1000);

    // if (appLoop % 2 == 0) {
    //     screen.write("even", 4, 4, 2);
    // } else {
    //     screen.write("odd", 7, 7, 3);
    // }

    if (isStarted) {
        // ui.loop();
    }
}

void App::debug(char s[]) {
    Serial.print("🐞 ");
    Serial.println(s);
    // softSerial.println(s);
    screenDebug->write(s);
};
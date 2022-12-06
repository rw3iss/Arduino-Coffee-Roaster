#pragma once

#include <Arduino.h>
#include <ArduinoSTL.h>
// #include <SoftwareSerial.h>
#include "Screen.h"
#include "ScreenDebug.h"
#include "StringUtils.h"
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

    private:
        bool isStarted = false;
        Screen *screen;
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
    viewManager = new ViewManager();
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

    screen->write("Roaster App v1.0", 5, 5, 4);
    //  Serial.println("App started.");
};

void App::loop() {
    debug("App::loop()");
    // debug("L.");
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
    Serial.print("🐞");
    Serial.println(s);
    // softSerial.println(s);
    screenDebug->write(s);
};
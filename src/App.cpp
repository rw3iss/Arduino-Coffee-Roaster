#include "./App.h"

App::App() {}

void App::setup() {
    screen.setup();
    ui.setup();

    screen.write("Started.", 5, 5, 4);
    Serial.println("App started.");
}

void App::loop() {
    ui.loop();
}
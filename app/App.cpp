#include "./App.h"

App::App() {}

void App::setup() {
    screen = Screen();
    ui.setup();
}

void App::loop() {
    ui.loop();
}
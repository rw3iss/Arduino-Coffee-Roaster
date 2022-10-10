#line 1 "C:\\Users\\rw3iss\\Documents\\Arduino\\Projects\\roaster\\app\\App.cpp"
#include "./App.h"

App::App() {}

void App::setup() {
    screen = Screen();
    ui.setup();
}

void App::loop() {
    ui.loop();
}
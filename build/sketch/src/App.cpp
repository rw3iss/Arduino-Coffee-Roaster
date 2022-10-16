#line 1 "C:\\Users\\rw3iss\\Documents\\Arduino\\Projects\\Roaster\\src\\App.cpp"
#include "./App.h"

App::App() {}

void App::setup() {
    screen.setup();
    ui.setup();
    
    view.setup();(

    screen.write("Started.", 5, 5, 4);
    Serial.println("App started.");
}

void App::loop() {
    ui.loop();
}
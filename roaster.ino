#include <Arduino.h>
#include <stdlib.h>
#include "./src/App.h"

App app;

void setup() {
    app.setup();
}

void loop() {
    app.loop();
}
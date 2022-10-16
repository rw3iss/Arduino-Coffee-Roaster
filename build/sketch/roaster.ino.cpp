#line 1 "C:\\Users\\rw3iss\\Documents\\Arduino\\Projects\\Roaster\\Roaster.ino"
#include <Arduino.h>
#include <stdlib.h>
#include "./src/App.h"

App app;

#line 7 "C:\\Users\\rw3iss\\Documents\\Arduino\\Projects\\Roaster\\Roaster.ino"
void setup();
#line 11 "C:\\Users\\rw3iss\\Documents\\Arduino\\Projects\\Roaster\\Roaster.ino"
void loop();
#line 7 "C:\\Users\\rw3iss\\Documents\\Arduino\\Projects\\Roaster\\Roaster.ino"
void setup() {
    app.setup();
}

void loop() {
    app.loop();
}

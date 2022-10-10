#include <Arduino.h>
#line 1 "C:\\Users\\rw3iss\\Documents\\Arduino\\Projects\\roaster\\roaster.ino"
#include "./app/App.h";

App app;

#line 5 "C:\\Users\\rw3iss\\Documents\\Arduino\\Projects\\roaster\\roaster.ino"
void setup();
#line 10 "C:\\Users\\rw3iss\\Documents\\Arduino\\Projects\\roaster\\roaster.ino"
void loop();
#line 5 "C:\\Users\\rw3iss\\Documents\\Arduino\\Projects\\roaster\\roaster.ino"
void setup() {
    app = App();
    app.setup();
}

void loop() {
    app.loop();
}


#include <Arduino.h>
#line 1 "/Users/rw3iss/Documents/Arduino/Projects/Roaster/Roaster.ino"
#include <ArduinoSTL.h>

#include "RoasterApp.h"

using namespace std;

App app;

typedef int (*CallbackType)(float);

#line 11 "/Users/rw3iss/Documents/Arduino/Projects/Roaster/Roaster.ino"
void setup();
#line 19 "/Users/rw3iss/Documents/Arduino/Projects/Roaster/Roaster.ino"
void loop();
#line 11 "/Users/rw3iss/Documents/Arduino/Projects/Roaster/Roaster.ino"
void setup() {
    app = RoasterApp();
    app.setup([]() -> void {
        printf("App setup complete, starting...");
        app.start();
    });
}

void loop() {
    app.loop();
}

#include <ArduinoSTL.h>

#include "RoasterApp.h"

using namespace std;

App app;

typedef int (*CallbackType)(float);

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
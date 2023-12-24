#include "RoasterApp.h"

RoasterApp app;

void setup() {
    app = RoasterApp();
    // app = App();
    app.setup();
    app.start();

    //  []() -> void {
    //      app.debug("Starting app...");
    //      app.start();
    //      app.debug("App started.");
    //  });

    delay(1000);
}

void loop() {
    app.loop();
}
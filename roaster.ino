#include "./app/App.h";

App app;

void setup() {
    app = App();
    app.setup();
}

void loop() {
    app.loop();
}

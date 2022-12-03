# 1 "/Users/rw3iss/Documents/Arduino/Projects/Roaster/Roaster.ino"
# 2 "/Users/rw3iss/Documents/Arduino/Projects/Roaster/Roaster.ino" 2

# 4 "/Users/rw3iss/Documents/Arduino/Projects/Roaster/Roaster.ino" 2

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

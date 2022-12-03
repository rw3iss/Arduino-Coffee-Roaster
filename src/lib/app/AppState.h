#pragma once

/**
 * AppState - Manages current application overall state.
 * -Clients can listen for state changes and react.
 */
class AppState {
   public:
    AppState();
    ~AppState();

    void* get(char[]){};
    void* set(char[], void*){};
    void listen(){};

   private:
};

AppState::AppState() {
}

AppState::~AppState() {
}

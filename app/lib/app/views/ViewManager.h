#pragma once

class ViewManager {
    public:
        ViewManager();
        ~ViewManager();

        void setup();
        void loop();

    private:
        void onEvent();        // handle control event (process/change state)
        void onStateChange();  // handle view/component state change (redraw)
};

ViewManager::ViewManager(){};

void ViewManager::setup(){};

void ViewManager::loop(){
    /* if: has state change (ie. re-render is queued, let the loop redraw? */
};

// void UI::loop(){};

void ViewManager::onEvent() {
    // handle a control/interface/hardware event.
}

void ViewManager::onStateChange() {
    //: tell the Renderer to redraw the app state to the screen.
}

ViewManager::~ViewManager(){};

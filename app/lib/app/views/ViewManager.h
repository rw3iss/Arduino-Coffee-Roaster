#pragma once

class ViewManager {
    public:
        ViewManager(ViewRenderer *_renderer) { renderer = _renderer; };
        ~ViewManager();

        void setup();
        void loop();

        void setView(View *view);
        void update();  // call to render current view after updates

    private:
        ViewRenderer *renderer;
        View *currentView;
        void onEvent();        // handle control event (process/change state)
        void onStateChange();  // handle view/component state change (redraw)
};

void ViewManager::setup(){};

void ViewManager::loop(){
    /* if: has state change (ie. re-render is queued, let the loop redraw? */
};

void ViewManager::setView(View *view) {
    currentView = view;
    update();
};

void ViewManager::update() {
    if (currentView == NULL) {
        debug("No view to render.");
    } else {
        renderer->render(currentView);
    }
};

// void UI::loop(){};

void ViewManager::onEvent() {
    // handle a control/interface/hardware event.
}

void ViewManager::onStateChange() {
    //: tell the Renderer to redraw the app state to the screen.
}

ViewManager::~ViewManager(){};

#pragma once

#include <Arduino.h>
#include <vector>
#include "ViewState.h"
#include "../events/Event.h"
#include "components/Component.h"

using namespace std;

/**
 * View - Base view.
 */
class View : public Component {
    public:
        View() : Component("View"){};
        View(string name) : Component(name){};
        ~View(){};

        void handleEvent(Event* event);

    private:
        ViewState state;
};

void View::handleEvent(Event* event){};
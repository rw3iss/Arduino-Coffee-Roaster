#pragma once

#include <Arduino.h>
#include <vector>
#include "ViewState.h"
#include "events/Event.h"
#include "views/components/Component.h"

using namespace std;

/**
 * Screen - Base screen.
 */
class View : public Component {
    public:
        View();
        ~View();

        void handleEvent(Event* event);

    private:
        ViewState state;
};

View::View(){};

View::~View(){};

void View::handleEvent(Event* event){};
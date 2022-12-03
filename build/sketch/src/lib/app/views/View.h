#line 1 "/Users/rw3iss/Documents/Arduino/Projects/Roaster/src/lib/app/views/View.h"
#pragma once

#include <vector>

#include "Arduino.h"
#include "Component.h"

using namespace std;

/**
 * Screen - Base screen.
 */
class View : public Component {
   public:
    View();
    ~View();
};

View::View() {
}

View::~View() {
}
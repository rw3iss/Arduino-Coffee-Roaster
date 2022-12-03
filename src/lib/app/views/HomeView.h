#pragma once

#include "Arduino.h"
#include "View.h"

/**
 * HomeScreen - sets up a component stack for the default / HomeScreen.
 */
class HomeView : public View {
   public:
    HomeView();
    ~HomeView();

   private:
};

HomeView::HomeView() {
    // initialize Columns...
}

HomeView::~HomeView() {
}
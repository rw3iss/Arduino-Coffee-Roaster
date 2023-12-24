#pragma once

#include "View.h"
#include "LabelValue.h"
#include "Button.h"

/**
 * HomeScreen - sets up a component stack for the default / HomeScreen.
 */
class HomeView : public View {
    public:
        HomeView();
        ~HomeView(){};

    private:
        // TODO: get current state from app / roast config
        bool motorOn;

        LabelValue *motorLabel;
        Button *motorBtn;
        void handleMotorClick();

        void tick();
};

// setup the view on creation
HomeView::HomeView() : View("Home"), motorOn(false) {
    motorLabel = new LabelValue("Motor: ", motorOn ? "ON" : "OFF");

    // add button listener
    motorBtn = new Button(PIN_MOTOR_BTN);
    //motorBtn->button.attachClick(handleMotorClick, this);

    addChild(motorLabel);
};

void HomeView::handleMotorClick() {
    debug("Motor clicked!");
    motorOn = !motorOn;
    motorLabel->setValue(motorOn ? "ON" : "OFF");
};


void HomeView::tick() {
   //motorBtn->button.tick();
}

#include "./UI.h"

#include "IOConfig.h"

UI::UI() {
}

void UI::initIO() {
    // init Buttons

    // init Screen
    // pinMode(LED_BUILTIN, OUTPUT);

    // pinMode(PIN_POWER_BTN, INPUT);
    // //enablePower();

    // pinMode(PIN_HEATER_BTN, INPUT_PULLUP);
    // pinMode(PIN_HEATER, OUTPUT);

    // pinMode(PIN_TEMP_UP_BTN, INPUT_PULLUP);
    // pinMode(PIN_TEMP_DOWN_BTN, INPUT_PULLUP);

    // pinMode(PIN_EJECT_BTN, INPUT_PULLUP);
}

void UI::setup() {
    this->initIO();
}

void UI::loop() {


}
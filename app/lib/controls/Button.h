
#ifndef Button_h
#define Button_h

//#include <max6675.h>
#include <Arduino.h>
#include "OneButton.h"

class Button {
    private:
        int value;

    public:
        OneButton button;

        explicit Button(uint8_t pin) : button(pin) {
            button.attachClick(
                [](void *scope) { ((Button *)scope)->Clicked(); }, this);
            button.attachDoubleClick(
                [](void *scope) { ((Button *)scope)->DoubleClicked(); }, this);
            button.attachLongPressStart(
                [](void *scope) { ((Button *)scope)->LongPressed(); }, this);
        }

        void Clicked() {
            debug("Click then value++");
            value++;
        }

        void DoubleClicked() {
            debug("DoubleClick");
        }

        void LongPressed() {
            debug("LongPress and the value is");
            debug(value);
        }

        void handle() { button.tick(); }
};

#endif;
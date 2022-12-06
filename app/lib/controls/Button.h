
#ifndef Button_h
#define Button_h
#include <max6675.h>

#include "OneButton.h"

class Button {
    private:
        OneButton button;
        int value;

    public:
        explicit Button(uint8_t pin) : button(pin) {
            button.attachClick(
                [](void *scope) { ((Button *)scope)->Clicked(); }, this);
            button.attachDoubleClick(
                [](void *scope) { ((Button *)scope)->DoubleClicked(); }, this);
            button.attachLongPressStart(
                [](void *scope) { ((Button *)scope)->LongPressed(); }, this);
        }

        void Clicked() {
            // Serial.println("Click then value++");
            value++;
        }

        void DoubleClicked() {
            // Serial.println("DoubleClick");
        }

        void LongPressed() {
            // Serial.println("LongPress and the value is");
            // Serial.println(value);
        }

        void handle() { button.tick(); }
};

#endif;
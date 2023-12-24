#pragma once

#include <vector>
#include "Component.h"

using namespace std;

enum Orientation : int {
    HORIZONTAL = 0,
    VERTICAL = 1
};

/**
 * LabelValue - represents a component with a label and displayed value
 */
class LabelValue : public Component {
    public:
        LabelValue() : Component("LabelValue"){};
        LabelValue(string _label, string _value) : Component("LabelValue") {
            label = _label;
            value = _value;
        };
        ~LabelValue(){};

        void setLabel(string _label);
        void setValue(string _value);
        void setOrientation(Orientation _orientation);

    private:
        string label;
        string value;
        Orientation orientation = HORIZONTAL;
};

void LabelValue::setLabel(string _label) {
    label = _label;
};

void LabelValue::setValue(string _value) {
    value = _value;
};

void LabelValue::setOrientation(Orientation _orientation) {
    orientation = _orientation;
};
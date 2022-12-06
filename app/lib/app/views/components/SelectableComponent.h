#pragma once

#include <string>
#include <vector>

#include "Component.h"

using namespace std;

/**
 * Component - A basic component with basic abilities.
 */
class SelectableComponent : public Component {
    public:
        SelectableComponent(string newType) : Component(newType){};
        SelectableComponent() : SelectableComponent("SelectableComponent"){};
        ~SelectableComponent(){};
};
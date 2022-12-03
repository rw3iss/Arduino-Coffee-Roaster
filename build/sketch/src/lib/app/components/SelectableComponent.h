#line 1 "/Users/rw3iss/Documents/Arduino/Projects/Roaster/src/lib/app/components/SelectableComponent.h"
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
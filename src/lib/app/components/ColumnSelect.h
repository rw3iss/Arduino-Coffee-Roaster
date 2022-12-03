#pragma once

#include <vector>

#include "Arduino.h"
#include "Component.h"
#include "SelectableComponent.h"

using namespace std;

uint16_t MAX_ROWS = 6;

/**
 * ColumnSelect - represents a column of components, that can each be selected.
 */
class ColumnSelect : public Component {
   public:
    ColumnSelect() : Component("ColumnSelect"){};
    ~ColumnSelect(){};

    uint16_t addChild(SelectableComponent* component);
    uint16_t addChild(Component* component);

    Component* ColumnSelect::selectNext();
    Component* ColumnSelect::selectPrevious();

   private:
    uint16_t selectedIndex = 0;
};

// Returns the size of the new children.
uint16_t ColumnSelect::addChild(SelectableComponent* comp) {
    this->children->push_back(comp);
    return this->children->size();
}

// Returns the size of the new children.
uint16_t ColumnSelect::addChild(Component* comp) {
    throw "ColumnSelect can only use SelectableComponent as children.";
}

Component* ColumnSelect::selectNext() {
    uint16_t size = this->children->size();
    if (this->selectedIndex < size) this->selectedIndex++;
    return this->getChild(this->selectedIndex);
    // todo: trigger redraw;
}

Component* ColumnSelect::selectPrevious() {
    if (this->selectedIndex > 0) this->selectedIndex--;
    return this->getChild(this->selectedIndex);
    // todo: trigger redraw;
}

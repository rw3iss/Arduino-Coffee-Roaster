#pragma once

#include <string>
#include <vector>

using namespace std;

/**
 * Component - A basic component with basic abilities.
 */
class Component {
    public:
        Component(string type);
        Component() : Component("unknown"){};
        ~Component();

        uint16_t addChild(Component* control);
        Component* removeChild(uint16_t index);
        Component* getChild(uint16_t index);

        string type;
        vector<Component*>* children;
};

Component::Component(string newType) { this->type = newType; }

Component::~Component() { delete this->children; }

// Returns the size of the new children.
uint16_t Component::addChild(Component* comp) {
    this->children->push_back(comp);
    return this->children->size();
}

// Returns the removed child, otherwise throws an exception.
Component* Component::removeChild(uint16_t index) {
    uint16_t const size = this->children->size();
    if (index > size) {
        debug("removeChild() index is greater than children size.");
    } else {
        // iterate to position and erase
        uint16_t cPos = 0;
        vector<Component*>::iterator it = this->children->begin();
        while (cPos++ < index) it++;
        return *this->children->erase(it);
    }
}

// Returns the child Component at index, otherwise NULL.
Component* Component::getChild(uint16_t index) {
    uint16_t size = this->children->size();
    if (index < 0 || index > size)
        return NULL;  // throw "getChild() index is greater than children
                      // size.";

    // iterate to position and erase
    uint16_t cPos = 0;
    vector<Component*>::iterator it = this->children->begin();
    while (cPos++ < index) it++;
    return *it;
}

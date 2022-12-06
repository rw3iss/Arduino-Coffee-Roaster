#pragma once

struct State {};

/**
 * ViewState - Contains arbitrary state values for a given view.
 * The values are reactive and will fire a StateChange event to the view when a
 * value is changed.
 */
class ViewState {
    public:
        ViewState();
        ~ViewState();

    private:
};

ViewState::ViewState() {}

ViewState::~ViewState() {}
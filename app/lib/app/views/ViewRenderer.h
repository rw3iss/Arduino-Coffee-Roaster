#pragma once

/**
 * ViewRenderer - Handles drawing of a particular View to a Screen.
 * The View child heirarchy is laid out in a normal 1:1 ratio, and then scaled
 * to the Screen dimensions, then drawn.
 *
 * The purpose of this class is to render views to a screen.
 *
 */
class ViewRenderer {
    public:
        ViewRenderer(Screen *_screen) { screen = _screen; };
        ~ViewRenderer() {};

        void render(View *view);

    private:
        Screen *screen;
        void drawComponent(Component *component);
};

void ViewRenderer::render(View *view) {
    debug("Render view:");
    debug(view->type.c_str());
    uint16_t pos = 0;
    uint16_t size = view->children->size();
    vector<Component*>::iterator it = view->children->begin();
    while (pos++ < size) {
        drawComponent(*it);
        it++;
    }
};

void ViewRenderer::drawComponent(Component *component) {
    debug("Draw component:");
    debug(component->type.c_str());
    
};
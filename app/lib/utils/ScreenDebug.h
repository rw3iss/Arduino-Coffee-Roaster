#pragma once

#include "Screen.h"

#include <string>
#include <vector>

using namespace std;

const int MAX_HISTORY = 5;
const int DEBUG_XPOS = 240;  // 480 max
const int DEBUG_YPOS = 0;    // 320 max
const int DEBUG_FONT_SIZE = 2;

int yPos = DEBUG_YPOS;

/**
 * ScreenDebug - Maintains a list/history of debug entries, and renders them to
 * the screen in a scrolling view.
 */
class ScreenDebug {
    public:
        ScreenDebug(){};
        ScreenDebug(Screen *_screen) { screen = _screen; };
        ~ScreenDebug(){};

        void write(char s[]);
        void update();

        void show();
        void hide();

    private:
        vector<string> history;
        Screen *screen;
};

void ScreenDebug::write(char s[]) {
    screen->write(s, DEBUG_XPOS, yPos, DEBUG_FONT_SIZE);
    yPos += 15;
    if (yPos > 300) yPos = 0;
    // history.push_back(s);
    // update();
};

// redraw the screen debug panel
void ScreenDebug::update() {
    vector<string>::iterator it;
    int i = 0;
    int yPos = DEBUG_YPOS;
    for (it = history.begin(); it != history.end() && i <= MAX_HISTORY;
         it++, i++) {
        // string s = *it;
        char *b = &(*it)[0];
        screen->write(b, DEBUG_XPOS, yPos, DEBUG_FONT_SIZE);
        yPos += DEBUG_FONT_SIZE * 5;
    }
};
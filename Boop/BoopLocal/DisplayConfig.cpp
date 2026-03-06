//
// Created by whale on 2/27/26.
//

#include "DisplayConfig.h"

void Display::drawCat(int x, int y, int playerIndex) {
    DrawRectangle(x - catSize() / 2, y - catSize() / 2, catSize(), catSize(), playerColor(playerIndex));
}

void Display::drawKitten(int x, int y, int playerIndex) {
    DrawRectangle(x - kittenSize() / 2, y - kittenSize() / 2, kittenSize(), kittenSize(), playerColor(playerIndex));
}

void Display::drawText(const char* text, int x, int y, int fontSize, Color color) {
    const int textWidth = MeasureText(text, fontSize);
    DrawText(text, x - textWidth / 2, y, fontSize, color);
}
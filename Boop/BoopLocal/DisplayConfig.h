//
// Created by whale on 2/27/26.
//

#ifndef BOOPLOCAL_DISPLAYCONFIG_H
#define BOOPLOCAL_DISPLAYCONFIG_H

#pragma once
#include <algorithm>
#include <raylib.h>

namespace Display {
    inline int Width() { return GetScreenWidth(); }
    inline int Height() { return GetScreenHeight(); }
    inline int MinDim() { return std::min(Width(), Height()); }

    inline int cellSize() { return MinDim() / 8; }
    inline int catSize() { return cellSize() - 30; }
    inline int kittenSize() { return catSize() / 2; }

    inline int playerViewEdgeOffset() { return (Width() - 6 * cellSize()) / 4; }
    inline int playerViewCatGap() { return playerViewEdgeOffset() / 2; }
    inline int playerViewRectWidth() { return cellSize(); }
    inline int playerViewRectHeight() { return 1.2 * playerViewRectWidth(); }
    inline int playerViewFontSize() { return 0.2 * playerViewRectWidth(); }

    inline Color playerColor(int index) { return index == 0 ? ORANGE : GRAY; }

    void drawCat(int x, int y, int playerIndex);
    void drawKitten(int x, int y, int playerIndex);
    void drawText(const char* text, int x, int y, int fontSize, Color color);
}

#endif //BOOPLOCAL_DISPLAYCONFIG_H
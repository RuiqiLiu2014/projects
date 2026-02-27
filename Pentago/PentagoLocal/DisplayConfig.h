//
// Created by whale on 1/16/26.
//

#ifndef PENTAGOLOCAL_DISPLAYCONFIG_H
#define PENTAGOLOCAL_DISPLAYCONFIG_H

#pragma once
#include <algorithm>
#include <stdexcept>
#include <raylib.h>

#include "Cell.h"

namespace Display {
    inline int Width() { return GetScreenWidth(); }
    inline int Height() { return GetScreenHeight(); }
    inline int MinDim() { return std::min(Width(), Height()); }

    inline float MOUSE_RADIUS() { return 10.0f; }

    inline int TITLE_FONT_SIZE() { return MinDim() / 15.0f; }
    inline float BUTTON_SIZE() { return MinDim() / 5.0f; }
    inline float BUTTON_GAP() { return 20; }
    inline Color BUTTON_COLOR() { return DARKGRAY; }
    inline Color BUTTON_HOVER_COLOR() { return GRAY; }

    inline float CELL_RADIUS() { return 30.0f; }
    inline float CELL_GAP() { return 15.0f; }
    inline Color CELL_COLOR(CellStatus status, bool isHovered, CellStatus currentTurn) {
        switch (status)
        {
            case CellStatus::EMPTY:
                if (isHovered)
                {
                    switch (currentTurn)
                    {
                        case CellStatus::EMPTY: throw std::invalid_argument("CellStatus::EMPTY");
                        case CellStatus::P1: return Fade(SKYBLUE, 0.5f);
                        case CellStatus::P2: return Fade(RED, 0.3f);
                        case CellStatus::P3: return Fade(GREEN, 0.3f);
                        case CellStatus::P4: return Fade(ORANGE, 0.3f);
                    }
                }
                return Fade(GRAY, 0.3f);
            case CellStatus::P1: return Fade(SKYBLUE, 0.9f);
            case CellStatus::P2: return Fade(RED, 0.7f);
            case CellStatus::P3: return Fade(GREEN, 0.5f);
            case CellStatus::P4: return Fade(ORANGE, 0.7f);
        }
        throw std::runtime_error("Unknown CellStatus");
    }
    inline Color MOUSE_COLOR(CellStatus status) {
        switch (status) {
            case CellStatus::P1: return Fade(SKYBLUE, 1.0f);
            case CellStatus::P2: return Fade(RED, 1.0f);
            case CellStatus::P3: return Fade(GREEN, 1.0f);
            case CellStatus::P4: return Fade(ORANGE, 1.0f);
            default: throw std::runtime_error("Unknown CellStatus for mousecolor");
        }
    }

    inline float SUBGRID_SIZE() { return CELL_RADIUS() * 6 + CELL_GAP() * 4; }
    inline float SUBGRID_GAP() { return 4.0f; }
    inline Color SUBGRID_COLOR() { return LIGHTGRAY; }

    inline Vector2 TITLE() { return Vector2(Width() / 2.0f, Height() / 4.0f); }
    inline Vector2 BUTTONS() { return Vector2(Width() / 2.0f, Height() / 2.0f); }
    inline Vector2 BOARD() { return Vector2(Width() / 2.0f, Height() / 2.0f); }
    inline Vector2 SUBGRID(int size, int r, int c) {
        float boardSize = size * SUBGRID_SIZE() + (size - 1) * SUBGRID_GAP();
        return Vector2(BOARD().x - boardSize / 2 + r * (SUBGRID_SIZE() + SUBGRID_GAP()) + 0.5 * SUBGRID_SIZE(), BOARD().y - boardSize / 2 + c * (SUBGRID_SIZE() + SUBGRID_GAP()) + 0.5 * SUBGRID_SIZE());
    }

    inline void drawText(const char* text, const int x, const int y, const int fontSize, const Color color) {
        const int textWidth = MeasureText(text, fontSize);
        DrawText(text, x - textWidth / 2, y - fontSize / 2, fontSize, color);
    }
}

#endif //PENTAGOLOCAL_DISPLAYCONFIG_H
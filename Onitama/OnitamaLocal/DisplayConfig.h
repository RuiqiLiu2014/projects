//
// Created by whale on 12/14/25.
//

#ifndef ONITAMALOCAL_DISPLAYCONFIG_H
#define ONITAMALOCAL_DISPLAYCONFIG_H

#pragma once

#include <algorithm>
#include <cmath>
#include <raylib.h>

namespace Display
{
    inline int Width() { return GetScreenWidth(); }
    inline int Height() { return GetScreenHeight(); }
    inline int MinDim() { return std::min(Width(), Height()); }

    inline int CELL_SIZE() { return MinDim() / 12; }
    inline float CARD_CELL_SIZE() { return MinDim() / 30.0; }

    inline int CARD_FONT_SIZE() { return MinDim() / 40; }
    inline int WARNING_FONT_SIZE() { return MinDim() / 40; }
    inline int SCORE_FONT_SIZE() { return MinDim() / 15;}

    inline float CARD_WIDTH() { return 5.5f * CARD_CELL_SIZE(); }
    inline float CARD_HEIGHT() { return CARD_WIDTH() + CARD_FONT_SIZE() + CARD_CELL_SIZE() / 4; }

    inline float PLAYER_VIEW_Y_OFFSET() { return MinDim() / 3.0; }
    inline float MIDDLE_CARD_X_OFFSET() { return MinDim() / 3.0; }
    inline float PLAYER_CARD_CENTER_GAP() { return MinDim() / 4.0; }
    inline float SCORE_X_OFFSET() { return MinDim() / 3.0; }
    inline float SCORE_Y_OFFSET() { return MinDim() / 10.0; }

    inline float TURN_INDICATOR_OFFSET() { return CARD_WIDTH() * 0.6f; }
    inline float TURN_INDICATOR_THICKNESS() { return MinDim() / 30.0f; }
    inline float TURN_INDICATOR_ARROW_LENGTH() { return MinDim() / 12.5f; }

    inline Vector2 BOARD() { return Vector2{Width() / 2.0f, Height() / 2.0f}; }
    inline Vector2 PLAYER(const int index) { return Vector2{Width() / 2.0f, Height() / 2 + (index == 0 ? -PLAYER_VIEW_Y_OFFSET() : PLAYER_VIEW_Y_OFFSET())};}
    inline Vector2 MIDDLE_CARD() { return Vector2{Width() / 2 + MIDDLE_CARD_X_OFFSET(), Height() / 2.0f};}
    inline Vector2 TURN_INDICATOR() { return MIDDLE_CARD(); }
    inline Vector2 SCORE(const int index) { return Vector2{Width() / 2 - SCORE_X_OFFSET(), Height() / 2 + (index == 0 ? -SCORE_Y_OFFSET() : SCORE_Y_OFFSET())}; }

    inline void drawText(const char* text, const int x, const int y, const int fontSize, const Color color)
    {
        const int textWidth = MeasureText(text, fontSize);
        DrawText(text, x - textWidth / 2, y, fontSize, color);
    }

    inline void drawArrow(Vector2 start, Vector2 end, float thickness, Color color) {
        Vector2 direction = { end.x - start.x, end.y - start.y };
        float length = sqrtf(direction.x * direction.x + direction.y * direction.y);

        if (length <= 0) return;

        // 1. Calculate Sizes
        // headSize is the "length" of the triangle head.
        // It should be at least 3x thickness to look good.
        float headSize = thickness * 1.5f;
        Vector2 unitDir = { direction.x / length, direction.y / length };
        Vector2 perpDir = { -unitDir.y, unitDir.x };

        // 2. Shorten the shaft so it doesn't bleed through the triangle tip
        Vector2 shortenedEnd = {
            end.x - unitDir.x * headSize,
            end.y - unitDir.y * headSize
        };

        // 3. Define the triangle points (Base is at shortenedEnd)
        Vector2 p1 = end; // The sharp tip
        Vector2 p2 = { shortenedEnd.x + perpDir.x * (headSize / 1.5f),
                       shortenedEnd.y + perpDir.y * (headSize / 1.5f) };
        Vector2 p3 = { shortenedEnd.x - perpDir.x * (headSize / 1.5f),
                       shortenedEnd.y - perpDir.y * (headSize / 1.5f) };

        // 4. Draw
        DrawLineEx(start, shortenedEnd, thickness, color); // Line ends at triangle base
        DrawTriangle(p1, p3, p2, color); // CCW winding order
    }
}

#endif //ONITAMALOCAL_DISPLAYCONFIG_H
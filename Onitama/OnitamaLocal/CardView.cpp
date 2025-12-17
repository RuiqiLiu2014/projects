//
// Created by whale on 12/14/25.
//

#include "CardView.h"

#include <raylib.h>

#include "DisplayConfig.h"

void CardView::draw() const
{
    constexpr float size = Display::CARD_CELL_SIZE;

    for (int r = -2; r <= 2; r++)
    {
        for (int c = -2; c <= 2; c++)
        {
            const Rectangle rect = { x - size / 2 + c * size, y - size / 2 + r * size, size, size };
            if (r == 0 && c == 0)
            {
                DrawRectangleRec(rect, DARKGRAY);
            }
            else if (card.canMoveTo(r, c))
            {
                DrawRectangleRec(rect, GRAY);
            }
            else
            {
                DrawRectangleLinesEx(rect, 1, GRAY);
            }
        }
    }
}

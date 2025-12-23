//
// Created by whale on 12/14/25.
//

#include "CardView.h"

#include <raylib.h>

#include "DisplayConfig.h"

void CardView::draw() const
{
    const Rectangle border = {x - Display::CARD_WIDTH / 2, y - Display::CARD_HEIGHT / 2, Display::CARD_WIDTH, Display::CARD_HEIGHT};
    DrawRectangleRoundedLinesEx(border, 0.2, 10, 1.0, BLACK);

    constexpr float size = Display::CARD_CELL_SIZE;

    const char* text = card.name.c_str();
    const int textWidth = MeasureText(text, Display::FONT_SIZE);
    DrawText(text, x - textWidth / 2, y - Display::CARD_HEIGHT / 2 + 5, Display::FONT_SIZE, BLACK);

    const float center_y = y + Display::CARD_HEIGHT / 2 - size * 3;

    for (int r = -2; r <= 2; r++)
    {
        for (int c = -2; c <= 2; c++)
        {
            const Rectangle rect = { x - size / 2 + c * size, center_y - size / 2 + r * size, size, size };
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

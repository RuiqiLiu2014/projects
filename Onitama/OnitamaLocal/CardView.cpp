//
// Created by whale on 12/14/25.
//

#include "CardView.h"

#include <raylib.h>
#include "DisplayConfig.h"

void CardView::draw(const Vector2 mousePos, const int x, const int y) const
{
    const Rectangle border = {x - Display::CARD_WIDTH() / 2, y - Display::CARD_HEIGHT() / 2, Display::CARD_WIDTH(), Display::CARD_HEIGHT()};
    if (selected)
    {
        DrawRectangleRoundedLinesEx(border, 0.2, 10, 1.0, GREEN);
    } else
    {
        DrawRectangleRoundedLinesEx(border, 0.2, 10, 1.0, isHovered(mousePos, x, y) ? ORANGE : BLACK);
    }

    Display::drawText(card.name.c_str(), x, y - Display::CARD_HEIGHT() / 2 + 5, Display::CARD_FONT_SIZE(), BLACK);

    const float size = Display::CARD_CELL_SIZE();
    const float center_y = y + Display::CARD_HEIGHT() / 2 - size * 3;

    for (int r = -2; r <= 2; r++)
    {
        for (int c = -2; c <= 2; c++)
        {
            const Rectangle rect = { x - size / 2 + c * size, center_y - size / 2 + r * size, size, size };
            if (r == 0 && c == 0)
            {
                DrawRectangleRec(rect, DARKGRAY);
            }
            else if (card.canMoveTo(r, c, false))
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

bool CardView::isHovered(const Vector2 mousePos, const int x, const int y) const
{
    return hoverable && std::abs(mousePos.x - x) <= Display::CARD_WIDTH() / 2 && std::abs(mousePos.y - y) <= Display::CARD_HEIGHT() / 2;
}

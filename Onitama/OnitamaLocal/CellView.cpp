//
// Created by whale on 12/14/25.
//

#include "Cell.h"
#include "CellView.h"

#include "DisplayConfig.h"
#include "raylib.h"
#include <cmath>

void CellView::draw() const
{
    constexpr int size = Display::CELL_SIZE;
    if (isHovered())
    {
        DrawRectangleLines(x - size / 2, y - size / 2, size, size, GREEN);
    } else
    {
        DrawRectangleLines(x - size / 2, y - size / 2, size, size, BLACK);
    }
    switch (cell.getStatus())
    {
        case CellStatus::EMPTY: break;
        case CellStatus::BLUE_KING: DrawRectangle(x - size / 3, y - size / 3, size * 2 / 3, size * 2 / 3, BLUE); break;
        case CellStatus::BLUE_DUDE: DrawCircle(x, y, size / 4.0, BLUE); break;
        case CellStatus::RED_KING: DrawRectangle(x - size / 3, y - size / 3, size * 2 / 3, size * 2 / 3, RED); break;
        case CellStatus::RED_DUDE: DrawCircle(x, y, size / 4.0, RED); break;
    }
}

bool CellView::isHovered() const
{
    return std::abs(GetMouseX() - x) <= Display::CELL_SIZE / 2 && std::abs(GetMouseY() - y) <= Display::CELL_SIZE / 2;
}

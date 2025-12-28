//
// Created by whale on 12/14/25.
//

#include "BoardView.h"

#include <optional>
#include <raylib.h>

#include "DisplayConfig.h"

void BoardView::draw(std::optional<Point> selectedCell) const
{
    int selectedR = -1;
    int selectedC = -1;
    if (selectedCell.has_value())
    {
        selectedR = selectedCell.value().r;
        selectedC = selectedCell.value().c;
    }
    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            CellView(board.getCells()[r][c], x + (c - 2) * Display::CELL_SIZE, y + (r - 2) * Display::CELL_SIZE).draw(r == selectedR && c == selectedC);
        }
    }
}

std::optional<Point> BoardView::getHoveredCell() const
{
    const int relativeX = GetMouseX() - (x - Display::CELL_SIZE * 2.5);
    const int relativeY = GetMouseY() - (y - Display::CELL_SIZE * 2.5);

    if (relativeX >= 0 && relativeX <= Display::CELL_SIZE * 5 && relativeY >= 0 && relativeY <= Display::CELL_SIZE * 5)
    {
        return Point{relativeY / Display::CELL_SIZE, relativeX / Display::CELL_SIZE};
    }
    return std::nullopt;
}

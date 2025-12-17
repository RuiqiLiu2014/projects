//
// Created by whale on 12/14/25.
//

#include "BoardView.h"

#include "DisplayConfig.h"

void BoardView::draw() const
{
    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            CellView(board.getCells()[r][c], x + (c - 2) * Display::CELL_SIZE, y + (r - 2) * Display::CELL_SIZE).draw();
        }
    }
}

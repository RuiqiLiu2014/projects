//
// Created by whale on 1/16/26.
//

#include "SubGridView.h"

#include <raylib.h>

#include "CellView.h"
#include "DisplayConfig.h"

SubGridView::SubGridView(const SubGrid& grid) : grid(grid) {
}

void SubGridView::draw(int x, int y, bool gridHover, Point hoveredCell, bool cellHover, CellStatus currentTurn) const {
    Rectangle rect = { x - Display::SUBGRID_SIZE() / 2, y - Display::SUBGRID_SIZE() / 2, Display::SUBGRID_SIZE(), Display::SUBGRID_SIZE() };
    DrawRectangleRounded(rect, 0.2f, 60, Display::SUBGRID_COLOR());

    if (gridHover) {
        DrawRectangleRoundedLines(rect, 0.2f, 60, GREEN);
    }

    const auto& cells = grid.getCells();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            CellView(cells[i][j]).draw(x + (i - 1) * (Display::CELL_RADIUS() * 2 + Display::CELL_GAP()),
                y + (j - 1) * (Display::CELL_RADIUS() * 2 + Display::CELL_GAP()),
                gridHover && cellHover && i == hoveredCell.r && j == hoveredCell.c, currentTurn);
        }
    }
}
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
    if (gridHover && !cellHover) {
        DrawRectangleRounded({ rect.x + 3, rect.y + 3, rect.width, rect.height }, 0.2f, 20, Fade(BLACK, 0.4));

        rect.x -= 2;
        rect.y -= 2;
    }

    DrawRectangleRounded(rect, 0.2f, 60, Display::SUBGRID_COLOR());

    const auto& cells = grid.getCells();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            CellView(cells[i][j]).draw(rect.x + Display::SUBGRID_SIZE() / 2 + (i - 1) * (Display::CELL_RADIUS() * 2 + Display::CELL_GAP()),
                rect.y + Display::SUBGRID_SIZE() / 2 + (j - 1) * (Display::CELL_RADIUS() * 2 + Display::CELL_GAP()),
                gridHover && cellHover && i == hoveredCell.r && j == hoveredCell.c, currentTurn);
        }
    }
}
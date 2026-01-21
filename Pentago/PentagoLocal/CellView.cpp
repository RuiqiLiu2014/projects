//
// Created by whale on 1/16/26.
//

#include "CellView.h"

#include <raylib.h>

#include "DisplayConfig.h"

CellView::CellView(const Cell& cell) : cell(cell) {
}

void CellView::draw(int x, int y, bool isHovered, CellStatus currentTurn) const {
    DrawCircle(x, y, Display::CELL_RADIUS(), Display::CELL_COLOR(cell.getStatus(), isHovered, currentTurn));
}
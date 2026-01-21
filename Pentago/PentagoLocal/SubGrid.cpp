//
// Created by whale on 1/15/26.
//

#include "SubGrid.h"

#include "Point.h"

SubGrid::SubGrid() : cells{} {
}

auto SubGrid::getCells() const -> const Cell(&)[3][3] {
    return cells;
}

void SubGrid::reset() {
    for (auto& row : cells) {
        for (auto& cell : row) {
            cell.setStatus(CellStatus::EMPTY);
        }
    }
}

bool SubGrid::placePiece(CellStatus status, Point p) {
    Cell& cell = cells[p.r][p.c];
    if (cell.getStatus() == CellStatus::EMPTY) {
        cell.setStatus(status);
        return true;
    }
    return false;
}

void SubGrid::rotate(bool clockwise) {
    CellStatus temp;
    if (!clockwise) {
        temp = cells[0][0].getStatus();
        cells[0][0].setStatus(cells[2][0].getStatus());
        cells[2][0].setStatus(cells[2][2].getStatus());
        cells[2][2].setStatus(cells[0][2].getStatus());
        cells[0][2].setStatus(temp);

        temp = cells[0][1].getStatus();
        cells[0][1].setStatus(cells[1][0].getStatus());
        cells[1][0].setStatus(cells[2][1].getStatus());
        cells[2][1].setStatus(cells[1][2].getStatus());
        cells[1][2].setStatus(temp);
    } else {
        temp = cells[0][0].getStatus();
        cells[0][0].setStatus(cells[0][2].getStatus());
        cells[0][2].setStatus(cells[2][2].getStatus());
        cells[2][2].setStatus(cells[2][0].getStatus());
        cells[2][0].setStatus(temp);

        temp = cells[0][1].getStatus();
        cells[0][1].setStatus(cells[1][2].getStatus());
        cells[1][2].setStatus(cells[2][1].getStatus());
        cells[2][1].setStatus(cells[1][0].getStatus());
        cells[1][0].setStatus(temp);
    }
}
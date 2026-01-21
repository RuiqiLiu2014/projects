//
// Created by whale on 1/15/26.
//

#include "Board.h"

#include "Point.h"

Board::Board(int size) {
    this->size = size;
    subgrids.resize(size);
    for (int i = 0; i < size; i++) {
        subgrids[i].resize(size);
    }
}

const std::vector<std::vector<SubGrid>>& Board::getSubgrids() const {
    return subgrids;
}

void Board::reset() {
    for (auto& row : subgrids) {
        for (auto& grid : row) {
            grid.reset();
        }
    }
}

bool Board::placePiece(CellStatus status, Point subgrid, Point cell) {
    return subgrids[subgrid.r][subgrid.c].placePiece(status, cell);
}

int Board::getSize() const {
    return size;
}

void Board::rotate(Point subgrid, bool clockwise) {
    subgrids[subgrid.r][subgrid.c].rotate(clockwise);
}
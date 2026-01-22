//
// Created by whale on 1/15/26.
//

#include "Board.h"

#include <stdexcept>

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

std::vector<std::vector<CellStatus>> Board::toArray() const {
    std::vector<std::vector<CellStatus>> array;
    array.resize(size * 3);
    for (int r = 0; r < size * 3; r++) {
        array[r].resize(size * 3);
        for (int c = 0; c < size * 3; c++) {
            array[r][c] = subgrids[r / 3][c / 3].getCells()[r % 3][c % 3].getStatus();
        }
    }

    return array;
}

CellStatus Board::winner() const {
    std::vector points = {0, 0, 0, 0};
    const std::vector<std::vector<CellStatus>>& board = toArray();

    for (int r = 0; r < board.size() - 4; r++) {
        for (int c = 0; c < board[r].size(); c++) {
            if (board[r][c] == board[r + 1][c] &&
                board[r][c] == board[r + 2][c] &&
                board[r][c] == board[r + 3][c] &&
                board[r][c] == board[r + 4][c]) {
                switch (board[r][c]) {
                    case CellStatus::P1: points[0]++; break;
                    case CellStatus::P2: points[1]++; break;
                    case CellStatus::P3: points[2]++; break;
                    case CellStatus::P4: points[3]++; break;
                    default: break;
                }
            }
        }
    }

    for (int r = 0; r < board.size(); r++) {
        for (int c = 0; c < board[r].size() - 4; c++) {
            if (board[r][c] == board[r][c + 1] &&
                board[r][c] == board[r][c + 2] &&
                board[r][c] == board[r][c + 3] &&
                board[r][c] == board[r][c + 4]) {
                switch (board[r][c]) {
                    case CellStatus::P1: points[0]++; break;
                    case CellStatus::P2: points[1]++; break;
                    case CellStatus::P3: points[2]++; break;
                    case CellStatus::P4: points[3]++; break;
                    default: break;
                }
            }
        }
    }

    for (int r = 0; r < board.size() - 4; r++) {
        for (int c = 0; c < board[r].size() - 4; c++) {
            if (board[r][c] == board[r + 1][c + 1] &&
                board[r][c] == board[r + 2][c + 2] &&
                board[r][c] == board[r + 3][c + 3] &&
                board[r][c] == board[r + 4][c + 4]) {
                switch (board[r][c]) {
                    case CellStatus::P1: points[0]++; break;
                    case CellStatus::P2: points[1]++; break;
                    case CellStatus::P3: points[2]++; break;
                    case CellStatus::P4: points[3]++; break;
                    default: break;
                }
            }
        }
    }

    for (int r = 4; r < board.size(); r++) {
        for (int c = 0; c < board[r].size() - 4; c++) {
            if (board[r][c] == board[r - 1][c + 1] &&
                board[r][c] == board[r - 2][c + 2] &&
                board[r][c] == board[r - 3][c + 3] &&
                board[r][c] == board[r - 4][c + 4]) {
                switch (board[r][c]) {
                    case CellStatus::P1: points[0]++; break;
                    case CellStatus::P2: points[1]++; break;
                    case CellStatus::P3: points[2]++; break;
                    case CellStatus::P4: points[3]++; break;
                    default: break;
                }
            }
        }
    }

    int max = 0;
    CellStatus winner = CellStatus::EMPTY;
    for (int i = 0; i < points.size(); i++) {
        if (points[i] > max) {
            max = points[i];
            switch (i) {
                case 0: winner = CellStatus::P1; break;
                case 1: winner = CellStatus::P2; break;
                case 2: winner = CellStatus::P3; break;
                case 3: winner = CellStatus::P4; break;
                default: throw std::out_of_range("win check issue");
            }
        }
    }

    return winner;
}
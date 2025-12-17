//
// Created by whale on 12/12/25.
//

#include "Board.h"

#include <iostream>

Board::Board()
{
    this->cells = std::vector(5, std::vector<Cell>(5));

    this->cells[0][0].setStatus(CellStatus::BLUE_DUDE);
    this->cells[0][1].setStatus(CellStatus::BLUE_DUDE);
    this->cells[0][2].setStatus(CellStatus::BLUE_KING);
    this->cells[0][3].setStatus(CellStatus::BLUE_DUDE);
    this->cells[0][4].setStatus(CellStatus::BLUE_DUDE);

    this->cells[4][0].setStatus(CellStatus::RED_DUDE);
    this->cells[4][1].setStatus(CellStatus::RED_DUDE);
    this->cells[4][2].setStatus(CellStatus::RED_KING);
    this->cells[4][3].setStatus(CellStatus::RED_DUDE);
    this->cells[4][4].setStatus(CellStatus::RED_DUDE);
}

const std::vector<std::vector<Cell>>& Board::getCells() const
{
    return cells;
}

bool Board::movePiece(const int startR, const int startC, const int endR, const int endC)
{
    Cell& start = cells[startR][startC];
    Cell& end = cells[endR][endC];
    if (start.isEmpty() || (start.isBlue() && end.isBlue()) || (start.isRed() && end.isRed()))
    {
        return false;
    }

    end.setStatus(start.getStatus());
    start.setStatus(CellStatus::EMPTY);
    return true;
}

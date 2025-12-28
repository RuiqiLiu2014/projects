//
// Created by whale on 12/12/25.
//

#include "Board.h"

#include <iostream>

#include "MoveCard.h"

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

bool Board::isPlayersPiece(const int turn, const Point p) const
{
    if (turn == 0)
    {
        return cells[p.r][p.c].isBlue();
    }
    return cells[p.r][p.c].isRed();
}

bool Board::movePiece(const Point start, const Point end, const MoveCard& card, bool upsideDown)
{
    Cell& startCell = cells[start.r][start.c];
    Cell& endCell = cells[end.r][end.c];
    if (startCell.isEmpty() || (startCell.isBlue() && endCell.isBlue()) || (startCell.isRed() && endCell.isRed()))
    {
        return false;
    }

    if (card.canMoveTo(end.r - start.r, end.c - start.c, upsideDown))
    {
        endCell.setStatus(startCell.getStatus());
        startCell.setStatus(CellStatus::EMPTY);
        return true;
    }

    return false;
}
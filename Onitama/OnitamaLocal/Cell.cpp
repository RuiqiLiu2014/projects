//
// Created by whale on 12/12/25.
//

#include "Cell.h"

CellStatus Cell::getStatus() const
{
    return status;
}


void Cell::setStatus(const CellStatus newStatus)
{
    status = newStatus;
}

bool Cell::isEmpty() const
{
    return status == CellStatus::EMPTY;
}

bool Cell::isBlue() const
{
    return status == CellStatus::BLUE_DUDE || status == CellStatus::BLUE_KING;
}

bool Cell::isRed() const
{
    return status == CellStatus::RED_DUDE || status == CellStatus::RED_KING;
}
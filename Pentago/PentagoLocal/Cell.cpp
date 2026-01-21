//
// Created by whale on 1/15/26.
//

#include "Cell.h"

Cell::Cell() {
    status = CellStatus::EMPTY;
}

CellStatus Cell::getStatus() const {
    return status;
}

void Cell::setStatus(CellStatus newStatus) {
    status = newStatus;
}

bool Cell::isEmpty() const {
    return status == CellStatus::EMPTY;
}
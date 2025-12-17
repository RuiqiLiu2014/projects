//
// Created by whale on 12/12/25.
//

#ifndef ONITAMALOCAL_CELL_H
#define ONITAMALOCAL_CELL_H

enum class CellStatus
{
    EMPTY, BLUE_DUDE, RED_DUDE, BLUE_KING, RED_KING
};

class Cell
{
    CellStatus status = CellStatus::EMPTY;

public:
    Cell() = default;
    [[nodiscard]] CellStatus getStatus() const;
    void setStatus(CellStatus newStatus);
    [[nodiscard]] bool isEmpty() const;
    [[nodiscard]] bool isBlue() const;
    [[nodiscard]] bool isRed() const;
};


#endif //ONITAMALOCAL_CELL_H
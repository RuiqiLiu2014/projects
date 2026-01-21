//
// Created by whale on 1/15/26.
//

#ifndef PENTAGOLOCAL_CELL_H
#define PENTAGOLOCAL_CELL_H

enum class CellStatus {
    EMPTY, P1, P2, P3, P4
};

class Cell {
    CellStatus status;

public:
    Cell();
    [[nodiscard]] CellStatus getStatus() const;
    void setStatus(CellStatus newStatus);
    [[nodiscard]] bool isEmpty() const;
};


#endif //PENTAGOLOCAL_CELL_H
//
// Created by whale on 12/12/25.
//

#ifndef ONITAMALOCAL_BOARD_H
#define ONITAMALOCAL_BOARD_H
#include <vector>

#include "Cell.h"

class Board
{
    std::vector<std::vector<Cell>> cells;

public:
    Board();
    [[nodiscard]] const std::vector<std::vector<Cell>>& getCells() const;
    bool movePiece(int startR, int startC, int endR, int endC);
};


#endif //ONITAMALOCAL_BOARD_H
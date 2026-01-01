//
// Created by whale on 12/12/25.
//

#ifndef ONITAMALOCAL_BOARD_H
#define ONITAMALOCAL_BOARD_H
#include <vector>

#include "Cell.h"
#include "MoveCard.h"
#include "Point.h"

class Board
{
    std::vector<std::vector<Cell>> cells;

public:
    Board();
    [[nodiscard]] const std::vector<std::vector<Cell>>& getCells() const;
    [[nodiscard]] bool isPlayersPiece(int turn, Point p) const;
    bool movePiece(Point start, Point end, const MoveCard& card, bool upsideDown);
    void reset();
};


#endif //ONITAMALOCAL_BOARD_H
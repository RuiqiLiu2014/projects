//
// Created by whale on 12/14/25.
//

#ifndef ONITAMALOCAL_BOARDVIEW_H
#define ONITAMALOCAL_BOARDVIEW_H
#include "Board.h"
#include "CellView.h"


class BoardView
{
    const Board& board;
    int x, y;

public:
    explicit BoardView(const Board& board, const int x, const int y) : board(board), x(x), y(y) {}
    void draw() const;
};


#endif //ONITAMALOCAL_BOARDVIEW_H
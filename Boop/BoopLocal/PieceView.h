//
// Created by whale on 2/27/26.
//

#ifndef BOOPLOCAL_PIECEVIEW_H
#define BOOPLOCAL_PIECEVIEW_H
#include "Board.h"


class PieceView {
    const Board* board;
    Point p;

public:
    PieceView() : board(nullptr), p(0, 0) {}
    PieceView(const Board* board, Point p);
    void draw(int x, int y) const;
};


#endif //BOOPLOCAL_PIECEVIEW_H
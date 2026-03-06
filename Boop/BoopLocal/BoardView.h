//
// Created by whale on 2/27/26.
//

#ifndef BOOPLOCAL_BOARDVIEW_H
#define BOOPLOCAL_BOARDVIEW_H
#include <vector>

#include "PieceView.h"


class BoardView {
    std::array<std::array<PieceView, 6>, 6> pieceViews;

public:
    explicit BoardView(const Board& board);
    void draw(int x, int y) const;
};


#endif //BOOPLOCAL_BOARDVIEW_H
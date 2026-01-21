//
// Created by whale on 1/16/26.
//

#ifndef PENTAGOLOCAL_CELLVIEW_H
#define PENTAGOLOCAL_CELLVIEW_H
#include "Cell.h"


class CellView {
    const Cell& cell;

public:
    explicit CellView(const Cell& cell);
    void draw(int x, int y, bool isHovered, CellStatus currentTurn) const;
};


#endif //PENTAGOLOCAL_CELLVIEW_H
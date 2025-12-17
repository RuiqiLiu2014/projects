//
// Created by whale on 12/14/25.
//

#ifndef ONITAMALOCAL_CELLVIEW_H
#define ONITAMALOCAL_CELLVIEW_H
#include "Cell.h"

class CellView
{
    const Cell& cell;
    int x, y;

public:
    CellView(const Cell& cell, int x, int y) : cell(cell), x(x), y(y) {}
    void draw() const;
};


#endif //ONITAMALOCAL_CELLVIEW_H
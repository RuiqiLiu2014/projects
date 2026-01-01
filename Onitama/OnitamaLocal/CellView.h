//
// Created by whale on 12/14/25.
//

#ifndef ONITAMALOCAL_CELLVIEW_H
#define ONITAMALOCAL_CELLVIEW_H
#include "Cell.h"

class CellView
{
    const Cell& cell;

public:
    explicit CellView(const Cell& cell) : cell(cell) {}
    void draw(int x, int y, bool selected) const;
    [[nodiscard]] static bool isHovered(int x, int y);
};


#endif //ONITAMALOCAL_CELLVIEW_H
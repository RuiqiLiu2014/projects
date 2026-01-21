//
// Created by whale on 1/15/26.
//

#ifndef PENTAGOLOCAL_SUBGRID_H
#define PENTAGOLOCAL_SUBGRID_H
#include "Cell.h"
#include "Point.h"


class SubGrid {
    Cell cells[3][3];

public:
    SubGrid();
    [[nodiscard]] auto getCells() const -> const Cell(&)[3][3];
    void reset();
    bool placePiece(CellStatus status, Point p);
    void rotate(bool clockwise);
};


#endif //PENTAGOLOCAL_SUBGRID_H
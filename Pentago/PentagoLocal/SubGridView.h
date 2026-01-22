//
// Created by whale on 1/16/26.
//

#ifndef PENTAGOLOCAL_SUBGRIDVIEW_H
#define PENTAGOLOCAL_SUBGRIDVIEW_H
#include "SubGrid.h"


class SubGridView {
    const SubGrid& grid;

public:
    explicit SubGridView(const SubGrid& grid);
    void draw(int x, int y, bool gridHover, Point hoveredCell, bool cellHover, CellStatus currentTurn) const;
};


#endif //PENTAGOLOCAL_SUBGRIDVIEW_H
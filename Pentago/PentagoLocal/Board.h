//
// Created by whale on 1/15/26.
//

#ifndef PENTAGOLOCAL_BOARD_H
#define PENTAGOLOCAL_BOARD_H
#include <vector>

#include "Point.h"
#include "SubGrid.h"


class Board {
    int size;
    std::vector<std::vector<SubGrid>> subgrids;

    [[nodiscard]] std::vector<std::vector<CellStatus>> toArray() const;

public:
    explicit Board(int size);
    [[nodiscard]] const std::vector<std::vector<SubGrid>>& getSubgrids() const;
    [[nodiscard]] int getSize() const;
    void reset();
    bool placePiece(CellStatus status, Point subgrid, Point cell);
    void rotate(Point subgrid, bool clockwise);
    [[nodiscard]] CellStatus winner() const;
};


#endif //PENTAGOLOCAL_BOARD_H
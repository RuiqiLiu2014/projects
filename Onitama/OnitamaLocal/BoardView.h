//
// Created by whale on 12/14/25.
//

#ifndef ONITAMALOCAL_BOARDVIEW_H
#define ONITAMALOCAL_BOARDVIEW_H
#include <optional>

#include "Board.h"
#include "CellView.h"
#include "Point.h"


class BoardView
{
    const Board& board;
    int x, y;

public:
    explicit BoardView(const Board& board, const int x, const int y) : board(board), x(x), y(y) {}
    void draw(std::optional<Point> selectedCell) const;
    [[nodiscard]] std::optional<Point> getHoveredCell() const;
};

#endif //ONITAMALOCAL_BOARDVIEW_H
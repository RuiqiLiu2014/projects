//
// Created by whale on 12/14/25.
//

#ifndef ONITAMALOCAL_BOARDVIEW_H
#define ONITAMALOCAL_BOARDVIEW_H
#include <optional>

#include "Board.h"
#include "Point.h"

class BoardView
{
    const Board& board;

public:
    explicit BoardView(const Board& board) : board(board) {}
    void draw(std::optional<Point> selectedCell, int x, int y) const;
    [[nodiscard]] std::optional<Point> getHoveredCell(int x, int y) const;
};

#endif //ONITAMALOCAL_BOARDVIEW_H
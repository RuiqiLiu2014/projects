//
// Created by whale on 2/27/26.
//

#include "BoardView.h"

#include "DisplayConfig.h"

BoardView::BoardView(const Board& board) {
    for (int r = 0; r < 6; r++) {
        for (int c = 0; c < 6; c++) {
            pieceViews[r][c] = PieceView(&board, Point(r, c));
        }
    }
}

void BoardView::draw(int x, int y) const {
    int startX = x - 3 * Display::cellSize();
    int startY = y - 3 * Display::cellSize();

    for (int r = 0; r < 6; r++) {
        for (int c = 0; c < 6; c++) {
            DrawRectangleLines(startX + r * Display::cellSize(), startY + c * Display::cellSize(), Display::cellSize(), Display::cellSize(), BLACK);
            pieceViews[r][c].draw(startX + (r + 0.5) * Display::cellSize(), startY + (c + 0.5) * Display::cellSize());
        }
    }
}
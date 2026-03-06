//
// Created by whale on 2/27/26.
//

#include "PieceView.h"

#include "DisplayConfig.h"
#include "raylib.h"

PieceView::PieceView(const Board* board, Point p) : board(board), p(p) {
}

void PieceView::draw(int x, int y) const {
    switch (board->pieceAt(p)) {
    case Piece::P0_CAT: Display::drawCat(x, y, 0); break;
    case Piece::P1_CAT: Display::drawCat(x, y, 1); break;
    case Piece::P0_KITTEN: Display::drawKitten(x, y, 0); break;
    case Piece::P1_KITTEN: Display::drawKitten(x, y, 1); break;
    default: break;
    }
}
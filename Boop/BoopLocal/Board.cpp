//
// Created by whale on 2/27/26.
//

#include "Board.h"

#include <stdexcept>

bool Board::placePiece(Point p, Piece piece) {
    if (!p.inBounds() || isEmpty(p)) {
        return false;
    }

    board[p.r][p.c] = piece;
    boop(p, piece == Piece::P0_CAT || piece == Piece::P1_CAT);
    return true;
}

Piece Board::pieceAt(Point p) const {
    if (!p.inBounds()) {
        throw std::invalid_argument("point out of bounds in Board::pieceAt");
    }

    return board[p.r][p.c];
}

bool Board::isEmpty(Point p) const {
    if (!p.inBounds()) {
        throw std::invalid_argument("point out of bounds in Board::isEmpty");
    }

    return board[p.r][p.c] == Piece::EMPTY;
}

void Board::boop(Point p, bool isCat) {
    if (!p.inBounds()) {
        throw std::invalid_argument("point out of bounds in Board::boop");
    }

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            auto adjacentPoint = Point(p.r + i, p.c + j);
            auto furtherPoint = Point(p.r + 2 * i, p.c + 2 * j);

            if (adjacentPoint.inBounds() && !furtherPoint.inBounds()) {
                removePiece(adjacentPoint);
            } else if (adjacentPoint.inBounds() && furtherPoint.inBounds()) {
                if (!isEmpty(adjacentPoint) && isEmpty(furtherPoint)) {
                    Piece piece = removePiece(adjacentPoint);
                    placePiece(furtherPoint, piece);
                }
            }
        }
    }
}

Piece Board::removePiece(Point p) {
    Piece piece = board[p.r][p.c];
    board[p.r][p.c] = Piece::EMPTY;
    return piece;
}
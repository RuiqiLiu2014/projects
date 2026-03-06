//
// Created by whale on 2/27/26.
//

#ifndef BOOPLOCAL_BOARD_H
#define BOOPLOCAL_BOARD_H
#include <array>

#include "Piece.h"
#include "Point.h"

class Board {
    std::array<std::array<Piece, 6>, 6> board{Piece::EMPTY};

    void boop(Point p, bool isCat);
    Piece removePiece(Point p);

public:
    Board() = default;
    bool placePiece(Point p, Piece piece);
    [[nodiscard]] Piece pieceAt(Point p) const;
    [[nodiscard]] bool isEmpty(Point p) const;
};


#endif //BOOPLOCAL_BOARD_H
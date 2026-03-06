//
// Created by whale on 2/27/26.
//

#ifndef BOOPLOCAL_BOARD_H
#define BOOPLOCAL_BOARD_H
#include <array>
#include <optional>
#include <vector>

#include "Piece.h"
#include "Point.h"

class Board {
    std::array<std::array<Piece, 6>, 6> board{Piece::EMPTY};

    std::vector<Piece> boop(Point p);
    [[nodiscard]] std::vector<std::array<Point, 3>> findGroups(int playerIndex) const;
    Piece removePiece(Point p);

public:
    Board() = default;
    std::optional<std::vector<Piece>> placePiece(Point p, Piece piece);
    std::vector<Piece> graduate(int playerIndex);
    [[nodiscard]] Piece pieceAt(Point p) const;
    [[nodiscard]] bool isEmpty(Point p) const;
    [[nodiscard]] int winner() const;
    [[nodiscard]] bool isCat(Point p) const;
    [[nodiscard]] bool isKitten(Point p) const;
};


#endif //BOOPLOCAL_BOARD_H
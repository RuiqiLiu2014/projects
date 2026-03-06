//
// Created by whale on 2/27/26.
//

#ifndef BOOPLOCAL_PIECE_H
#define BOOPLOCAL_PIECE_H

enum class Piece {
    EMPTY,
    P0_KITTEN,
    P0_CAT,
    P1_KITTEN,
    P1_CAT
};

inline int getOwner(Piece p) {
    if (p == Piece::P0_CAT || p == Piece::P0_KITTEN) return 0;
    if (p == Piece::P1_CAT || p == Piece::P1_KITTEN) return 1;
    return -1;
}

#endif //BOOPLOCAL_PIECE_H
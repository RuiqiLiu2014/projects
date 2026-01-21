//
// Created by whale on 1/15/26.
//

#ifndef PENTAGOLOCAL_TURN_H
#define PENTAGOLOCAL_TURN_H
#include "Cell.h"

#endif //PENTAGOLOCAL_TURN_H

enum class TurnPhase {
    Placing, Rotating
};

class Turn {
    int numPlayers;
    int index;
    TurnPhase phase;

public:
    explicit Turn(int numPlayers);
    void next();
    [[nodiscard]] int turnIndex() const;
    [[nodiscard]] TurnPhase turnPhase() const;
    [[nodiscard]] CellStatus cellStatus() const;
};
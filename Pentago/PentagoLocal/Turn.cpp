//
// Created by whale on 1/16/26.
//

#include "Turn.h"

#include <stdexcept>

Turn::Turn(int numPlayers) : numPlayers(numPlayers), index(0), phase(TurnPhase::Placing) {
}

void Turn::next() {
    if (phase == TurnPhase::Placing) {
        phase = TurnPhase::Rotating;
    } else {
        phase = TurnPhase::Placing;
        index = (index + 1) % numPlayers;
    }
}

int Turn::turnIndex() const {
    return index;
}

TurnPhase Turn::turnPhase() const {
    return phase;
}

CellStatus Turn::cellStatus() const {
    switch (index) {
        case 0: return CellStatus::P1;
        case 1: return CellStatus::P2;
        case 2: return CellStatus::P3;
        case 3: return CellStatus::P4;
        default: throw std::out_of_range("Turn::cellStatus");
    }
}
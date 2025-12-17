//
// Created by whale on 12/12/25.
//

#ifndef ONITAMALOCAL_GAMECONTROLLER_H
#define ONITAMALOCAL_GAMECONTROLLER_H
#include <array>

#include "Board.h"
#include "MiddleCard.h"
#include "MoveCard.h"
#include "Player.h"


class GameController
{
    Board board;
    std::array<Player, 2> players;
    MiddleCard middleCard;

    static std::vector<MoveCard> chooseCards(const std::vector<MoveCard>& allCards, int n);
    explicit GameController(const std::vector<MoveCard>& cards);

public:
    static GameController create(const std::vector<MoveCard>& allCards);
    void start();
    void display() const;
};

#endif //ONITAMALOCAL_GAMECONTROLLER_H
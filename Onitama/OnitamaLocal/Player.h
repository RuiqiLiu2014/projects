//
// Created by whale on 12/12/25.
//

#ifndef ONITAMALOCAL_PLAYER_H
#define ONITAMALOCAL_PLAYER_H
#include <vector>

#include "MoveCard.h"


class Player
{
    std::vector<MoveCard> cards;
    int index;

public:
    explicit Player(int index);
    void addCard(const MoveCard& card);
    void removeCard(int i);
    [[nodiscard]] const std::vector<MoveCard>& getCards() const;
    [[nodiscard]] bool isUpsideDown() const;
    void displayCards() const;
    void takeTurn();
};


#endif //ONITAMALOCAL_PLAYER_H
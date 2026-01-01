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
    int score;

public:
    explicit Player(const int index) : index(index), score(0) {}
    void addCard(const MoveCard& card);
    MoveCard removeCard(int i);
    void clearCards();
    [[nodiscard]] const std::vector<MoveCard>& getCards() const;
    [[nodiscard]] bool isUpsideDown() const;
    [[nodiscard]] int getScore() const;
    void addScore(int score);
    [[nodiscard]] int getIndex() const;
};


#endif //ONITAMALOCAL_PLAYER_H
//
// Created by whale on 12/12/25.
//

#include "Player.h"

void Player::addCard(const MoveCard& card)
{
    cards.push_back(card);
}

MoveCard Player::removeCard(const int i)
{
    MoveCard removed = cards[i];
    cards.erase(this->cards.begin() + i);
    return removed;
}

void Player::clearCards()
{
    cards.clear();
}

const std::vector<MoveCard>& Player::getCards() const
{
    return cards;
}

bool Player::isUpsideDown() const
{
    return index == 0;
}

int Player::getScore() const
{
    return score;
}

void Player::addScore(const int score)
{
    this->score += score;
}

int Player::getIndex() const
{
    return index;
}

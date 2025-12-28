//
// Created by whale on 12/12/25.
//

#include "Player.h"

#include <iostream>

Player::Player(const int index)
{
    this->cards = {};
    this->index = index;
}

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

const std::vector<MoveCard>& Player::getCards() const
{
    return cards;
}

bool Player::isUpsideDown() const
{
    return index == 0;
}

void Player::displayCards() const
{
    for (const MoveCard& card : cards)
    {
        std::cout << card.name << " ";
    }
    std::cout << std::endl;
}
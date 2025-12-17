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

void Player::removeCard(const int i)
{
    cards.erase(this->cards.begin() + i);
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

void Player::takeTurn()
{

}
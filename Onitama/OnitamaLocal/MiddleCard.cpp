//
// Created by whale on 12/16/25.
//

#include "MiddleCard.h"

const MoveCard& MiddleCard::getCard() const
{
    return card;
}

void MiddleCard::setCard(const MoveCard& card)
{
    this->card = card;
}

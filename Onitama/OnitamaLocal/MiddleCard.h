//
// Created by whale on 12/16/25.
//

#ifndef ONITAMALOCAL_MIDDLECARD_H
#define ONITAMALOCAL_MIDDLECARD_H
#include <utility>

#include "MoveCard.h"


class MiddleCard
{
    MoveCard card;

public:
    explicit MiddleCard(MoveCard card) : card(std::move(card)) {}
    [[nodiscard]] const MoveCard& getCard() const;
};

#endif //ONITAMALOCAL_MIDDLECARD_H
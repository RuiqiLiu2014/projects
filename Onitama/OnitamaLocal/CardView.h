//
// Created by whale on 12/14/25.
//

#ifndef ONITAMALOCAL_CARDVIEW_H
#define ONITAMALOCAL_CARDVIEW_H
#include <utility>

#include "MoveCard.h"


class CardView
{
    const MoveCard& card;
    int x, y;

public:
    CardView(const MoveCard& card, const int x, const int y) : card(card), x(x), y(y) {}
    void draw() const;
};


#endif //ONITAMALOCAL_CARDVIEW_H
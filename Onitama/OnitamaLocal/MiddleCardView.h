//
// Created by whale on 12/16/25.
//

#ifndef ONITAMALOCAL_MIDDLECARDVIEW_H
#define ONITAMALOCAL_MIDDLECARDVIEW_H
#include "CardView.h"

#include <utility>

#include "MiddleCard.h"


class MiddleCardView
{
    const MiddleCard& card;
    int x, y;

public:
    MiddleCardView(const MiddleCard& card, const int x, const int y) : card(card), x(x), y(y) {}
    void draw() const;
};


#endif //ONITAMALOCAL_MIDDLECARDVIEW_H
//
// Created by whale on 12/16/25.
//

#ifndef ONITAMALOCAL_MIDDLECARDVIEW_H
#define ONITAMALOCAL_MIDDLECARDVIEW_H

#include "MiddleCard.h"

class MiddleCardView
{
    const MiddleCard& card;

public:
    explicit MiddleCardView(const MiddleCard& card) : card(card) {}
    void draw(int x, int y) const;
};


#endif //ONITAMALOCAL_MIDDLECARDVIEW_H
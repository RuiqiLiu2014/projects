//
// Created by whale on 12/14/25.
//

#ifndef ONITAMALOCAL_CARDVIEW_H
#define ONITAMALOCAL_CARDVIEW_H
#include <raylib.h>
#include <utility>

#include "MoveCard.h"


class CardView
{
    const MoveCard& card;
    int x, y;
    bool hoverable;
    bool selected;
    [[nodiscard]] bool isHovered(Vector2 mousePos) const;

public:
    CardView(const MoveCard& card, const int x, const int y, const bool hoverable, const bool selected) : card(card), x(x), y(y), hoverable(hoverable), selected(selected) {}
    void draw(Vector2 mousePos) const;
};


#endif //ONITAMALOCAL_CARDVIEW_H
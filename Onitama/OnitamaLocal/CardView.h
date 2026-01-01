//
// Created by whale on 12/14/25.
//

#ifndef ONITAMALOCAL_CARDVIEW_H
#define ONITAMALOCAL_CARDVIEW_H
#include <raylib.h>

#include "MoveCard.h"

class CardView
{
    const MoveCard& card;
    bool hoverable;
    bool selected;
    [[nodiscard]] bool isHovered(Vector2 mousePos, int x, int y) const;

public:
    CardView(const MoveCard& card, const bool hoverable, const bool selected) : card(card), hoverable(hoverable), selected(selected) {}
    void draw(Vector2 mousePos, int x, int y) const;
};


#endif //ONITAMALOCAL_CARDVIEW_H
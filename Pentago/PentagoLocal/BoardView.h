//
// Created by whale on 1/16/26.
//

#ifndef PENTAGOLOCAL_BOARDVIEW_H
#define PENTAGOLOCAL_BOARDVIEW_H
#include <raylib.h>

#include "Board.h"
#include "HoverStatus.h"
#include "Turn.h"

class BoardView {
    const Board& board;
    HoverStatus hoverStatus;

public:
    explicit BoardView(const Board& board);
    void update();
    void draw(CellStatus currentTurn, TurnPhase currentPhase) const;
    [[nodiscard]] HoverStatus getHoverStatus() const;
};


#endif //PENTAGOLOCAL_BOARDVIEW_H
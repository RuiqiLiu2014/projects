//
// Created by whale on 1/16/26.
//

#ifndef PENTAGOLOCAL_BOARDVIEW_H
#define PENTAGOLOCAL_BOARDVIEW_H
#include <raylib.h>

#include "Board.h"
#include "HoverStatus.h"
#include "Turn.h"

struct RotationAnimation {
    Point subgrid = Point(-1, -1);
    float currentAngle = 0.0f;
    bool active = false;
    bool clockwise = false;
};

class BoardView {
    const Board& board;
    HoverStatus hoverStatus;
    RotationAnimation anim;

public:
    explicit BoardView(const Board& board);
    void update();
    void draw(CellStatus currentTurn, TurnPhase currentPhase) const;
    void startRotation(Point subgrid, bool clockwise);
    [[nodiscard]] bool isAnimating() const;
    [[nodiscard]] HoverStatus getHoverStatus() const;
};


#endif //PENTAGOLOCAL_BOARDVIEW_H
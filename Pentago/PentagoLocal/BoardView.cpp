//
// Created by whale on 1/16/26.
//

#include "BoardView.h"
#include "DisplayConfig.h"
#include "SubGridView.h"
#include "rlgl.h"

BoardView::BoardView(const Board& board) : board(board), hoverStatus(Point(-1, -1), Point(-1, -1)) {
}

void BoardView::update() {
    Vector2 mouse = GetMousePosition();
    hoverStatus.active = false;

    int size = board.getSize();
    bool break_out = false;
    for (int r = 0; r < size && !break_out; r++) {
        for (int c = 0; c < size; c++) {
            auto [x, y] = Display::SUBGRID(board.getSize(), r, c);
            if (CheckCollisionPointRec(mouse, { x - Display::SUBGRID_SIZE() / 2, y - Display::SUBGRID_SIZE() / 2, Display::SUBGRID_SIZE(), Display::SUBGRID_SIZE() })) {
                float relativeX = mouse.x - (x - Display::SUBGRID_SIZE() / 2);
                float relativeY = mouse.y - (y - Display::SUBGRID_SIZE() / 2);
                hoverStatus.active = true;
                hoverStatus.subgrid = Point(r, c);
                hoverStatus.cell = Point(static_cast<int>(relativeX / (Display::SUBGRID_SIZE() / 3)), static_cast<int>(relativeY / (Display::SUBGRID_SIZE() / 3)));
                break_out = true;
                break;
            }
        }
    }

    if (anim.active) {
        float speed = 90.0f; // Degrees per second
        float step = speed * GetFrameTime();

        if (anim.clockwise) anim.currentAngle += step;
        else anim.currentAngle -= step;

        // Check if finished
        if (std::abs(anim.currentAngle) >= 90) {
            anim.active = false;
            anim.currentAngle = 0;
        }
    }
}

void BoardView::draw(CellStatus currentTurn, TurnPhase currentPhase) const {
    const auto& subgrids = board.getSubgrids();
    for (int r = 0; r < board.getSize(); r++) {
        for (int c = 0; c < board.getSize(); c++) {
            auto [x, y] = Display::SUBGRID(board.getSize(), r, c);

            if (anim.active && anim.subgrid.r == r && anim.subgrid.c == c) {
                rlPushMatrix();
                rlTranslatef(x, y, 0.0f);
                rlRotatef(anim.currentAngle, 0, 0, 1);
                SubGridView(subgrids[r][c]).draw(0, 0, hoverStatus.active && r == hoverStatus.subgrid.r && c == hoverStatus.subgrid.c, hoverStatus.cell, hoverStatus.active && currentPhase == TurnPhase::Placing, currentTurn);
                rlPopMatrix();
            } else {
                SubGridView(subgrids[r][c]).draw(x, y, hoverStatus.active && r == hoverStatus.subgrid.r && c == hoverStatus.subgrid.c, hoverStatus.cell, hoverStatus.active && currentPhase == TurnPhase::Placing, currentTurn);
            }
        }
    }
}

void BoardView::startRotation(Point subgrid, bool clockwise) {
    anim.subgrid = subgrid;
    anim.currentAngle = 0;
    anim.active = true;
    anim.clockwise = clockwise;
}

HoverStatus BoardView::getHoverStatus() const {
    return hoverStatus;
}

bool BoardView::isAnimating() const {
    return anim.active;
}
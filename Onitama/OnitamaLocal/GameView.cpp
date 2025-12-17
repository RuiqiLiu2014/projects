//
// Created by whale on 12/14/25.
//

#include "GameView.h"

#include <utility>

void GameView::draw() const
{
    boardView.draw();
    playerViews[0].draw();
    playerViews[1].draw();
    middleCardView.draw();
}
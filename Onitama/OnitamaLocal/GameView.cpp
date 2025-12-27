//
// Created by whale on 12/14/25.
//

#include "GameView.h"

void GameView::draw(std::optional<Point> selectedCell) const
{
    boardView.draw(selectedCell);
    playerViews[0].draw();
    playerViews[1].draw();
    middleCardView.draw();
}

std::optional<Point> GameView::getHoveredCellLocation() const
{
    return boardView.getHoveredCell();
}

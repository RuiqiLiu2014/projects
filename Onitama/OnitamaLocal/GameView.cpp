//
// Created by whale on 12/14/25.
//

#include "GameView.h"

#include <utility>

#include "TurnIndicatorView.h"

void GameView::draw(const std::optional<Point> selectedCell, const int selectedCardIndex) const
{
    boardView.draw(selectedCell, Display::BOARD().x, Display::BOARD().y);
    playerViews[0].draw(Display::PLAYER(0).x, Display::PLAYER(0).y, turn == 0, selectedCardIndex);
    playerViews[1].draw(Display::PLAYER(1).x, Display::PLAYER(1).y, turn == 1, selectedCardIndex);
    middleCardView.draw(Display::MIDDLE_CARD().x, Display::MIDDLE_CARD().y);
    drawMessage();
    TurnIndicatorView(turn).draw(Display::TURN_INDICATOR().x, Display::TURN_INDICATOR().y);
}

void GameView::drawMessage() const
{
    Display::drawText(message.c_str(), Display::Width() / 2, Display::Height() - Display::WARNING_FONT_SIZE() * 4 / 3, Display::WARNING_FONT_SIZE(), RED);
}

std::optional<Point> GameView::getHoveredCellLocation() const
{
    return boardView.getHoveredCell(Display::BOARD().x, Display::BOARD().y);
}

int GameView::getHoveredCardIndex() const
{
    return playerViews[turn].getHoveredCardIndex(Display::PLAYER(turn).x, Display::PLAYER(turn).y);
}

void GameView::setTurn(const int turn)
{
    this->turn = turn;
}

void GameView::displayWarning(std::string str)
{
    message = std::move(str);
}

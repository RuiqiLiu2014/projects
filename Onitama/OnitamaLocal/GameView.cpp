//
// Created by whale on 12/14/25.
//

#include "GameView.h"

#include <utility>

void GameView::draw(const std::optional<Point> selectedCell, const int selectedCardIndex) const
{
    boardView.draw(selectedCell);
    playerViews[0].draw(turn == 0, selectedCardIndex);
    playerViews[1].draw(turn == 1, selectedCardIndex);
    middleCardView.draw();
    drawMessage();
}

void GameView::drawMessage() const
{
    const char* text = message.c_str();
    const int textWidth = MeasureText(text, Display::CARD_FONT_SIZE);
    constexpr int x = Display::WINDOW_WIDTH / 2;
    constexpr int y = Display::WINDOW_HEIGHT - Display::WARNING_FONT_SIZE - 10;

    DrawText(text, x - textWidth / 2, y, Display::WARNING_FONT_SIZE, RED);
}

std::optional<Point> GameView::getHoveredCellLocation() const
{
    return boardView.getHoveredCell();
}

int GameView::getHoveredCardIndex() const
{
    return playerViews[turn].getHoveredCardIndex();
}

void GameView::switchTurn()
{
    turn = 1 - turn;
}

void GameView::displayWarning(std::string str)
{
    message = std::move(str);
}

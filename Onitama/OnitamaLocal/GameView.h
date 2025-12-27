//
// Created by whale on 12/14/25.
//

#ifndef ONITAMALOCAL_GAMEVIEW_H
#define ONITAMALOCAL_GAMEVIEW_H
#include <array>

#include "BoardView.h"
#include "DisplayConfig.h"
#include "MiddleCardView.h"
#include "PlayerView.h"


class GameView
{
    std::array<PlayerView, 2> playerViews;
    MiddleCardView middleCardView;
    BoardView boardView;

public:
    GameView(const Board& board, const std::array<Player, 2>& players, const MiddleCard& middleCard) :
        playerViews{PlayerView(players[0], Display::WINDOW_WIDTH / 2, Display::PLAYER_VIEW_Y_OFFSET), PlayerView(players[1], Display::WINDOW_WIDTH / 2, Display::WINDOW_HEIGHT - Display::PLAYER_VIEW_Y_OFFSET)},
        middleCardView(middleCard, Display::WINDOW_WIDTH - Display::MIDDLE_CARD_X_OFFSET, Display::WINDOW_HEIGHT / 2),
        boardView(board, Display::WINDOW_WIDTH / 2, Display::WINDOW_HEIGHT / 2) {}
    void draw(std::optional<Point> selectedCell) const;
    [[nodiscard]] std::optional<Point> getHoveredCellLocation() const;
};


#endif //ONITAMALOCAL_GAMEVIEW_H
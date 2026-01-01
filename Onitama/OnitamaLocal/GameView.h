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
    int turn;
    std::string message;

    void drawMessage() const;

public:
    GameView(const Board& board, const std::array<Player, 2>& players, const MiddleCard& middleCard, const int turn) :
        playerViews{PlayerView(players[0]), PlayerView(players[1])},
        middleCardView(middleCard),
        boardView(board),
        turn(turn) {}
    void draw(std::optional<Point> selectedCell, int selectedCardIndex) const;
    [[nodiscard]] std::optional<Point> getHoveredCellLocation() const;
    [[nodiscard]] int getHoveredCardIndex() const;
    void setTurn(int turn);
    void displayWarning(std::string str);
};


#endif //ONITAMALOCAL_GAMEVIEW_H
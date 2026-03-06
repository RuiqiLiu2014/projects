//
// Created by whale on 2/27/26.
//

#ifndef BOOPLOCAL_GAMECONTROLLER_H
#define BOOPLOCAL_GAMECONTROLLER_H
#include <memory>

#include "Board.h"
#include "BoardView.h"
#include "Player.h"
#include "PlayerView.h"


class GameController {
    Board board;
    int turn;
    BoardView boardView;
    std::array<Player, 2> players;
    std::array<PlayerView, 2> playerViews;

public:
    GameController();
    void update();
    void display();
    void handleClick();
};


#endif //BOOPLOCAL_GAMECONTROLLER_H
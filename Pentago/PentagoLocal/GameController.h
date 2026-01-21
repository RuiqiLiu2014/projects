//
// Created by whale on 1/15/26.
//

#ifndef PENTAGOLOCAL_GAMECONTROLLER_H
#define PENTAGOLOCAL_GAMECONTROLLER_H
#include <memory>

#include "Board.h"
#include "BoardView.h"
#include "Turn.h"

enum class AppState {
    CHOOSE_PLAYERS,
    PLAYING
};

class GameController {
    std::unique_ptr<Board> board;
    std::unique_ptr<Turn> turn;
    AppState state;
    std::unique_ptr<BoardView> boardView;

    void drawPlayerSelect();
    void createGame(int players);

public:
    GameController();
    void update() const;
    void display();
    void handleClick() const;
};


#endif //PENTAGOLOCAL_GAMECONTROLLER_H
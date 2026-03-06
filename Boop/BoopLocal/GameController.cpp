//
// Created by whale on 2/27/26.
//

#include "GameController.h"

#include "DisplayConfig.h"

GameController::GameController() : board(Board()), turn(0), boardView(board), players({Player(0), Player(1)}), playerViews({PlayerView(&players[0]), PlayerView(&players[1])}) {
}

void GameController::update() {
}

void GameController::display() {
    boardView.draw(Display::Width() / 2, Display::Height() / 2);
    playerViews[0].draw(Display::playerViewEdgeOffset(), Display::Height() / 2);
    playerViews[1].draw(Display::Width() - Display::playerViewEdgeOffset(), Display::Height() / 2);
}

void GameController::handleClick() {
}
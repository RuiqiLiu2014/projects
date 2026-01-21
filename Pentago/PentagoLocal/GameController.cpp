//
// Created by whale on 1/15/26.
//

#include "GameController.h"

#include "DisplayConfig.h"
#include "raylib.h"

GameController::GameController() {
    board = nullptr;
    turn = nullptr;
    state = AppState::CHOOSE_PLAYERS;
    boardView = nullptr;
}

void GameController::createGame(int players) {
    board = std::make_unique<Board>(players == 2 ? 2 : 3);
    turn = std::make_unique<Turn>(players);
    state = AppState::PLAYING;
    boardView = std::make_unique<BoardView>(*board);
}

void GameController::drawPlayerSelect() {
    Display::drawText("Choose Number of Players", Display::TITLE().x, Display::TITLE().y, Display::TITLE_FONT_SIZE(), DARKGRAY);

    int options[] = {2, 3, 4};

    for (int i = 0; i < 3; i++) {
        float x = Display::BUTTONS().x - Display::BUTTON_SIZE() - Display::BUTTON_GAP() + i * (Display::BUTTON_SIZE() + Display::BUTTON_GAP());
        float y = Display::BUTTONS().y;

        Rectangle rect = { x - Display::BUTTON_SIZE() / 2, y - Display::BUTTON_SIZE() / 2, Display::BUTTON_SIZE(), Display::BUTTON_SIZE() };

        bool isHovered = CheckCollisionPointRec(GetMousePosition(), rect);

        DrawRectangleRec(rect, isHovered ? Display::BUTTON_HOVER_COLOR() : Display::BUTTON_COLOR());
        Display::drawText(std::to_string(options[i]).c_str(), x, y, Display::TITLE_FONT_SIZE(), LIGHTGRAY);

        if (isHovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            createGame(options[i]);
        }
    }
}

void GameController::update() const {
    if (state == AppState::PLAYING) {
        handleClick();
        boardView->update();
    }
}

void GameController::display() {
    switch (state) {
        case AppState::CHOOSE_PLAYERS: drawPlayerSelect(); break;
        case AppState::PLAYING: boardView->draw(turn->cellStatus()); break;
    }
}

void GameController::handleClick() const {
    switch (turn->turnPhase()) {
        case TurnPhase::Placing:
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if (HoverStatus hover = boardView->getHoverStatus(); hover.active) {
                    if (board->placePiece(turn->cellStatus(), hover.subgrid, hover.cell)) {
                        turn->next();
                        break;
                    }
                }
            }
        case TurnPhase::Rotating:
            if (HoverStatus hover = boardView->getHoverStatus(); hover.active) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    board->rotate(hover.subgrid, false);
                    turn->next();
                } else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
                    board->rotate(hover.subgrid, true);
                    turn->next();
                }
                break;
            }
    }
}
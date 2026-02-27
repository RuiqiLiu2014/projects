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

void GameController::drawWinScreen(CellStatus winner) {
    std::string text;
    switch (winner) {
        case CellStatus::P1: text = "Blue wins"; break;
        case CellStatus::P2: text = "Red wins"; break;
        case CellStatus::P3: text = "Green wins"; break;
        case CellStatus::P4: text = "Orange wins"; break;
        default: throw std::invalid_argument("Invalid winner");
    }
    Display::drawText(text.c_str(), Display::Width() / 2, Display::Height() / 2, Display::TITLE_FONT_SIZE() * 2, Display::MOUSE_COLOR(winner));
}

void GameController::drawMouse() const {
    HideCursor();
    Color color;
    if (state == AppState::PLAYING) {
        color = Display::CELL_COLOR(turn->cellStatus(), false, turn->cellStatus());
    } else {
        color = BLACK;
    }

    Vector2 mouse = GetMousePosition();

    DrawCircle(mouse.x, mouse.y, Display::MOUSE_RADIUS(), color);
}

void GameController::update() {
    if (state == AppState::PLAYING) {
        handleClick();
        CellStatus winner = board->winner();
        if (winner != CellStatus::EMPTY) {
            state = AppState::GAME_OVER;
        }
        boardView->update(*board);
    }
}

void GameController::display() {
    switch (state) {
        case AppState::CHOOSE_PLAYERS:
            drawPlayerSelect();
            break;
        case AppState::PLAYING:
            boardView->draw(turn->cellStatus(), turn->turnPhase());
            break;
        case AppState::GAME_OVER:
            boardView->draw(turn->cellStatus(), turn->turnPhase());
            drawWinScreen(board->winner());
            break;
    }
    drawMouse();
}

void GameController::handleClick() const {
    if (boardView->isAnimating()) return;
    switch (turn->turnPhase()) {
        case TurnPhase::Placing:
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if (HoverStatus hover = boardView->getHoverStatus(); hover.active) {
                    if (board->placePiece(turn->cellStatus(), hover.subgrid, hover.cell)) {
                        turn->next();
                    }
                }
            }
        break;
        case TurnPhase::Rotating:
            if (HoverStatus hover = boardView->getHoverStatus(); hover.active) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    boardView->startRotation(hover.subgrid, false);
                    turn->next();
                } else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
                    boardView->startRotation(hover.subgrid, true);
                    turn->next();
                }
            }
        break;
    }
}

void GameController::reset() const {
    board->reset();
    turn->reset();
}
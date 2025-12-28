//
// Created by whale on 12/12/25.
//

#ifndef ONITAMALOCAL_GAMECONTROLLER_H
#define ONITAMALOCAL_GAMECONTROLLER_H
#include <array>
#include <optional>

#include "Board.h"
#include "GameView.h"
#include "MiddleCard.h"
#include "MoveCard.h"
#include "Player.h"


class GameController
{
    Board board;
    std::array<Player, 2> players;
    MiddleCard middleCard;
    int currentTurn;
    int selectedCardIndex;
    std::optional<Point> selectedPieceLocation;
    std::optional<Point> targetLocation;
    GameView gameView;
    int winner;

    static std::vector<MoveCard> chooseCards(const std::vector<MoveCard>& allCards, int n);
    explicit GameController(const std::vector<MoveCard>& cards);
    void handleClick();
    [[nodiscard]] int getWinner() const;
    void switchTurn();

public:
    static GameController create(const std::vector<MoveCard>& allCards);
    void update();
    void display() const;
};

#endif //ONITAMALOCAL_GAMECONTROLLER_H
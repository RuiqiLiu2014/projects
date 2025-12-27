//
// Created by whale on 12/12/25.
//

#include "GameController.h"

#include <chrono>
#include <iostream>
#include <random>
#include <raylib.h>
#include <utility>

#include "BoardView.h"
#include "DisplayConfig.h"
#include "GameView.h"

GameController::GameController(const std::vector<MoveCard>& cards) : players{Player(0), Player(1)}, middleCard(cards[4]), currentTurn(0), gameView(board, players, middleCard), winner(-1)
{
    players[0].addCard(cards[0]);
    players[0].addCard(cards[1]);
    players[1].addCard(cards[2]);
    players[1].addCard(cards[3]);
}

std::vector<MoveCard> GameController::chooseCards(const std::vector<MoveCard>& allCards, int n)
{
    std::vector<MoveCard> chosenCards;
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::sample(allCards.begin(), allCards.end(), std::back_inserter(chosenCards), n, rng);
    return chosenCards;
}

GameController GameController::create(const std::vector<MoveCard>& allCards)
{
    return GameController(chooseCards(allCards, 5));
}

void GameController::update()
{
    handleClick();

    if (winner != -1) return;

    if (targetLocation.has_value())
    {
        std::cout << "9" << std::endl;
        if (board.movePiece(selectedPieceLocation.value(), targetLocation.value()))
        {
            selectedPieceLocation.reset();
            targetLocation.reset();
            currentTurn = 1 - currentTurn;
            winner = getWinner();
        } else
        {
            targetLocation.reset();
        }
    }
}

void GameController::display() const
{
    gameView.draw(selectedPieceLocation);
}

void GameController::handleClick()
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        const auto location = gameView.getHoveredCellLocation();

        if (location.has_value())
        {
            auto point = location.value();
            std::cout << point.r << " " << point.c << std::endl;

            if (selectedPieceLocation.has_value())
            {
                std::cout << "1" << std::endl;
                if (board.isPlayersPiece(currentTurn, point))
                {
                    std::cout << "2" << std::endl;
                    if (selectedPieceLocation.value() == point)
                    {
                        std::cout << "3" << std::endl;
                        selectedPieceLocation.reset();
                    } else
                    {
                        std::cout << "4" << std::endl;
                        selectedPieceLocation = point;
                    }
                } else
                {
                    std::cout << "5" << std::endl;
                    targetLocation = point;
                }
            } else
            {
                std::cout << "6" << std::endl;
                if (board.isPlayersPiece(currentTurn, point))
                {
                    std::cout << "7" << std::endl;
                    selectedPieceLocation = point;
                }
            }
        } else
        {
            std::cout << "8" << std::endl;
            selectedPieceLocation.reset();
        }
    }
}

int GameController::getWinner() const
{
    auto cells = board.getCells();
    bool blueKingAlive = false;
    bool redKingAlive = false;
    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            auto cell = cells[r][c];
            if (cell.getStatus() == CellStatus::BLUE_KING)
            {
                if (r == 4 && c == 2)
                {
                    return 0;
                }
                blueKingAlive = true;
            } else if (cell.getStatus() == CellStatus::RED_KING)
            {
                if (r == 0 && c == 2)
                {
                    return 1;
                }
                redKingAlive = true;
            }
        }
    }

    if (blueKingAlive && redKingAlive)
    {
        return -1;
    }
    if (blueKingAlive)
    {
        return 0;
    }
    return 1;
}

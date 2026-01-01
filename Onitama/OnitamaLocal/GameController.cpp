//
// Created by whale on 12/12/25.
//

#include "GameController.h"

#include <chrono>
#include <random>
#include <raylib.h>

#include "BoardView.h"
#include "GameView.h"

GameController::GameController(const std::vector<MoveCard>& cards) : players{Player(0), Player(1)}, middleCard(cards[4]), currentTurn(0), selectedCardIndex(-1), gameView(board, players, middleCard, currentTurn), winner(-1)
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
    std::ranges::sample(allCards, std::back_inserter(chosenCards), n, rng);
    return chosenCards;
}

GameController GameController::create()
{
    return GameController(chooseCards(MoveCard::ALL_CARDS, 5));
}

void GameController::update()
{
    handleClick();

    if (winner != -1)
    {
        players[winner].addScore(1);
        reset();
    }

    if (targetLocation.has_value())
    {
        if (board.movePiece(selectedPieceLocation.value(), targetLocation.value(), players[currentTurn].getCards()[selectedCardIndex], players[currentTurn].isUpsideDown()))
        {
            const MoveCard card = players[currentTurn].removeCard(selectedCardIndex);
            players[currentTurn].addCard(middleCard.getCard());
            middleCard.setCard(card);
            switchTurn();
            winner = getWinner();
        } else
        {
            gameView.displayWarning("Illegal move");
            targetLocation.reset();
        }
    }
}

void GameController::reset()
{
    board.reset();

    players[0].clearCards();
    players[1].clearCards();
    const std::vector<MoveCard>& cards = chooseCards(MoveCard::ALL_CARDS, 5);
    players[0].addCard(cards[0]);
    players[0].addCard(cards[1]);
    players[1].addCard(cards[2]);
    players[1].addCard(cards[3]);

    middleCard.setCard(cards[4]);

    currentTurn = winner;
    gameView.setTurn(currentTurn);

    selectedCardIndex = -1;
    selectedPieceLocation.reset();
    targetLocation.reset();
    winner = -1;
}

void GameController::display() const
{
    gameView.draw(selectedPieceLocation, selectedCardIndex);
}

void GameController::handleClick()
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        const auto hoveredCellLocation = gameView.getHoveredCellLocation();
        const auto hoveredCardIndex = gameView.getHoveredCardIndex();

        if (hoveredCellLocation.has_value())
        {
            auto point = hoveredCellLocation.value();

            if (selectedPieceLocation.has_value())
            {
                if (board.isPlayersPiece(currentTurn, point))
                {
                    if (selectedPieceLocation.value() == point)
                    {
                        selectedPieceLocation.reset();
                    } else
                    {
                        selectedPieceLocation = point;
                    }
                } else if (selectedCardIndex != -1)
                {
                    targetLocation = point;
                } else
                {
                    gameView.displayWarning("Select a move card first");
                }
            } else
            {
                if (board.isPlayersPiece(currentTurn, point))
                {
                    selectedPieceLocation = point;
                }
            }
        } else if (hoveredCardIndex != -1)
        {
            if (selectedCardIndex == hoveredCardIndex)
            {
                selectedCardIndex = -1;
            } else
            {
                selectedCardIndex = hoveredCardIndex;
                gameView.displayWarning("");
            }
        } else
        {
            selectedPieceLocation.reset();
        }
    }
}

int GameController::getWinner() const
{
    const auto cells = board.getCells();
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

void GameController::switchTurn()
{
    gameView.displayWarning("");
    selectedCardIndex = -1;
    selectedPieceLocation.reset();
    targetLocation.reset();
    currentTurn = 1 - currentTurn;
    gameView.setTurn(currentTurn);
}

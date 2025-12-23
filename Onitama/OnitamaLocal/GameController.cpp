//
// Created by whale on 12/12/25.
//

#include "GameController.h"

#include <chrono>
#include <iostream>
#include <random>
#include <utility>

#include "BoardView.h"
#include "DisplayConfig.h"
#include "GameView.h"

GameController::GameController(const std::vector<MoveCard>& cards) : players{Player(0), Player(1)}, middleCard(cards[4]), currentTurn(0)
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

void GameController::start()
{

}

void GameController::display() const
{
    GameView(board, players, middleCard).draw();
}


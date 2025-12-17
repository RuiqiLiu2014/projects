//
// Created by whale on 12/12/25.
//

#include "MoveCard.h"

#include <algorithm>
#include <utility>

MoveCard::MoveCard(std::string name, std::vector<Movement> movements)
{
    this->name = std::move(name);
    this->movements = std::move(movements);
}

bool MoveCard::canMoveTo(const int r, const int c) const
{
    return std::ranges::count(movements, Movement(r, c)) > 0;
}

std::vector<MoveCard> MoveCard::ALL_CARDS = {
    MoveCard("Cobra", {Movement(0, -1), Movement(1, 1), Movement(-1, 1)}),
    MoveCard("Ox", {Movement(-1, 0), Movement(1, 0), Movement(0, 1)}),
    MoveCard("Crab", {Movement(-1, 0), Movement(0, 2), Movement(0, -2)}),
    MoveCard("Boar", {Movement(0, -1), Movement(0, 1), Movement(-1, 0)}),
    MoveCard("Mantis", {Movement(-1, -1), Movement(-1, 1), Movement(1, 0)}),
    MoveCard("Dragon", {Movement(-1, -2), Movement(-1, 2), Movement(1, -1), Movement(1, 1)}),
    MoveCard("Monkey", {Movement(-1, -1), Movement(-1, 1), Movement(1, -1), Movement(1, 1)}),
    MoveCard("Rabbit", {Movement(1, -1), Movement(-1, 1), Movement(0, 2)}),
    MoveCard("Tiger", {Movement(-2, 0), Movement(1, 0)}),
    MoveCard("Eel", {Movement(-1, -1), Movement(1, -1), Movement(0, 1)}),
    MoveCard("Frog", {Movement(0, -2), Movement(-1, -1), Movement(1, 1)}),
    MoveCard("Crane", {Movement(1, -1), Movement(1, 1), Movement(-1, 0)}),
    MoveCard("Elephant", {Movement(0, 1), Movement(0, -1), Movement(-1, 1), Movement(-1, -1)}),
    MoveCard("Rooster", {Movement(0, -1), Movement(1, -1), Movement(0, 1), Movement(-1, 1)}),
    MoveCard("Goose", {Movement(0, -1), Movement(-1, -1), Movement(0, 1), Movement(1, 1)}),
    MoveCard("Horse", {Movement(0, -1), Movement(-1, 0), Movement(1, 0)}),
};

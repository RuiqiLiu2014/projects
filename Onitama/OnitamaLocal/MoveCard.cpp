//
// Created by whale on 12/12/25.
//

#include "MoveCard.h"

#include <algorithm>
#include <utility>

MoveCard::MoveCard(std::string name, std::vector<Point> movements)
{
    this->name = std::move(name);
    this->movements = std::move(movements);
}

bool MoveCard::canMoveTo(const int r, const int c) const
{
    return std::ranges::count(movements, Point(r, c)) > 0;
}

std::vector<MoveCard> MoveCard::ALL_CARDS = {
    MoveCard("Cobra", {Point(0, -1), Point(1, 1), Point(-1, 1)}),
    MoveCard("Ox", {Point(-1, 0), Point(1, 0), Point(0, 1)}),
    MoveCard("Crab", {Point(-1, 0), Point(0, 2), Point(0, -2)}),
    MoveCard("Boar", {Point(0, -1), Point(0, 1), Point(-1, 0)}),
    MoveCard("Mantis", {Point(-1, -1), Point(-1, 1), Point(1, 0)}),
    MoveCard("Dragon", {Point(-1, -2), Point(-1, 2), Point(1, -1), Point(1, 1)}),
    MoveCard("Monkey", {Point(-1, -1), Point(-1, 1), Point(1, -1), Point(1, 1)}),
    MoveCard("Rabbit", {Point(1, -1), Point(-1, 1), Point(0, 2)}),
    MoveCard("Tiger", {Point(-2, 0), Point(1, 0)}),
    MoveCard("Eel", {Point(-1, -1), Point(1, -1), Point(0, 1)}),
    MoveCard("Frog", {Point(0, -2), Point(-1, -1), Point(1, 1)}),
    MoveCard("Crane", {Point(1, -1), Point(1, 1), Point(-1, 0)}),
    MoveCard("Elephant", {Point(0, 1), Point(0, -1), Point(-1, 1), Point(-1, -1)}),
    MoveCard("Rooster", {Point(0, -1), Point(1, -1), Point(0, 1), Point(-1, 1)}),
    MoveCard("Goose", {Point(0, -1), Point(-1, -1), Point(0, 1), Point(1, 1)}),
    MoveCard("Horse", {Point(0, -1), Point(-1, 0), Point(1, 0)}),
};

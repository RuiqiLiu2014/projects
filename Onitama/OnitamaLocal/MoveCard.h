//
// Created by whale on 12/12/25.
//

#ifndef ONITAMALOCAL_MOVECARD_H
#define ONITAMALOCAL_MOVECARD_H
#include <string>
#include <vector>

#include "Point.h"

struct MoveCard
{
    std::string name;
    std::vector<Point> movements;

    MoveCard(std::string name, std::vector<Point> movements);
    [[nodiscard]] bool canMoveTo(int r, int c) const;
    static std::vector<MoveCard> ALL_CARDS;
};


#endif //ONITAMALOCAL_MOVECARD_H
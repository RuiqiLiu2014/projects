//
// Created by whale on 12/16/25.
//

#ifndef ONITAMALOCAL_PLAYERVIEW_H
#define ONITAMALOCAL_PLAYERVIEW_H
#include <vector>

#include "CardView.h"
#include "Player.h"


class PlayerView
{
    const Player& player;
    int x;
    int y;

public:
    PlayerView(const Player& player, const int x, const int y) : player(player), x(x), y(y) {}
    void draw() const;
};


#endif //ONITAMALOCAL_PLAYERVIEW_H
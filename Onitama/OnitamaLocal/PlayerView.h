//
// Created by whale on 12/16/25.
//

#ifndef ONITAMALOCAL_PLAYERVIEW_H
#define ONITAMALOCAL_PLAYERVIEW_H
#include <optional>
#include <raylib.h>
#include <vector>

#include "CardView.h"
#include "Player.h"


class PlayerView
{
    const Player& player;
    int x;
    int y;
    [[nodiscard]] Camera2D createCamera(bool upsideDown) const;

public:
    PlayerView(const Player& player, const int x, const int y) : player(player), x(x), y(y) {}
    void draw(bool isTurn, int selectedCardIndex) const;
    [[nodiscard]] int getHoveredCardIndex() const;
};


#endif //ONITAMALOCAL_PLAYERVIEW_H
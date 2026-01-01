//
// Created by whale on 12/16/25.
//

#ifndef ONITAMALOCAL_PLAYERVIEW_H
#define ONITAMALOCAL_PLAYERVIEW_H
#include <raylib.h>

#include "Player.h"

class PlayerView
{
    const Player& player;
    [[nodiscard]] static Camera2D createCamera(bool upsideDown, int x, int y);

public:
    explicit PlayerView(const Player& player) : player(player) {}
    void draw(int x, int y, bool isTurn, int selectedCardIndex) const;
    [[nodiscard]] int getHoveredCardIndex(int x, int y) const;
};


#endif //ONITAMALOCAL_PLAYERVIEW_H
//
// Created by whale on 2/27/26.
//

#ifndef BOOPLOCAL_PLAYERVIEW_H
#define BOOPLOCAL_PLAYERVIEW_H
#include <raylib.h>

#include "Player.h"


class PlayerView {
    const Player* player;

public:
    explicit PlayerView(const Player* player);
    void draw(int x, int y) const;
};


#endif //BOOPLOCAL_PLAYERVIEW_H
//
// Created by whale on 2/27/26.
//

#ifndef BOOPLOCAL_PLAYER_H
#define BOOPLOCAL_PLAYER_H

struct Player {
    int index;
    int kittens = 8;
    int cats = 0;

    explicit Player(int index) : index(index) {}
};

#endif //BOOPLOCAL_PLAYER_H
//
// Created by whale on 2/27/26.
//

#ifndef BOOPLOCAL_POINT_H
#define BOOPLOCAL_POINT_H

struct Point {
    int r, c;

    bool inBounds() const {
        return r >= 0 && r < 6 && c >= 0 && c < 6;
    }
};

#endif //BOOPLOCAL_POINT_H
//
// Created by whale on 12/13/25.
//

#ifndef ONITAMALOCAL_MOVEMENT_H
#define ONITAMALOCAL_MOVEMENT_H


struct Movement
{
    int dr;
    int dc;

    Movement(const int dr, const int dc) : dr(dr), dc(dc) {}
    bool operator==(const Movement& other) const {
        return dr == other.dr && dc == other.dc;
    }
};


#endif //ONITAMALOCAL_MOVEMENT_H
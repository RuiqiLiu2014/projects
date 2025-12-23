//
// Created by whale on 12/13/25.
//

#ifndef ONITAMALOCAL_MOVEMENT_H
#define ONITAMALOCAL_MOVEMENT_H


struct Point
{
    int r;
    int c;

    Point(const int r, const int c) : r(r), c(c) {}
    bool operator==(const Point& other) const {
        return r == other.r && c == other.c;
    }
};


#endif //ONITAMALOCAL_MOVEMENT_H
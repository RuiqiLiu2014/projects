//
// Created by whale on 1/20/26.
//

#ifndef PENTAGOLOCAL_POINT_H
#define PENTAGOLOCAL_POINT_H

struct Point {
    int r, c;

    Point(const int r, const int c) : r(r), c(c) {}
    bool operator==(const Point& other) const {
        return r == other.r && c == other.c;
    }
};

#endif //PENTAGOLOCAL_POINT_H
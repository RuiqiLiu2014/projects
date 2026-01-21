//
// Created by whale on 1/20/26.
//

#ifndef PENTAGOLOCAL_HOVERSTATUS_H
#define PENTAGOLOCAL_HOVERSTATUS_H

struct HoverStatus {
    Point subgrid;
    Point cell;
    bool active = false;

    HoverStatus(Point subgrid, Point cell) : subgrid(subgrid), cell(cell) {}
};

#endif //PENTAGOLOCAL_HOVERSTATUS_H
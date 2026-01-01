//
// Created by whale on 1/1/26.
//

#ifndef ONITAMALOCAL_TURNINDICATORVIEW_H
#define ONITAMALOCAL_TURNINDICATORVIEW_H


class TurnIndicatorView
{
    int turn;

public:
    explicit TurnIndicatorView(const int turn) : turn(turn) {}
    void draw(int x, int y) const;
};


#endif //ONITAMALOCAL_TURNINDICATORVIEW_H
//
// Created by whale on 12/30/25.
//

#ifndef ONITAMALOCAL_SCOREVIEW_H
#define ONITAMALOCAL_SCOREVIEW_H
#include <raylib.h>


class ScoreView
{
    int score;

public:
    explicit ScoreView(const int score) : score(score) {}
    void draw(int x, int y, Color color) const;
};


#endif //ONITAMALOCAL_SCOREVIEW_H
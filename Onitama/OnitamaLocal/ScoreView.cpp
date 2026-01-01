//
// Created by whale on 12/30/25.
//

#include "ScoreView.h"

#include <raylib.h>
#include <string>

#include "DisplayConfig.h"

void ScoreView::draw(const int x, const int y, const Color color) const
{
    Display::drawText(std::to_string(score).c_str(), x, y - Display::SCORE_FONT_SIZE() / 2, Display::SCORE_FONT_SIZE(), color);
}
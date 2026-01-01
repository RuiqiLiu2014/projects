//
// Created by whale on 1/1/26.
//

#include "TurnIndicatorView.h"

#include "DisplayConfig.h"

void TurnIndicatorView::draw(const int x, const int y) const
{
    const auto xf = static_cast<float>(x);
    const float startY = y + (turn == 0 ? -Display::TURN_INDICATOR_OFFSET() : Display::TURN_INDICATOR_OFFSET());
    const float endY = startY + (turn == 0 ? -Display::TURN_INDICATOR_ARROW_LENGTH() : Display::TURN_INDICATOR_ARROW_LENGTH());
    Display::drawArrow(Vector2{xf, startY}, Vector2{xf, endY}, Display::TURN_INDICATOR_THICKNESS(), turn == 0 ? BLUE : RED);
}

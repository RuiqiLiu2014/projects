//
// Created by whale on 2/27/26.
//

#include "PlayerView.h"

#include <raylib.h>
#include <string>

#include "DisplayConfig.h"

PlayerView::PlayerView(const Player* player) : player(player) {
}

void PlayerView::draw(int x, int y) const {
    int y1 = y - Display::playerViewRectHeight() / 2 - Display::playerViewCatGap() / 2;
    int y2 = y + Display::playerViewRectHeight() / 2 + Display::playerViewCatGap() / 2;

    DrawRectangleLines(x - Display::playerViewRectWidth() / 2, y1 - Display::playerViewRectHeight() / 2,
        Display::playerViewRectWidth(), Display::playerViewRectHeight(), Display::playerColor(player->index));
    Display::drawKitten(x, y1 + Display::playerViewFontSize(), player->index);
    Display::drawText(std::to_string(player->kittens).c_str(), x, y1 - Display::playerViewRectHeight() / 2 + Display::playerViewFontSize() / 2,
        Display::playerViewFontSize(), Display::playerColor(player->index));

    DrawRectangleLines(x - Display::playerViewRectWidth() / 2, y2 - Display::playerViewRectHeight() / 2,
        Display::playerViewRectWidth(), Display::playerViewRectHeight(), Display::playerColor(player->index));
    Display::drawCat(x, y2 + Display::playerViewFontSize(), player->index);
    Display::drawText(std::to_string(player->cats).c_str(), x, y2 - Display::playerViewRectHeight() / 2 + Display::playerViewFontSize() / 2,
        Display::playerViewFontSize(), Display::playerColor(player->index));
}
//
// Created by whale on 12/16/25.
//

#include "PlayerView.h"

#include <raylib.h>

#include "DisplayConfig.h"

void PlayerView::draw() const
{
    Camera2D camera = {};
    camera.target = (Vector2){static_cast<float>(x), static_cast<float>(y)};
    camera.offset = (Vector2){static_cast<float>(x), static_cast<float>(y)};
    if (player.isUpsideDown())
    {
        camera.rotation = 180;
    } else
    {
        camera.rotation = 0;
    }
    camera.zoom = 1;

    BeginMode2D(camera);
    const auto cards = player.getCards();
    CardView(cards[0], x - Display::PLAYER_CARD_GAP / 2, y).draw();
    CardView(cards[1], x + Display::PLAYER_CARD_GAP / 2, y).draw();
    EndMode2D();
}
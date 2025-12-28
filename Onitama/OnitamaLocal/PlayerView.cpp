//
// Created by whale on 12/16/25.
//

#include "PlayerView.h"

#include <raylib.h>

#include "DisplayConfig.h"

void PlayerView::draw(const bool isTurn, const int selectedCardIndex) const
{
    const Camera2D camera = createCamera(player.isUpsideDown());
    BeginMode2D(camera);
    const auto cards = player.getCards();
    CardView(cards[0], x - Display::PLAYER_CARD_CENTER_GAP / 2, y, isTurn, isTurn && selectedCardIndex == 0).draw(GetScreenToWorld2D(GetMousePosition(), camera));
    CardView(cards[1], x + Display::PLAYER_CARD_CENTER_GAP / 2, y, isTurn, isTurn && selectedCardIndex == 1).draw(GetScreenToWorld2D(GetMousePosition(), camera));
    EndMode2D();
}

int PlayerView::getHoveredCardIndex() const
{
    Vector2 mousePos = GetScreenToWorld2D(GetMousePosition(), createCamera(player.isUpsideDown()));
    const float relativeX = mousePos.x - x;
    const float relativeY = mousePos.y - y;

    if (std::abs(relativeY) <= Display::CARD_HEIGHT / 2)
    {
        if (relativeX >= Display::PLAYER_CARD_CENTER_GAP / 2.0 - Display::CARD_WIDTH / 2)
        {
            return 1;
        }
        if (relativeX <= -(Display::PLAYER_CARD_CENTER_GAP / 2.0 - Display::CARD_WIDTH / 2))
        {
            return 0;
        }
    }

    return -1;
}

Camera2D PlayerView::createCamera(const bool upsideDown) const
{
    Camera2D camera = {};
    camera.target = (Vector2){static_cast<float>(x), static_cast<float>(y)};
    camera.offset = (Vector2){static_cast<float>(x), static_cast<float>(y)};
    camera.rotation = upsideDown ? 180 : 0;
    camera.zoom = 1;

    return camera;
}

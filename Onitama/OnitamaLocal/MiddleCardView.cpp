//
// Created by whale on 12/16/25.
//

#include "MiddleCardView.h"

#include <raylib.h>

#include "CardView.h"

void MiddleCardView::draw(const int x, const int y) const
{
    Camera2D camera = {};
    camera.target = (Vector2){static_cast<float>(x), static_cast<float>(y)};
    camera.offset = (Vector2){static_cast<float>(x), static_cast<float>(y)};
    camera.rotation = 90;
    camera.zoom = 1;

    BeginMode2D(camera);
    CardView(card.getCard(), false, false).draw(GetScreenToWorld2D(GetMousePosition(), camera), x, y);
    EndMode2D();
}

#include "CardView.h"
#include "DisplayConfig.h"
#include "GameController.h"
#include "MoveCard.h"
#include "raylib.h"

int main()
{
    auto gameController = GameController::create(MoveCard::ALL_CARDS);

    // Initialization
    InitWindow(Display::WINDOW_WIDTH, Display::WINDOW_HEIGHT, "Onitama");
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        gameController.update();

        // Drawing
        BeginDrawing();
        ClearBackground(RAYWHITE);
        gameController.display();
        EndDrawing();
    }

    // De-Initialization
    CloseWindow();
    return 0;
}
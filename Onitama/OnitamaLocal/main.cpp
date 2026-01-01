#include <iostream>

#include "DisplayConfig.h"
#include "GameController.h"
#include "MoveCard.h"
#include "raylib.h"

int main()
{
    // Initialization
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1000, 1000, "Onitama");
    SetTargetFPS(60);

    auto gameController = GameController::create();

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        gameController.update();

        // Drawing
        BeginDrawing();
        ClearBackground(WHITE);
        gameController.display();
        EndDrawing();
    }

    // De-Initialization
    CloseWindow();
    return 0;
}
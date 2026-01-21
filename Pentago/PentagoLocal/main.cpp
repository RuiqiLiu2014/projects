#include "GameController.h"
#include "raylib.h"

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(900, 900, "Pentago");
    SetTargetFPS(60);

    auto gameController = GameController();

    // Main game loop
    while (!WindowShouldClose()) {
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
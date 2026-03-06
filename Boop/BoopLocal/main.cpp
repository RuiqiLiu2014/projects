#include "GameController.h"
#include "raylib.h"

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1200, 900, "Boop");
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
#include "raylib.h"
#include "Board.h"
int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Pokemon 2048");

    SetTargetFPS(60);

    Board gameBoard = Board();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        gameBoard.Draw(screenHeight, screenWidth);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
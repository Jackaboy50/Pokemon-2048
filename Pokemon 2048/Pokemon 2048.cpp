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
        // Controls
        if (IsKeyPressed(KEY_SPACE)) {
            gameBoard.NewTile();
        }

        // WASD and arrow key controls for shifting tiles
        if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) gameBoard.Shift(0);
        if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) gameBoard.Shift(1);
        if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) gameBoard.Shift(2);
        if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) gameBoard.Shift(3);

        // Drawing
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawFPS(0, 0);
        gameBoard.Draw(screenWidth, screenHeight);
        gameBoard.DrawTiles(screenWidth, screenHeight);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
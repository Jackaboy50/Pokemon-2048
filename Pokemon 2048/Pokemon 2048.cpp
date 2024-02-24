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

        // WASD and arrow key controls for shifting tiles
        if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) gameBoard.LeftShift();
        if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) gameBoard.UpShift();
        if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) gameBoard.DownShift();
        if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) gameBoard.RightShift();

        // Drawing
        BeginDrawing();

        ClearBackground(RAYWHITE);

        gameBoard.Draw(screenWidth, screenHeight);
        gameBoard.DrawTiles(screenWidth, screenHeight);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
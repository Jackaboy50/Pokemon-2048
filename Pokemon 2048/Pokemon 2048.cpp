#include "raylib.h"
#include "Board.h"
#include <string>
int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Pokemon 2048");

    SetTargetFPS(60);

    Board gameBoard = Board();
    int highScore = 0;

    

    while (!WindowShouldClose())
    {
        // Replace highscore with the current game score if it is greater
        if (highScore < gameBoard.TotalScore()) highScore = gameBoard.TotalScore();

        // Controls
        // WASD and arrow key controls for shifting tiles
        if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) gameBoard.LeftShift();
        if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) gameBoard.UpShift();
        if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) gameBoard.DownShift();
        if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) gameBoard.RightShift();

        // R to restart the game
        if (IsKeyPressed(KEY_R)) gameBoard.Restart();

        // Drawing
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Draw on screen elements
        DrawText(("Total Score: " + std::to_string(gameBoard.TotalScore())).c_str(), 10, 0, 30, BLACK);
        DrawText(("High Score: " + std::to_string(highScore)).c_str(), 10, screenHeight * 0.05, 30, BLACK);
        DrawText("WASD or arrow keys to shift the tiles", 5, screenHeight - screenHeight * 0.1, 20, BLACK);
        DrawText("R to restart the game", 5, screenHeight - screenHeight * 0.05, 20, BLACK);
        gameBoard.Draw(screenWidth, screenHeight);
        gameBoard.DrawTiles(screenWidth, screenHeight);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
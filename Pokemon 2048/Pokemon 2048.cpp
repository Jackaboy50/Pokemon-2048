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
    Tile::LoadSpriteSheet();
    bool toolTips = true;
    int highScore = 0;

    Color backgroundColour = { 142, 135, 189, 255};
    Color gridColour = { 76, 76, 159, 255 };
    Color textColour = RAYWHITE;

    while (!WindowShouldClose())
    {
        // Replace highscore with the current game score if it is greater
        if (highScore < gameBoard.TotalScore()) highScore = gameBoard.TotalScore();

        // Controls
        // WASD and arrow key controls for shifting tiles
        if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) { gameBoard.LeftShift(); toolTips = false; }
        if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) { gameBoard.UpShift(); toolTips = false; }
        if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) { gameBoard.DownShift(); toolTips = false; }
        if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) { gameBoard.RightShift(); toolTips = false; }

        // R to restart the game
        if (IsKeyPressed(KEY_R)) { gameBoard.Restart(); toolTips = true; }

        // Space to change draw type
        if (IsKeyPressed(KEY_SPACE)) Tile::ChangeDrawType();

        // Drawing
        BeginDrawing();

        ClearBackground(backgroundColour);

        // Draw on screen elements
        DrawText(("Total Score: " + std::to_string(gameBoard.TotalScore())).c_str(), 10, 0, 30, textColour);
        DrawText(("High Score: " + std::to_string(highScore)).c_str(), 10, (int)(screenHeight * 0.05), 30, textColour);
        if (toolTips) {
            DrawText("WASD or arrow keys to shift the tiles", 5, screenHeight - (int)(screenHeight * 0.1), 20, textColour);
            DrawText("R to restart the game", 5, screenHeight - (int)(screenHeight * 0.05), 20, textColour);
        }
        gameBoard.Draw(screenWidth, screenHeight, gridColour);
        gameBoard.DrawTiles(screenWidth, screenHeight);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
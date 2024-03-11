#include "raylib.h"
#include "Tile.h"
#include <string>

Tile::Tile(int state) {
	this->state = state;
	// Load the spriteSheet texture from the spritesheet.png
	Image image = LoadImage("Pokemon-2048/spritesheet.png");
	spriteSheet = LoadTextureFromImage(image);
	UnloadImage(image);
}

Tile::Tile() { 
	state = 0; 
	// Load the spriteSheet texture from the spritesheet.png
	Image image = LoadImage("Pokemon-2048/spritesheet.png");
	spriteSheet = LoadTextureFromImage(image);
	UnloadImage(image);
}

bool Tile::drawType = true;

void Tile::IncrementState() {
	// If state is 0 make it 2, otherwise multiply by 2
	state == 0 ? state = 2 : state *= 2;
}

void Tile::ResetState() {
	state = 0;
}

void Tile::SetState(int state) {
	this->state = state;
}

int Tile::CheckState() {
	return state;
}

void Tile::ResetSize() {
	tileSizePercentage = 0.1;
	tileOffsetPercentage = 0;
}

void Tile::FlagMerged(bool flag) {
	merged = flag;
}

bool Tile::HasMerged() {
	return merged;
}

void Tile::SetOffset(int x, int y) {
	tileShiftOffset = { (float)x, (float)y };
	tileOffsetPercentage = 1;
}

void Tile::Draw(Vector2 screenDimensions, int x, int y) {
	// If drawType is true then we draw using standard 2048 tiles
	// else we draw using the Pokemon tiles
	if (drawType) {
		Draw2048(screenDimensions, x, y);
	}
	else {
		DrawPokemon(screenDimensions, x, y);
	}
}

void Tile::Draw2048(Vector2 screenDimensions, int x, int y) {

	// Get sizes smaller than screen
	// Cast to int as the draw method takes integer arguments
	int halfWidth = (int)(screenDimensions.x * 0.75);
	int increment = (int)(halfWidth / 4);

	// Create offsets for the start of the board
	int xOffset = (int)(screenDimensions.x * 0.1) + 20;
	int yOffset = (int)(screenDimensions.y * 0.1) + 20;

	// Create positions for the tiles on the board
	int posX = xOffset + (increment * x);
	int posY = yOffset + (increment * y);

	// Get the index for the colour array based on the log2 of the state
	int index = (int)log2(state) - 1;

	if (tileOffsetPercentage > 0) {
		// Create positions for where the tile was before it was shifted
		int oldPosX = xOffset + (increment * (int)tileShiftOffset.x);
		int oldPosY = yOffset + (increment * (int)tileShiftOffset.y);

		// Create the offsets between the two positions
		int posXOffset = (int)((oldPosX - posX) * tileOffsetPercentage);
		int posYOffset = (int)((oldPosY - posY) * tileOffsetPercentage);

		// Draw the tile with varing levels of posX/yOffset to simulate it moving to the new positon
		DrawRectangle(posX + posXOffset, posY + posYOffset, 140, 140, colours[index]);
		DrawText(std::to_string(state).c_str(), posX + 55 + posXOffset, posY + 50 + posYOffset, 50, WHITE);

		// Decrease the offset percentage to make the offset smaller
		tileOffsetPercentage -= 0.1;
	}
	else if (tileSizePercentage < 1) {
		// Uses the tileSizePercentage float to slowly grow the tile from the middle until it is at full size
		DrawRectangle(posX + (55 - (int)(55 * tileSizePercentage)), posY + (50 - (int)(50 * tileSizePercentage)), (int)(140 * tileSizePercentage), (int)(140 * tileSizePercentage), colours[index]);
		DrawText(std::to_string(state).c_str(), posX + 55, posY + 50, (int)(50 * tileSizePercentage), WHITE);
		tileSizePercentage += 0.075;
	}
	else {
		// Once the tile is at full size and not shifting, draw the tile using the variables
		DrawRectangle(posX, posY, 140, 140, colours[index]);
		DrawText(std::to_string(state).c_str(), posX + 55, posY + 50, 50, WHITE);
	}
}

void Tile::DrawPokemon(Vector2 screenDimensions, int x, int y) {
	// Rectangle - { startX, startY, lengthX, lengthY }
	// spriteSheet - { 5, 5 } origin / 250x250 tiles / offset by +-260
	//DrawTexturePro(spriteSheet, { 5, 5, 255, 255 }, { 5, 5, 125, 125 }, { 0, 0 }, 0, WHITE);

}
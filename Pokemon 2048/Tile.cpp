#include "raylib.h"
#include "Tile.h"
#include <string>

Tile::Tile(int state) {
	this->state = state;
	merged = false;
}

Tile::Tile() { state = 0; }

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

void Tile::FlagMerged(bool flag) {
	merged = flag;
}

bool Tile::HasMerged() {
	return merged;
}

void Tile::Draw(Vector2 screenDimensions, int x, int y) {

	// Get sizes smaller than screen
	// Cast to int as the draw method takes integer arguments
	int halfWidth = (int)(screenDimensions.x * 0.75);
	int increment = (int)(halfWidth / 4);

	// Create offsets for the start of the board
	int xOffset = (int)(screenDimensions.x * 0.1) + 20;
	int yOffset = (int)(screenDimensions.y * 0.1) + 20;

	// Draw tiles using variables
	DrawRectangle(xOffset + (increment * x), yOffset + (increment * y), 140, 140, colours[(int)log2(state) - 1]);
	DrawText(std::to_string(state).c_str(), xOffset + (increment * x), yOffset + (increment * y), 50, WHITE);
}
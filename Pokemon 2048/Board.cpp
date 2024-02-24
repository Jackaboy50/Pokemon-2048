#include "raylib.h"
#include "Board.h"
#include <cstdlib>
#include <time.h>

Board::Board() {
	total = 0;
	// Seed the random number generator with the current time
	srand(time(0));
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			tiles[x][y] = Tile(0);
		}
	}
	// Create two new tiles to start the game off
	NewTile();
	NewTile();
}

void Board::LeftShift() {
	// Left shift
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			// If the tile is inactive we don't need to shift it
			if (tiles[x][y].CheckState() == 0) continue;

			// Loop through tiles to the left to see how far the tile can shift
			int endTileX = x;
			bool merged = false;
			for (int i = x - 1; i > -1; i--) {
				// Cache the position of the tile it can shift to
				if (tiles[i][y].CheckState() == 0) {
					endTileX = i;
				}
				else if (tiles[i][y].CheckState() == tiles[x][y].CheckState()) {
					// If the tile has already merged, break to avoid a double merge
					if (tiles[i][y].HasMerged()) break;

					// If both active tiles share the same value, merge them
					Merge({ (float)i, (float)y }, { (float)x, (float)y});
					merged = true;
					break;
				}
				else {
					// If an active tile to the left is in the way, it cannot shift any further
					break;
				}
			}
			if (merged) continue;
			// Store the state of the tile and reset it, then move the value to the empty space
			int state = tiles[x][y].CheckState();
			tiles[x][y].ResetState();
			tiles[endTileX][y].SetState(state);
		}
	}
	ResetMergeFlags();
	NewTile();
}

void Board::UpShift() {
	// Up shift
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			// If the tile is inactive we don't need to shift it
			if (tiles[x][y].CheckState() == 0) continue;

			// Loop through tiles above to see how far the tile can shift
			int endTileY = y;
			bool merged = false;
			for (int i = y - 1; i > -1; i--) {
				// Cache the position of the tile it can shift to
				if (tiles[x][i].CheckState() == 0) {
					endTileY = i;
				}
				else if (tiles[x][i].CheckState() == tiles[x][y].CheckState()) {
					// If the tile has already merged, break to avoid a double merge
					if (tiles[x][i].HasMerged()) break;

					// If both active tiles share the same value, merge them
					Merge({ (float)x, (float)i }, { (float)x, (float)y });
					merged = true;
					break;
				}
				else {
					// If an active tile above is in the way, it cannot shift any further
					break;
				}
			}
			if (merged) continue;
			// Store the state of the tile and reset it, then move the value to the empty space
			int state = tiles[x][y].CheckState();
			tiles[x][y].ResetState();
			tiles[x][endTileY].SetState(state);
		}
	}
	ResetMergeFlags();
	NewTile();
}

void Board::DownShift() {
	// Down shift
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			// If the tile is inactive we don't need to shift it
			if (tiles[x][y].CheckState() == 0) continue;

			// Loop through tiles below to see how far the tile can shift
			int endTileY = y;
			bool merged = false;
			for (int i = y + 1; i < 4; i++) {
				// Cache the position of the tile it can shift to
				if (tiles[x][i].CheckState() == 0) {
					endTileY = i;
				}
				else if (tiles[x][i].CheckState() == tiles[x][y].CheckState()) {
					// If the tile has already merged, break to avoid a double merge
					if (tiles[x][i].HasMerged()) break;

					// If both active tiles share the same value, merge them
					Merge({ (float)x, (float)i }, { (float)x, (float)y });
					merged = true;
					break;
				}
				else {
					// If an active tile below is in the way, it cannot shift any further
					break;
				}
			}
			if (merged) continue;
			// Store the state of the tile and reset it, then move the value to the empty space
			int state = tiles[x][y].CheckState();
			tiles[x][y].ResetState();
			tiles[x][endTileY].SetState(state);
		}
	}
	ResetMergeFlags();
	NewTile();
}

void Board::RightShift() {
	// Right shift
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			// If the tile is inactive we don't need to shift it
			if (tiles[x][y].CheckState() == 0) continue;

			// Loop through tiles to the left to see how far the tile can shift
			int endTileX = x;
			bool merged = false;
			for (int i = x + 1; i < 4; i++) {
				// Cache the position of the tile it can shift to
				if (tiles[i][y].CheckState() == 0) {
					endTileX = i;
				}
				else if (tiles[i][y].CheckState() == tiles[x][y].CheckState()) {
					// If the tile has already merged, break to avoid a double merge
					if (tiles[i][y].HasMerged()) break;

					// If both active tiles share the same value, merge them
					Merge({ (float)i, (float)y }, { (float)x, (float)y });
					merged = true;
					break;
				}
				else {
					// If an active tile to the left is in the way, it cannot shift any further
					break;
				}
			}
			if (merged) continue;
			// Store the state of the tile and reset it, then move the value to the empty space
			int state = tiles[x][y].CheckState();
			tiles[x][y].ResetState();
			tiles[endTileX][y].SetState(state);
		}
	}
	ResetMergeFlags();
	NewTile();
}

void Board::Merge(Vector2 mergedTile, Vector2 mergingTile) {
	// Increment the state of the merged tile
	// Set the merged flag to true so it won't merge twice in a single shift
	tiles[(int)mergedTile.x][(int)mergedTile.y].IncrementState();
	tiles[(int)mergedTile.x][(int)mergedTile.y].FlagMerged(true);

	// Reset the state of the merging tile so it becomes blank
	tiles[(int)mergingTile.x][(int)mergingTile.y].ResetState();
}

void Board::ResetMergeFlags() {
	// Loop through all tiles and set their merged flags to false
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			tiles[x][y].FlagMerged(false);
		}
	}
}

void Board::NewTile() {
	// Loop through all tiles to see if there is an empty tile
	bool emptyTile = false;
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			if (tiles[x][y].CheckState() == 0) {
				emptyTile = true;
				break;
			}
		}
	}
	// If there is no empty tile, don't create a new one
	if (!emptyTile) return;

	// Create the indices and bool flag for the loop
	int tileXIndex;
	int tileYIndex;
	bool validIndex = false;

	// Loop while the flag is false
	while (!validIndex) {

		// Set the indices to random number
		tileXIndex = rand() % 4;
		tileYIndex = rand() % 4;
		// Check if the tile at the random index is empty
		if (tiles[tileXIndex][tileYIndex].CheckState() == 0) {
			validIndex = true;
			break;
		}
	}

	// Increment the random, empty tile 
	tiles[tileXIndex][tileYIndex].IncrementState();

	// Creates a 10% chance that a new tile can start as a 4
	int fourTileChance = rand() % 9;
	if(fourTileChance == 9) tiles[tileXIndex][tileYIndex].IncrementState();
	tiles[tileXIndex][tileYIndex].ResetSize();
}

void Board::Draw(int width, int height) {

	// Get sizes smaller than screen
	// Cast to int as the draw method takes integer arguments
	int halfHeight = (int)(height * 0.75);
	int halfWidth = (int)(width * 0.75);
	int increment = (int)(halfWidth / 4);

	// Create offsets to start the board
	int xOffset = (int)(width * 0.1) + 10;
	int yOffset = (int)(height * 0.1) + 10;

	// Loop to draw 5 grid lines on x-axis
	for (int i = xOffset; i <= halfWidth + xOffset; i += increment) {
		DrawRectangle(i, yOffset, 10, halfHeight + 10, BEIGE); // halfheight + 10 to make up for missed end corner
	}

	// Loop to draw 5 grid lines on y-axis
	increment = halfHeight / 4;
	for (int i = yOffset; i <= halfHeight + yOffset; i += increment) {
		DrawRectangle(xOffset, i, halfWidth, 10, BEIGE);
	}
}

void Board::DrawTiles(float width, float height) {
	// Iterate through all tiles
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			// Draw any tiles with a state above 0
			if (tiles[x][y].CheckState() != 0) tiles[x][y].Draw({ width, height }, x, y);
		}
	}
}
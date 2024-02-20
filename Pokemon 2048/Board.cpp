#include "raylib.h"
#include "Board.h"

Board::Board() {
	total = 0;
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			tiles[x][y] = Tile(0);
		}
	}
}

void Board::Shift(int direction) {

}

void Board::Merge() {

}

void Board::NewTile() {

}

void Board::Draw(int height, int width) {

	// Get sizes smaller than screen
	int halfHeight = height * 0.75;
	int halfWidth = width * 0.75;
	int increment = halfWidth / 4;

	// Create offsets to start the board
	int xOffset = (width * 0.1) + 10;
	int yOffset = (height * 0.1) + 10;

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
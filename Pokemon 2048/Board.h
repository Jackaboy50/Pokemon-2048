#pragma once
#include "Tile.h"
class Board {
	public:
		Board();
		void Shift(int direction);
		void Merge();
		void Draw(int height, int width);
		void NewTile();
	private:
		Tile tiles[3][3];
		int total;
};
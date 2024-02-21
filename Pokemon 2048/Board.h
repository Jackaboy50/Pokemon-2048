#pragma once
#include "Tile.h"
class Board {
	public:
		Board();
		void Shift(int direction);
		void Merge();
		void Draw(int width, int height);
		void DrawTiles(float width, float height);
		void NewTile();
	private:
		Tile tiles[4][4];
		int total;
};
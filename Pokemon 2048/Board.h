#pragma once
#include "Tile.h"
class Board {
	public:
		Board();
		void LeftShift();
		void UpShift();
		void DownShift();
		void RightShift();
		void Merge(Vector2 mergedTile, Vector2 mergingTile);
		void ResetMergeFlags();
		void Draw(int width, int height);
		void DrawTiles(float width, float height);
		void NewTile();
	private:
		Tile tiles[4][4];
		int total;
};
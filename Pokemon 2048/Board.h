#pragma once
#include "Tile.h"
class Board final {
	public:
		Board();
		void LeftShift();
		void UpShift();
		void DownShift();
		void RightShift();
		int TotalScore();
		void Restart();

		void Merge(Vector2 mergedTile, Vector2 mergingTile);
		void ResetMergeFlags();
		void Draw(int width, int height, Color gridColour);
		void DrawTiles(float width, float height);
		void NewTile();
		
	private:
		Tile tiles[4][4];
		int total;
};
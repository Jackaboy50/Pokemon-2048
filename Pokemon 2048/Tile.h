#pragma once
class Tile {
	public:
		Tile(int state);
		Tile();
		void IncrementState();
		void ResetState();
		void SetState(int state);
		int CheckState();
		void ResetSize();
		void FlagMerged(bool flag);
		bool HasMerged();
		void SetOffset(float x, float y);
		void Draw(Vector2 screenDimensions, int x, int y);

	private:
		int state;
		bool merged = false;
		float tileSizePercentage = 0.1;
		float tileOffsetPercentage = 1;
		Vector2 tileShiftOffset = { 0, 0 };
		Color colours[10] = {RED, ORANGE, YELLOW, GREEN, SKYBLUE, DARKBLUE, DARKPURPLE, PURPLE, MAGENTA, PINK};
};
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
		void Draw(Vector2 screenDimensions, int x, int y);

	private:
		int state;
		bool merged = false;
		float tileSizePercentage = 0.1;
		Color colours[10] = {RED, ORANGE, YELLOW, GREEN, SKYBLUE, DARKBLUE, DARKPURPLE, PURPLE, MAGENTA, PINK};
};
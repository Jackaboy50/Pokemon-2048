#pragma once
class Tile {
	public:
		Tile(int state);
		Tile();
		void IncrementState();
		void ResetState();
		void SetState(int state);
		int CheckState();
		void Draw(Vector2 screenDimensions, int x, int y);

	private:
		int state;
};
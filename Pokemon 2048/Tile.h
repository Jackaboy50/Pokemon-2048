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
		void SetOffset(int x, int y);
		void Draw(Vector2 screenDimensions, int x, int y);
		void Draw2048(Vector2 screenDimensions, int x, int y);
		void DrawPokemon(Vector2 screenDimensions, int x, int y);


		static void LoadSpriteSheet();
		static void ChangeDrawType() {
			drawType = !drawType;
		}

	private:
		int state;
		bool merged = false;
		static bool drawType;
		double tileSizePercentage = 0.1;
		double tileOffsetPercentage = 1;
		Vector2 tileShiftOffset = { 0, 0 };
		Color colours[12] = {RED, ORANGE, GOLD, LIME, GREEN, SKYBLUE, DARKBLUE, DARKPURPLE, PURPLE, VIOLET, MAGENTA, PINK };
};
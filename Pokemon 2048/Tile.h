#pragma once
class Tile {
	public:
		Tile(int state);
		Tile();
		void ChangeState();
		void CheckState();
		void Draw();

	private:
		int state;
};
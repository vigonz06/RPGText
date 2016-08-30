#ifndef COORD
#define COORD

enum Direction { left = 37, up, right, down };

class Board;

struct Coord
{
	int x; int y;
	Coord(int i = 0, int j = 0) : x(i), y(j) {}
	Coord next(Direction dir, Board board);

	bool operator != (Coord coor){ return x != coor.x || y != coor.y; }
};

#endif//TCOORD

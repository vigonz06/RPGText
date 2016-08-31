#ifndef BOARD
#define BOARD

#include <string>
#include "Lists.h"
#include <fstream>

struct Coord;

enum Box { ULC, URC, LLC, LRC, CF, HL, VL, EMP, ENMY, PLYR };

class Board
{
private:

	Box** board;
	static int dimx, dimy;

public:

	Board();
	Board(const Board &oldBoard);
	~Board();

	static int getDimX() { return dimx; }
	static int getDimY() { return dimy; }

	void create(MapList maps, std::string &id);

	bool load(std::ifstream &file);
	void save(std::ofstream &file);

	Box& operator ()(const int i, const int j) { return board[i][j]; }
	Box& operator [](const Coord coord) { return board[coord.x][coord.y]; }
	Box& operator ()(const int i, const int j) const { return board[i][j]; }
};

#endif

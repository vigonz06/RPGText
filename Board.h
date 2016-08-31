#ifndef BOARD
#define BOARD

#include <string>
#include "Coord.h"
#include <fstream>
#include "BoardList.h"

enum Box { ULC, URC, LLC, LRC, CF, HL, VL, EMP, ENMY, PLYR };

class Board
{
private:

	std::string id;

	Box** board;
	static int dimx, dimy;

public:

	Board() {};
	Board(BoardList boards, std::string &id) { create(boards, id); };

	std::string getId()  { return id; }
	static int getDimX() { return dimx; }
	static int getDimY() { return dimy; }

	void create(BoardList boards, std::string &id);

	bool load(std::ifstream &file);
	void save(std::ofstream &file);

	Box& operator ()(const int i, const int j) { return board[i][j]; }
	Box& operator [](const Coord coord) { return board[coord.x][coord.y]; }
	Box& operator ()(const int i, const int j) const { return board[i][j]; }
};

#endif
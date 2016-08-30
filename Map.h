#ifndef MAP
#define MAP

#include <string>
#include <fstream>

class Boaard;

struct Map
{
	std::string id;
	Board board;

	std::string getId() { return id; }
	Board getBoard() { return board; }

	bool load(std::ifstream &file);
	void save(std::ofstream &file);
};

bool Map::load(std::ifstream &file)
{
	file >> id;

	if (!file.fail())
	{
		if (board.load(file)) return true;

		else return false;
	}
	else return false;
}

void Map::save(std::ofstream &file)
{
	file << id << std::endl;

	board.save(file);

	file << std::endl;
}

#endif
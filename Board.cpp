#include "Board.h"
#include "Coord.h"

struct Map;

int Board::dimx;
int Board::dimy;

bool Board::load(std::ifstream &file)
{
	int box;

	file >> dimx;

	if (!file.fail())
	{
		file >> dimy;

		if (!file.fail())
		{
			for (int i = 0; i < dimy; i++)
			{
				for (int j = 0; j < dimx; j++)
				{
					file >> box;

					if (!file.fail()) board[j][i] = Box(box);

					else return false;
				}
			}
			return true;
		}
		else return false;
	}
	else return false;
}

void Board::save(std::ofstream &file)
{
	file << dimx << dimy << std::endl;

	for (int i = 0; i < dimy; i++)
	{
		for (int j = 0; j < dimx; j++)
		{
			file << board[j][i] << " ";
		}
		file << std::endl;
	}
}

void Board::create(MapList maps, std::string &id)
{
	Board newBoard;

	*this = maps.get(id).getBoard();
}
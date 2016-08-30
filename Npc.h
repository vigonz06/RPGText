#include <string>
#include <fstream>

struct NPC
{
	std::string id;
	int health;
	int power;

	//Coord coord;

	std::string getId() { return id; }

	bool load(std::ifstream &file);
	void save(std::ofstream &file);
};

bool NPC::load(std::ifstream &file)
{
	file >> id;

	if (!file.fail())
	{
		file >> health;

		if (!file.fail())
		{
			file >> power;

			if (file.fail())
			{
				//file >> coord.x;
				//file >> coord.y;

				return true;
			}
			else return false;
		}
		else return false;
	}
	else return false;
}
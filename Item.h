#ifndef ITEM
#define ITEM

#include <string>
#include <fstream>

struct Item
{
	std::string id;
	int HowMany;

	std::string getId() { return id; }

	bool load(std::ifstream &file);
	void save(std::ofstream &file);
};

bool Item::load(std::ifstream &file)
{
	file >> id;

	if (!file.fail())
	{
		file >> HowMany;

		if (file.fail()) return true;

		else return false;
	}
	else return false;
}

void Item::save(std::ofstream &file)
{
	file << id << " " << HowMany << std::endl;
}

#endif
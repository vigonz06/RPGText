#ifndef MENU
#define MENU

#include "List.h"
#include <string>
#include <fstream>

class Menu: public List<std::string>
{
public:

	bool load(std::ifstream &file);
	void save(std::ofstream &file);
};

bool Menu::load(std::ifstream &file)
{
	int n;
	std::string* option;

	file >> n;

	for (int i = 0; i < n; i++)
	{
		option = new std::string;

		file >> *option;
		list[counter++] = option;

		if (file.fail()) return false;
	}
	return true;
}

void Menu::save(std::ofstream &file)
{
	file << counter << std::endl;

	for (int i = 0; i < counter; i++)
	{
		file << *list[i] << std::endl;
	}
}
#endif
#ifndef MENU
#define MENU

#include "OptionList.h"
#include <fstream>
#include <string>

struct Menu
{
	std::string id;
	OptionList* options;

	bool load(std::ifstream &file);
};

bool Menu::load(std::ifstream &file)
{
	file >> id;

	if (file.fail())
	{
		if (options->load(file)) return true;

		else return false;
	}
	else return false;
}

#endif
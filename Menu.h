#ifndef MENU
#define MENU

#include "List.h"
#include <string>
#include <fstream>
#include "OptionList.h"

class Menu
{
public:

	std::string id;
	std::string scentence;
	OptionList options;

	bool load(std::ifstream &file)
	{
		file >> id;

		if (!file.fail())
		{
			file >> scentence;

			if (!file.fail() && options.load(file)) return true;

			else return false;
		}
		else return false;
	}
};

#endif
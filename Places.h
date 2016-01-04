#ifndef PLACES
#define PLACES

#include <string>
#include <fstream>
#include "Menu.h"

struct Places
{
	std::string id;
	std::string descripcion;
	Menu* menu;

	bool load(std::ifstream &file)
	{
		file >> id;

		if (!file.fail())
		{
			file >> descripcion;

			if (!file.fail() && menu->load(file)) return true;

			else return false;
		}
		else return false;
	}
};

#endif

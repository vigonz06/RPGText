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
	int orden;

	bool load(std::ifstream &file)
	{
		file >> id;

		if (!file.fail())
		{
			file >> descripcion;

			if (!file.fail() && menu->load(file))
			{
				file >> orden;

				if (!file.fail()) return true;

				else return false;
			}
			else return false;
		}
		else return false;
	}
};

#endif
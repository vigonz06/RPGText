#ifndef ITEMS
#define ITEMS

//to do David
//le pongo esto de momento, si se te ocurren mas cosas,
//o ves que sobrea el propierties, editalo, pero no olvides
//adaptar la funcion de cargar

#include <string>
#include <fstream>
#include "Globalconstants.h"

struct Item
{
	std::string id;
	std::string descripcion;
	int counter;

	bool load(std::ifstream &file);
	void save(std::ofstream &file);
	bool find();
};

bool Item::load(std::ifstream &file)
{
	std::string line, text = "";

	file >> id;

	if (!file.fail())
	{
		file >> counter;

		if (!file.fail())
		{
			do
			{
				std::getline(file, line);
				text += line + '\n';
			} while (line != "" && !file.fail());

			if (!file.fail())
			{
				descripcion = text;

				return true;
			}
			else return false;
		}
		else return false;
	}
	else return false;
}

void Item::save(std::ofstream &file)
{
	file << id << counter 
		<< std::endl << descripcion 
		<< std::endl << std::endl;
}

bool Item::find()
{
	if (counter < MAX_ITEMS)
	{
		counter++;
		return true;
	}
	else return false;
}

#endif
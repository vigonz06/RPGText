#ifndef ITEMS
#define ITEMS

//to do David
//le pongo esto de momento, si se te ocurren mas cosas,
//o ves que sobrea el propierties, editalo, pero no olvides
//adaptar la funcion de carga

#include <string>
#include <fstream>

struct Item
{
	std::string name;
	bool found;
	std::string properties;

	bool load(std::ifstream &file);
	void find();
};

bool Item::load(std::ifstream &file)
{
	std::string line, text = "";

	std::getline(file, name);

	if (!file.fail())
	{
		file >> found;

		if (!file.fail())
		{
			do
			{
				std::getline(file, line);
				text += line + '\n';
			} while (line != "" && !file.fail());

			if (!file.fail())
			{
				properties = text;

				return true;
			}
			else return false;
		}
		else return false;
	}
	else return false;
}

void Item::find()
{
	if (!found)
	{
		found = true;
	}
}#endif
#ifndef Characters
#define Characters

#include <string>
#include <fstream>
#include "Clase.h"

struct Ataque
{
 	int daño;
	int mana;

	bool load(std::ifstream &file)
	{
		file >> daño;

		if (!file.fail())
		{
			file >> mana;

			if (!file.fail()) return true;

			else return false;
		}
		else return false;
	}

	void save(std::ofstream &file)
	{
		file << daño << " "
			<< mana << std::endl;
	}
};

struct Defensa
{
	int vida;
	int armadura;

	bool load(std::ifstream &file)
	{
		file >> vida;

		if (!file.fail())
		{
			file >> armadura;

			if (!file.fail()) return true;

			else return false;
		}
		else return false;
	}

	void save(std::ofstream &file)
	{
		file << vida << " "
			<< armadura << std::endl;
	}
};

struct Character
{
	std::string id;
	Clase clase;
	Defensa defensa;
	Ataque ataque;
};

#endif

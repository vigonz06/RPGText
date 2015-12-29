#ifndef ARMA
#define ARMA

#include <string>
#include <fstream>

struct Arma
{
	std::string id;
	float mod_daño;
	std::string descripcion;

	bool load(std::ifstream &file)
	{
		file >> id;

		if (!file.fail())
		{
			file >> mod_daño;

			if (!file.fail())
			{
				file >> descripcion;

				if (!file.fail()) return true;

				else return false;
			}
		}
	}
};

#endif

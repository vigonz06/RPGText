#ifndef ATAQUE
#define ATAQUE

#include <string>
#include <fstream>

struct Ataque
{
	std::string id;
	int da�o;
	int consumo;

	bool load(std::ifstream &file)
	{
		file >> id;

		if (!file.fail())
		{
			file >> da�o;

			if (!file.fail())
			{
				file >> consumo;

				if (!file.fail()) return true;

				else return false;
			}
		}
	}
};

#endif
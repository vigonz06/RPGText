#ifndef ARMA
#define ARMA

#include <string>
#include <fstream>

struct Arma
{
	std::string id;
	int municion;
	int mod_daño;
	std::string descripcion;

	bool load(std::ifstream &file);
	void save(std::ofstream &file);
};

bool Arma::load(std::ifstream &file)
{
	std::string line, text = "";

	file >> id;

	if (!file.fail())
	{
		file >> municion;

		if (!file.fail())
		{
			file >> mod_daño;

			if (!file.fail())
			{
				do
				{
					std::getline(file, line);
					text += line + '\n';
				} while (line != "" && !file.fail());

				descripcion = text;

				if (!file.fail()) return true;

				else return false;
			}
			else return false;
		}
		else return false;
	}
	else return false;
}

void Arma::save(std::ofstream &file)
{
	file << id << " " << mod_daño
		<< std::endl << descripcion
		<< std::endl << std::endl;
}

#endif

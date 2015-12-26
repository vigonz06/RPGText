#ifndef CLASE
#define CLASE

#include <string>
#include <fstream>

struct Clase
{
	std::string id;
	std::string descripcion;

	bool load(std::ifstream &file);
	void save(std::ofstream &file);
};

bool Clase::load(std::ifstream &file)
{
	std::string line, text = "";

	file >> id;

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

void Clase::save(std::ofstream &file)
{
	file << id << std::endl
		<< descripcion << std::endl
		<< std::endl;
}

#endif

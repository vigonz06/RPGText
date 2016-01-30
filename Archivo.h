#ifndef ARCHIVO
#define ARCHIVO

#include <string>
#include <fstream>

bool get(std::ifstream &file, std::string scentinel)
{
	std::string ignore = "";

	while (ignore != scentinel && !file.eof())
	{
		std::getline(file, ignore);
	}

	if (ignore == scentinel) return true;

	else return false;
}

std::string put(std::ifstream &file, std::string scentinel)
{
	std::string linea;
	std::string texto = "";

	if (get(file, scentinel))
	{
		do
		{
			std::getline(file, linea);

			if (linea != "") texto += linea;

		} while (linea != "" && file.eof());

		file.close();

		return texto;
	}
	else
	{
		file.close();

		return "Text not found";
	}
}

std::string find(std::string scentinel, std::string filename)
{
	std::ifstream file;

	file.open(filename);

	if (file.is_open())
	{
		return put(file, scentinel);
	}
	else return "File not found";
}

#endif
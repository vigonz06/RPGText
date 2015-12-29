#ifndef CLASE
#define CLASE

#include <string>
#include <fstream>
#include "ListaAtaque.h"
#include "ListaArmas.h"

struct Clase
{
	std::string id;
	std::string descripcion;
	ListaArmas armas;
	ListaAtaque ataques;

	bool load(std::ifstream &file)
	{
		file >> id;

		if (!file.fail())
		{
			file >> descripcion;

			if (!file.fail() && armas.load(file) && ataques.load(file)) return true;

			else return false;
		}
	}
};

#endif

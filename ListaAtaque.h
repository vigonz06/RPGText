#ifndef LISTAATAQUE
#define LISTAATAQUE

#include "List.h"
#include "Ataque.h"
#include <fstream>

class ListaAtaque : public List<Ataque> 
{
public:

	bool load(std::ifstream &file)
	{
		int n;
		Ataque* nuevo;

		file >> n;

		for (int i = 0; i < n; i++)
		{
			nuevo = new Ataque;

			if (!nuevo->load(file))
			{
				delete nuevo;

				return false;
			}
			else insert(nuevo);
		}
		return true;
	}
};

#endif
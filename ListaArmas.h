#ifndef LISTAARMAS
#define LISTAARMAS

#include "List.h"
#include "Arma.h"
#include <fstream>

class ListaArmas : public List<Arma> 
{
public:

	bool load(std::ifstream &file)
	{
		int n;
		Arma* nuevo;

		file >> n;

		for (int i = 0; i < n; i++)
		{
			nuevo = new Arma;

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
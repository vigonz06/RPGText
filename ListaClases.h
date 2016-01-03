#ifndef LISTACLASES
#define LISTACLASES

#include "List.h"
#include "Clase.h"
#include <string>
#include "GraphInter.h"

class ListaClases : public List<Clase> 
{
public:

	Clase elegir()
	{
		int choose;
		int i = 0, k = 0;
		std::string* options;

		for (int j = 0; j < counter; j++)
		{
			if (list[j]->player)
			{
				i++;
			}
		}

		options = new std::string[i];

		for (int j = 0; j < counter; j++)
		{
			if (list[j]->player)
			{
				options[k] = list[j]->id;
				k++;
			}
		}

		choose = GraphInter::get()->menu(options, i, "Choose your class");

		return *get(options[choose]);
	}
};

#endif
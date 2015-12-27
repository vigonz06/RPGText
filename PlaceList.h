#ifndef PLACELIST
#define PLACELIST

#include "List.h"
#include "Places.h"

class PlaceList : public List<Places> 
{
public:

	Places* buscar(int orden)
	{
		Places* searched = new Places;

		for (int i = 0; i < counter; i++)
		{
			if (list[i]->orden == orden)
			{
				searched = list[i];

				return searched;
			}
		}
		delete searched;

		return nullptr;
	}
};

#endif

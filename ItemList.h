#ifndef ITEMLIST
#define ITEMLIST

#include "List.h"
#include "Items.h"
#include <fstream>

class ItemList: public List<Item> 
{
public:

	bool load(std::ifstream &file)
	{
		Item* nuevo;
		int n;

		file >> n;

		if (!file.fail())
		{
			for (int i = 0; i < n; i++)
			{
				nuevo = new Item;

				if (!nuevo->load(file))
				{
					delete nuevo;

					return false;
				}
				else insert(nuevo);
			}
			return true;
		}
		else return false;
	}

	void save(std::ofstream &file)
	{
		file << counter;

		for (int i = 0; i < counter; i++)
		{
			list[i]->save(file);
		}
	}
};

#endif

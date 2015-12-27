#ifndef PLACES
#define PLACES

#include <string>
#include <fstream>
#include "Menu.h"

struct Places
{
	std::string id;
	std::string descripcion;
	Menu* menu;
	int orden;
};

#endif

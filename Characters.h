#ifndef Characters
#define Characters

#include <string>
#include <fstream>
#include "Clase.h"

struct Character
{
	std::string id;
	Clase clase;
	int vida, daño, armadura, consumibles;
};

#endif

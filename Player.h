#ifndef PLAYER
#define PLAYER

#include "Characters.h"
#include "Arma.h"

struct Objeto
{
	std::string id;
	std::string tipo;
	std::string descripcion;
	int num_objetos//limitar un maximo

};

struct Player : public Character
{
	Arma arma_equipada;
	//inventario

};

#endif

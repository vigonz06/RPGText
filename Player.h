#ifndef PLAYER
#define PLAYER

#include "Arma.h"
#include <fstream>
#include "Characters.h"

typedef enum Prendas { Casco, Pechera, Capa, Pantalones, Botas };

//to do Victor
//lista de tipos
//compartimentar
 struct Ropa
 {
 	Prendas prenda;
 	std::string id;
 	std::string descripcion;
 	int mejora;
 };

struct Player : public Character
{
	Ropa ropas;


};

#endif

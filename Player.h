#ifndef PLAYER
#define PLAYER

#include "Characters.h"
#include "Arma.h"

struct Player : public Character
{
	Arma arma_equipada;

};

#endif

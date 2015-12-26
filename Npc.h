#ifndef NPC
#define NPC

#include "Characters.h"

typedef enum Dificultad
{
	Facil,
	Medio,
	Dificil
};

struct NPC : public Character
{
	//to do David
	//caracteristicas individuales de los npc

	Dificultad dificultad;

	void init(); //la inicializacion dependera de la dificultad
};

#endif
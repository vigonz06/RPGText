#ifndef NPC
#define NPC

#include "Characters.h"

typedef enum Dificultad
{
	Facil,
	Medio,
	Dificil
};

struct Npc : public Character
{
	//to do David
	//caracteristicas individuales de los npc

	Dificultad dificultad;
	string tipe;

	void init(); //la inicializacion dependera de la dificultad
};

#endif

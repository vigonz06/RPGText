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
	Dificultad dificultad;

	void init();
};

#endif

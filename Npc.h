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
	int daño;

	void init()
	{
		switch (dificultad)
		{
		case Facil:

			daño = 50;
			vida = 50;
			armadura = 0;
			consumibles = 0;

		case Medio:

			daño = 100;
			vida = 100;
			armadura = 50;
			consumibles = 5;

		case Dificil:

			daño = 150;
			vida = 150;
			armadura = 100;
			consumibles = 10;
		}
	}
};

#endif

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
	int da�o;

	void init()
	{
		switch (dificultad)
		{
		case Facil:

			da�o = 50;
			vida = 50;
			armadura = 0;
			consumibles = 0;

		case Medio:

			da�o = 100;
			vida = 100;
			armadura = 50;
			consumibles = 5;

		case Dificil:

			da�o = 150;
			vida = 150;
			armadura = 100;
			consumibles = 10;
		}
	}
};

#endif

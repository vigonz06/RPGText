#ifndef Personajes
#define Personajes

#include <string>

struct Personaje
{
	std::string name; //evidente que ambos van a tener nombres

	//to do David
	//caracteristicas comunes 
	//tanto de los npc como del personaje
	//salud, daño, mana, etc (lo que quieras que tengan,
	//pero recuerda, solo lo que sea comun a ambos)

	//para que entiendas la herencia:
	//ahora no hace falta declarar la variable name ni en
	//personaje ni en npc, ya que al ser esta una structura 
	//base de ambos, dicha variable pasa a ser de ellos
};

struct NPC: public Personaje
{
	//to do David
	//caracteristicas individuales de los npc
};

struct Jugador: public Personaje
{
	//to do David
	//caracteristicas individuales del jugador
};

#endif
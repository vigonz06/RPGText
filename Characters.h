#ifndef Characters
#define Characters

#include <string>

struct Character
{
	std::string id; //evidente que ambos van a tener nombres

	//to do David
	//caracteristicas comunes 
	//tanto de los npc como del personaje
	//salud, da�o, mana, etc (lo que quieras que tengan,
	//pero recuerda, solo lo que sea comun a ambos)

	//para que entiendas la herencia:
	//ahora no hace falta declarar la variable name ni en
	//personaje ni en npc, ya que al ser esta una structura 
	//base de ambos, dicha variable pasa a ser de ellos
};

#endif
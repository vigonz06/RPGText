#ifndef Characters
#define Characters

#include <string>

//Si vas a hacer una estructura de ataque, con daño, municion, mana, defensa, magie, etc...
//supongo que sera comun tanto para el personaje como para los npc, por tanto ponla aqui, 
//encima de la struct characters

/*struct Ataque
{
	//por ejemplo
};*/

struct Character
{
	std::string id; //evidente que ambos van a tener nombres

	//to do David
	//caracteristicas comunes 
	//tanto de los npc como del personaje
	//salud, daño, mana, etc (lo que quieras que tengan,
	//pero recuerda, solo lo que sea comun a ambos)

	//para que entiendas la herencia:
	//ahora no hace falta declarar la variable id ni en
	//personaje ni en npc, ya que al ser esta una structura 
	//base de ambos, dicha variable pasa a ser de ellos
};

#endif
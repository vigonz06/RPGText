#ifndef Characters
#define Characters

#include <string>

//Si vas a hacer una estructura de ataque, con daño, municion, mana, defensa, magie, etc...
//supongo que sera comun tanto para el personaje como para los npc, por tanto ponla aqui, 
//encima de la struct characters

struct Ataque
{
 	int danio;
	int mana;
	int municion;

};

struct Character
{
	std::string id; //evidente que ambos van a tener nombres

	string nombre;
	string clase;
	int vida;
	int mana;
	int municion;
	int armadura;
};

#endif

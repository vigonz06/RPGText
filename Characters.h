#ifndef Characters
#define Characters

#include <string>
#include <fstream>
#include "Clase.h"

//Si vas a hacer una estructura de ataque, con daño, municion, mana, defensa, magie, etc...
//supongo que sera comun tanto para el personaje como para los npc, por tanto ponla aqui, 
//encima de la struct characters

struct Ataque
{
 	int daño; //las variables si pueden contener caracteres tales como la ñ
	int mana;

	bool load(std::ifstream &file)
	{
		file >> daño;

		if (!file.fail())
		{
			file >> mana;

			if (!file.fail()) return true;

			else return false;
		}
		else return false;
	}

	void save(std::ofstream &file)
	{
		file << daño << " "
			<< mana << std::endl;
	}
};

struct Defensa
{
	int vida;
	int armadura;

	bool load(std::ifstream &file)
	{
		file >> vida;

		if (!file.fail())
		{
			file >> armadura;

			if (!file.fail()) return true;

			else return false;
		}
		else return false;
	}

	void save(std::ofstream &file)
	{
		file << vida << " "
			<< armadura << std::endl;
	}
};

struct Character
{
	std::string id; //el id es el nombre, hay que poner id ya que todas las structs deben tener el mismo identificador, por temas de la lista base
	Clase clase;
	//hay que poner std:: delante de todo lo que te lo pida, ya que como trabajamos con varios archivos, no usamos el "using"
	//std::string clase; para la clase hay que hacer una struct
	Defensa defensa;
	Ataque ataque; //como el ataque engloba esas tres cosas, ponemos un objeto de este tipo, y lo tenemos englobado
};

#endif

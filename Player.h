#ifndef PLAYER
#define PLAYER

#include "Arma.h"
#include <fstream>
#include "ItemList.h"
#include "Characters.h"


struct Player : public Character
{
	Arma arma_equipada;
	ItemList inventario;

	bool load();
	void save();
};

bool Player::load()
{
	std::ifstream file;

	file.open("Player.txt");

	if (file.is_open());
	{
		file >> id;

		if (!file.fail() && clase.load(file) && defensa.load(file) && ataque.load(file) && arma_equipada.load(file) && inventario.load(file)) return true;

		else return false;
	}
}

void Player::save()
{
	std::ofstream file;

	file.open("Player.txt");

	file << id << std::endl;

	defensa.save(file);
	ataque.save(file);
	arma_equipada.save(file);
	inventario.save(file);
}

#endif

#ifndef COMBAT
#define COMBAT

#include "Characters.h"
#include "MenuList.h"
#include "Player.h"
#include "Npc.h"

//to do David
//to do Victor

//ve poniendo las funciones de combate, y luego las pulimos entre los dos
//de esas dos funciones que ves ahi te hablare mas adelante, de momento 
//me encargo yo de ellas, tu no las toques

class Combat
{
public:

	static Combat* get();

	void fight(Npc &actual, Player* player, MenuList* menus);

private:

	Combat() {};

	static Combat* combat;

	void fightkind(std::string &id, Player* player);

	void player_fight(Npc &actual, Player* player, MenuList* menus);
	void npc_fight(Npc &actual, Player* player);

	void quitar_salud_npc(Npc &actual, int daño);
	void quitar_salud_jugador(int daño, Player* player);
	
	bool comprobar_ataque(int consumible, int comsumido);
	bool comprobar_vivo(int salud);
};

#endif
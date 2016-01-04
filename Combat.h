#ifndef COMBAT
#define COMBAT

#include "Characters.h"
#include "MenuList.h"
#include "Player.h"
#include "Npc.h"

class Combat
{
public:

	static Combat* get();
	static void load();
	static void close();

	void fight(Npc &actual, Player* player);

private:

	Combat() {};

	static Combat* combat;

	void fightkind(std::string &id, Player* player);

	void player_fight(Npc &actual, Player* player);
	void npc_fight(Npc &actual, Player* player);

	void quitar_salud_jugador(int daño, Player* player);
	void quitar_salud_npc(Npc &actual, int daño);
	
	bool comprobar_ataque(int consumible, int comsumido);
	bool comprobar_vivo(int salud);
};

#endif
#include "Combat.h"
#include "Player.h"
#include "MenuList.h"
#include "GraphInter.h"

Combat* Combat::combat = nullptr;

Combat* Combat::get()
{
	return combat;
}

void Combat::load()
{
	if (combat == nullptr)
	{
		combat = new Combat;
	}
}

void Combat::close()
{
	if (combat != nullptr)
	{
		delete combat;
		combat = nullptr;
	}
}

void Combat::player_fight(Npc &actual, Player* player)
{
	std::string* options = new std::string[player->clase.ataques.length()];
	int opcion;

	for (int i = 0; i < player->clase.ataques.length(); i++)
	{
		options[i] = player->clase.ataques.operator[](i)->id;
	}

	opcion = GraphInter::get()->menu(options, player->clase.ataques.length(), "Choose your attack:");

	if (comprobar_ataque(player->consumibles, player->clase.ataques.operator[](opcion)->consumo))
	{
		quitar_salud_npc(actual, player->clase.ataques.operator[](opcion)->daño);
		player->consumibles -= player->clase.ataques.operator[](opcion)->consumo;
	}
	delete[] options;
	options = nullptr;
}
	
bool Combat::comprobar_ataque(int consumible, int consumido)
{
	if (consumible >= consumido) return true;

	else return false;
}

void Combat::quitar_salud_npc(Npc &actual, int daño)
{
	if (actual.armadura >= daño) actual.armadura -= daño;

	else
	{
		actual.vida -= (daño - actual.armadura);

		actual.armadura = 0;
	}
}

void Combat::quitar_salud_jugador(int daño, Player* player)
{
	if (player->armadura >= daño) player->armadura -= daño;

	else
	{
		player->vida -= (daño - player->armadura);

		player->armadura = 0;
	}
}

void Combat::npc_fight(Npc &actual, Player* player)
{

    int opcion;
    opcion = (rand() % 2) + 1;

	if (comprobar_ataque(actual.consumibles, actual.clase.ataques.operator[](opcion)->consumo))
	{
		quitar_salud_jugador(actual.clase.ataques.operator[](opcion)->daño, player);
		actual.consumibles -= actual.clase.ataques.operator[](opcion)->consumo;
	}
}

bool Combat::comprobar_vivo(int vida)
{

    if(vida <= 0) return false;

    else return true;
}

void Combat::fight(Npc &actual, Player* player)
{
    bool continuar = true;

    do{
        if(comprobar_vivo(player->vida))
		{
            player_fight(actual, player);
        }
		else
		{
            continuar = false;
        }
        if(comprobar_vivo(actual.vida))
		{
			npc_fight(actual, player);
        }
		else
		{
            continuar = false;
        }

        //IMPRIMIR DATOS DE COMBATE
        //MEJORAR
		GraphInter::get()->display("vida de " + player->id + ": " + std::to_string(player->vida));
		GraphInter::get()->display("");
        GraphInter::get()->display("vida de " + actual.id + ": " + std::to_string(actual.vida));
		GraphInter::get()->pause();
		GraphInter::get()->clearConsole();

    }while(continuar);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void bienvenida ()
{

}

std::string pregunta_nombre()
{

    std::string nombre;

    GraphInter::get()->display("Como te llamas? ");

	GraphInter::get()->enter(nombre);

    return nombre;
}

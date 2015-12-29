#include "Combat.h"
#include "Player.h"
#include "MenuList.h"
#include "GraphInter.h"

void Combat::fightkind(std::string &id, Player* player)
{
	id += player->clase.id;
}

void Combat::player_fight(Npc &actual, Player* player, MenuList* menus)
{
	std::string id = "ataque_";
	int opcion;

	fightkind(id, player);

	opcion = GraphInter::get()->menu(menus->get(id));

	if (comprobar_ataque(player->consumibles, player->clase.ataques.operator[](opcion)->consumo))
	{
		quitar_salud_npc(actual, player->clase.ataques.operator[](opcion)->daño);
		player->consumibles -= player->clase.ataques.operator[](opcion)->consumo;
	}
		//aqui irian los ajustes del daño y el consumo
	
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
		actual.armadura = 0;

		actual.vida -= (daño - actual.armadura);
	}
}

void Combat::quitar_salud_jugador(int daño, Player* player)
{
	if (player->armadura >= daño) player->armadura -= daño;

	else
	{
		player->armadura = 0;

		player->vida -= (daño - player->armadura);
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

void Combat::fight(Npc &actual, Player* player, MenuList* menus)
{
    bool continuar = true;

    do{
        if(comprobar_vivo(player->vida))
		{
            player_fight(actual, player, menus);
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

/*std::string eleccion_personaje(std::string nombre)
{
    vector<string> opciones = {"mago", "guerrero", "ladron"};
    string clase;



    cout << "\nDime noble " << nombre << " que clase de aventurero eres?" << endl;
    cout << "\n\t\t    Guerrero        Mago         Ladron"<< endl;
    cout << "\tVida:       200 PS          75 PS        150 PS" << endl;
    cout << "\tMana:       100 PM          200 PM       100 PM" << endl;
    cout << "\tArma:       Espadazo        Hechizo      Flecha" << endl;

    do
    {
        cout << "\nEres guerrero, mago o ladron ?" << endl;
        clase = recoger_string(opciones);
        if (clase == "mago")
        {
            cout << "\nHas elegido mago" << endl;
            return "mago";
        }
        else if (clase == "guerrero")
        {
            cout << "\nHas elegido guerrero" << endl;
            return "guerrero";
        }
        else if (clase == "ladron")
        {
            cout << "\nHas elegido ladron" << endl;
            return "ladron";
        }
    }
    while(clase != "mago" || clase != "guerrero" || clase != "ladron");

    return clase;
}

int recoger_int(vector<int> opciones)
{

    int opcion;
    bool coincidencia = false;

    do
    {
        do
        {
            cin >> opcion;
            void clear_the_mess();
            if(opcion == error)
            {
                cout << "dato incorrecto, vuelve a intentarlo" << endl;
            }
        }
        while(opcion == error);

        for(unsigned int i = 0; i < opciones.size(); i++)
        {
            if(opcion == opciones[i])
            {
                coincidencia = true;
            }
        }
    }
    while(coincidencia != true);

    return opcion;
}

string recoger_string(vector<string> opciones)
{

    string opcion;
    bool coincidencia = false;
    do
    {

        cin >> opcion;

        for(unsigned int i = 0; i < opciones.size(); i++)
        {
            if(opcion == opciones[i])
            {
                coincidencia = true;
            }
        }
        if(coincidencia != true){
            cout << "dato incorrecto, vuelve a intentarlo" << endl;
        }
    } while(coincidencia != true);

    return opcion;
}
*/
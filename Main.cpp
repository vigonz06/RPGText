#include "GraphInter.h"
#include "PlaceList.h"
#include "Player.h"


#include <iostream>
#include "Archivo.h"

void bienvenida(Player * player)
{
    //rellena los campos player id y clase id
    //todo rellenar mas campos player y clase
    std::cout << find("id_bienvenida_nombre") << std::endl;
    std::cin >>  player->id;
    std::cout << "\n" <<find("id_bienvenida_clase_1") << player->id << find("id_bienvenida_clase_2") << std::endl;
    std::cin >>  player->clase.id;
    std::cout << find("id_bienvenida_final") << std::endl;
    std::string centinela_clase= "clase_" + player->clase.id;
    player->clase.descripcion = find(centinela_clase);

}

void main()
{
	
}

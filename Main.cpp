#include "GraphInter.h"
#include "PlaceList.h"
#include "Player.h"

#include "list.h"
#include "quest.h"
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

int main()
{
    Character enti("test");
    Character yupti("tast");

    enti.addQuest("q_bandidos");
    enti.addQuest("q_veneno");

    enti.setAvaiable("q_veneno");

    if(enti.getAvaiable("q_bandidos")){
        yupti.addQuest("q_bandidos");
    }
    else{
        std::cout << "q_bandidos no avaiable";
    }


    if(enti.getAvaiable("q_veneno")){
        yupti.addQuest("q_veneno");
    }
    else{
        std::cout << "q_veneno no avaiable";
    }

    yupti.printQuestList();


    return 0;
}

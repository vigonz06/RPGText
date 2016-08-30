<<<<<<< HEAD
=======
#include "GraphInter.h"
#include "PlaceList.h"
#include "Player.h"

#include "list.h"
#include "quest.h"
>>>>>>> origin/master
#include <iostream>

int main()
{
<<<<<<< HEAD
	return 0;
}
=======
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
>>>>>>> origin/master

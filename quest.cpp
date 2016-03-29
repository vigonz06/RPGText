#include <iostream>
#include "quest.h"
#include "archivo.h"


Quest::Quest()
{
    id = "DEFAULT";
    description = "DEFAULT";
    avaiable = false;
    completed = false;
}
Quest::Quest(const std::string id)
{
    this->id = id;
    description = find(id, "quest.txt");
    avaiable = false;
    completed = false;
}
Quest::~Quest()
{
}
void Quest::printQuest()
{
    std::cout << "Quest name: " << id << std::endl;
    std::cout << "Quest description: " << description<< std::endl << std::endl << std::endl;
}
void Quest::readQuest(){
    description = find(id, "quest.txt");
}

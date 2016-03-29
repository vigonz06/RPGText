#include <iostream>
#include "character.h"
#include "list.h"

Character::Character()
{
    //m_questlist = nullptr;
    this->id = "DEFAULT";
}
Character::Character(const std::string id)
{
    this->id = id;
}

Character::~Character()
{
}

void Character::addQuest(std::string id)
{
    Quest *quest = createQuest(id);
    quest->setId(id);
    pushback(quest);
}

Quest* Character::createQuest(std::string id)
{
    Quest *quest = new Quest(id);
    return quest;
}

void Character::printQuestList()
{
    std::cout << "\nQUEST LIST\n\n";
    Quest *quest = nullptr;

    for(int i = 0; i < HowMany(); i++)
    {
        quest = returnElement(i);
        std::cout << "Quest number " << i << std::endl << std::endl;
        quest->printQuest();
    }
}

Quest *Character::giveQuest(std::string id)
{
    Quest *quest = search(id);
    if(quest != nullptr && quest->getAvaiable())
    {
        std::cout << "here u go";
        return quest;
    }
    else
    {
        std::cout << "nope";
    }
    return nullptr;
}

void Character::finishQuest(std::string id)
{
    Quest *quest = search(id);
    if(quest != nullptr && quest->getCompleted())
    {
        std::cout << "u hero";
    }
    else
    {
        std::cout << "nope";
    }
}

void Character::setCompleted(std::string id)
{
    Quest *quest =search(id);
    if(quest != nullptr)
    {
        quest->setCompleted(true);
    }
    else
    {
        std::cout << "problemo";
    }
}

void Character::setAvaiable(std::string id)
{
    Quest *quest = search(id);
    if(quest != nullptr)
    {
        quest->setAvaiable(true);
    }
    else
    {
        std::cout << "problemo";
    }
}

bool Character::getCompleted(std::string id){
    if(search(id)->getCompleted()){
        return true;
    }
    return false;
}
bool Character::getAvaiable(std::string id){
    if(search(id)->getAvaiable()){
        return true;
    }
    return false;
}

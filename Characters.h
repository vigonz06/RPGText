#ifndef CHARACTER_H
#define CHARACTER_H
#include "quest.h"
#include "list.h"
#include "Clase.h"


class Character: public List<Quest>
{
    std::string id;
	Clase clase;
	int vida, daño, armadura, consumibles;


public:
    Character();
    Character(const std::string id);
    ~Character();
    void setId(const std::string id)
    {
        this->id = id;
    }
    std::string getId()
    {
        return id;
    }
    void addQuest(std::string id);
    Quest* createQuest(std::string id);
    void printQuestList();
    Quest *giveQuest(std::string id);
    void finishQuest(std::string id);
    void setCompleted(std::string id);
    void setAvaiable(std::string id);
    bool getCompleted(std::string id);
    bool getAvaiable(std::string id);

//    void readQuestList(){m_questlist->readQuestList();}

//    void setQuestList(QuestList *questlist){m_questlist = questlist;}
};

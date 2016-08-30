#ifndef LISTS
#define LISTS

#include "MainList.h"
#include "Item.h"
#include "NPC.h"
#include "Map.h"

class NPCList : public List<Npc> {};

class MapList : public List<Map> {};

class ItemList : public List<Item> {};

#endif
#include "Entity.h"

#ifndef _ITEM_
#define _ITEM_

#define NUM_ITEMS 2

enum ItemType{
	WEAPON,
	ARMOUR,
	OTHER
};
enum ItemPlace{
	EQUIPPED,
	INVENTORY,
	FLOOR
};

class Item :public Entity{
public:
	Item(){}
	Item(const char* n, const char* d, Room* position, int val, int b_chance, ItemType t, ItemPlace p) :Entity(n, d) {
		item_position = position;
		value = val;
		block_chance = b_chance;
		type = t;
		place = p;
	}
	Room* item_position = nullptr;
	int value;
	int block_chance;
	ItemType type;
	ItemPlace place;

};

#endif //_ITEM_
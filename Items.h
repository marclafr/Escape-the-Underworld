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
	//void Look();
	Item(const char* n, const char* d, Room* position, int val, ItemType t, ItemPlace p) :Entity(n, d) {
		item_position = position;
		value = val;
		type = t;
		place = p;
	}
	Room* item_position = nullptr;
	int value;
	ItemType type;
	ItemPlace place;

};

#endif //_ITEM_
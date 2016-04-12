#include "Entity.h"

#ifndef _ITEM_
#define _ITEM_

#define NUM_ITEMS 10

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
	void Look();
	int value;
	Room* item_position = nullptr;
	ItemType item_type;
	ItemPlace item_place;
};

#endif //_ITEM_
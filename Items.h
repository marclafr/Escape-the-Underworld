#include "Entity.h"

#ifndef _ITEM_
#define _ITEM_

#define NUM_ITEMS 9
#define NUM_1_WORD_ITEMS 6
#define NUM_2_WORD_ITEMS 3
#define NUM_INVENTORY_SLOTS 10

enum ItemType{
	WEAPON,
	ARMOUR,
	SHIELD,
	OTHER
};
enum ItemPlace{
	EQUIPPED,
	INVENTORY,
	FLOOR
};
enum Union{
	FUSABLE1,	//	as the union of items shall be unidirectional, I decided to define 2 kinds of items:
	FUSABLE2,	//	the ones that can allocate items(FUSABLE2) and the ones that can be allocated into others(FUSABLE1).
	UNFUSABLE,
	FUSED		//	FUSED is needed in order to not put something indefinetly into something other
};

class Item :public Entity{
public:
	Item(){}
	Item(const char* n, const char* d, Room* position, int val, int val2, ItemType t, ItemPlace p, Union f) :Entity(n, d) {
		item_position = position;
		value = val;		//attack for WEAPONS, defense for ARMOURS, capacity for quiver, and quantity for arrows (and damage?).
		value2 = val2;		//block chance for WEAPONS && ARMOURS.
		type = t;
		place = p;
		fuse = f;
	}
	Room* item_position = nullptr;
	int value;
	int value2;
	ItemType type;
	ItemPlace place;
	Union fuse;

};

#endif //_ITEM_
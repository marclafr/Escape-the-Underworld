#include "Entity.h"

#ifndef _ITEM_
#define _ITEM_

#define NUM_ITEMS 17
#define NUM_1_WORD_ITEMS 7
#define NUM_2_WORD_ITEMS 10
#define NUM_INVENTORY_SLOTS 10
#define MAX_STATUES_ACTIVATED 2

enum ItemType{
	WEAPON,
	ARMOUR,
	SHIELD,
	STATUE,
	OTHER
};
enum ItemPlace{
	EQUIPPED,
	INVENTORY,
	FLOOR,
	STORE,
	DISAPPEARED	//only for statues, make them disappear from the map.
};
enum Union{
	FUSABLE1,	//	as the union of items shall be unidirectional, I decided to define 2 kinds of items:
	FUSABLE2,	//	the ones that can allocate items(FUSABLE2) and the ones that can be allocated into others(FUSABLE1).
	UNFUSABLE,
	FUSED		//	FUSED is needed in order to not put something indefinetly into something other
};

enum StatuesState{	//special feature: statues:
	ACTIVATED,		//they have 2 states, activated or desactivated
	DESACTIVATED,
	DESTROYED,		//some statues only can be used once
	UNACTIVABLE		//the rest of items won't be activable
};

enum Upgrade{
	UPGRADED,
	REGULAR
};



class Item :public Entity{
public:
	Item(const char* n, const char* d, uint val, uint val2, uint price, ItemType t, ItemPlace p, Union f, StatuesState s, Upgrade upgr) 
		:Entity(ITEM, n, d), value(val), value2(val2), price(price), item_type(t), place(p), fuse(f), state(s), upgrade(upgr) {}
	uint value;
	uint value2;
	uint price;
	ItemType item_type;
	ItemPlace place;
	Union fuse;
	StatuesState state;
	Upgrade upgrade;

	bool PickItem(Vector<String> &tokens, int &InventorySlots);
	void LookInventory(int &InventorySlots)const;
	bool DropItem(Vector<String> &tokens, int &InventorySlots);
	void LookItem(Vector<String> &tokens)const;
	bool EquipItem(Vector<String> &tokens, int &WeaponCounter, int &ArmourCounter, int &ShieldCounter, int &QuiverCapacityCounter);
	bool UnequipItem(Vector<String> &tokens, int &WeaponCounter, int &ArmourCounter, int &ShieldCounter);
	void FuseItems(Vector<String> &tokens, int &InventoryCapacity, int &QuiverCapacityCounter);
	void UnfuseItems(Vector<String> &tokens, int &InventoryCapacity, int &QuiverCapacityCounter)const;
	bool ActivateStatue(Vector<String> &tokens, int &ActiveStatues, int &InventorySlots);
	bool DesactivateStatue(Vector<String> &tokens, int &ActiveStatues);
};

#endif //_ITEM_
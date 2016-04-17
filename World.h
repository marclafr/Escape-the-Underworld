

#ifndef WORLD
#define WORLD

#include <stdio.h>
#include "Exits.h"
#include "Player.h"
#include "Rooms.h"
#include "Chain.h"
#include "Entity.h"
#include "Items.h"
#include "Vector.h"

class World{
public:
	String command;
	Vector <Room*> rooms;
	Vector<Item*> items;
	Vector<Exit*> exits;
	Player player;
	void CreateWorld();
	bool ExitGame()const;
	bool Move(int CommandDir);
	bool LookDirection(int CommandDir, Vector<String> tokens)const;
	void Look()const;
	Vector<String> item_tokens;
	bool PickItem(Vector<String> tokens, int &InventorySlots, unsigned int num_words);
	bool LookInventory(int &InventorySlots)const;
	bool DropItem(Vector<String> tokens, int &InventorySlots, unsigned int num_words);
	void LookItem(String item, unsigned int num_words)const;
	bool EquipItem(Vector<String> tokens, int &WeaponCounter, int &ArmourCounter, unsigned int num_words);
	void UnequipItem(Vector<String> tokens, int &WeaponCounter, int &ArmourCounter, unsigned int num_words);
	int GetDirection(String command, Vector<String> tokens)const;
	int GetDirection(String command)const;
	void CloseGate(int CommandDir)const;
	void OpenGate(int CommandDir)const;
	void FuseItems(Vector<String> tokens, int &QuiverCapacityCounter)const;
	void Stats()const;
private:	
	bool WayClear(int i)const;	
};

#endif //WORLD
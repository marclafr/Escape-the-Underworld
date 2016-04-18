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
	World(){}
	~World(){
		for (int i = 0; i < NUM_ROOMS; i++){
			delete rooms[i];
		}
		for (int i = 0; i < NUM_EXITS; i++){
			delete exits[i];
		}
		for (int i = 0; i < NUM_ITEMS; i++){
			delete items[i];
		}
	}
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
	void LookItem(String item_w1)const;						//items with 1 word
	void LookItem(String item_w1, String item_w2)const;		//items with 2 words
	bool EquipItem(Vector<String> tokens, int &WeaponCounter, int &ArmourCounter, int &ShieldCounter, int &QuiverCapacityCounter, unsigned int num_words);
	bool UnequipItem(Vector<String> tokens, int &WeaponCounter, int &ArmourCounter, int &ShieldCounter, unsigned int num_words);
	int GetDirection(String command, Vector<String> tokens)const;
	int GetDirection(String command)const;
	void CloseGate(int CommandDir)const;
	void OpenGate(int CommandDir)const;
	void FuseItems(Vector<String> tokens, int &InventoryCapacity, int &QuiverCapacityCounter)const;
	void UnfuseItems(Vector<String> tokens, int &InventoryCapacity, int &QuiverCapacityCounter)const;
	bool ActivateStatue(Vector<String> tokens, int &ActiveStatues, int &InventorySlots);
	void Stats()const;
private:	
	bool WayClear(int i)const;	
};

#endif //WORLD
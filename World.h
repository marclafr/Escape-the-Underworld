

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
	//Room* rooms = nullptr;
	//Player* player = nullptr;
	//Exit* exit = nullptr;
	String command;
	//Item* item;
	Vector <Room*> rooms;
	Vector<Item*> items;
	Vector<Exit*> exits;
	Player player;
	void CreateWorld();
	bool ExitGame()const;
	bool Move(int CommandDir);
	bool LookDirection(int CommandDir)const;
	void Look()const;
	bool PickItem()const;
	bool LookInventory()const;
	bool DropItem()const;
	int GetDirection(String command)const;
	void CloseGate(int CommandDir)const;
	void OpenGate(int CommandDir)const;
private:	
	bool WayClear(int i)const;
	
};

#endif //WORLD
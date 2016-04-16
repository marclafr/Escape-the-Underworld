

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
	bool PickItem(Vector<String> tokens)const;
	bool LookInventory()const;
	bool DropItem(Vector<String> tokens)const;
	void LookItem(String item)const;
	bool EquipItem()const;
	int GetDirection(String command, Vector<String> tokens)const;
	void CloseGate(int CommandDir)const;
	void OpenGate(int CommandDir)const;
	void Stats()const;
private:	
	bool WayClear(int i)const;	
};

#endif //WORLD
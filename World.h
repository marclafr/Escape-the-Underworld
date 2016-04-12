

#ifndef WORLD
#define WORLD

#include <stdio.h>
#include "Exits.h"
#include "Player.h"
#include "Rooms.h"
#include "Chain.h"
#include "Entity.h"
#include "Items.h"

class World:public Entity{
public:
	Room* rooms = nullptr;
	Player* player = nullptr;
	Exit* exit = nullptr;
	String command;
	Item* item;
	World();
	void CreateWorld()const;
	bool ExitGame()const;
	bool Move(int CommandDir);
	bool LookDirection(int CommandDir)const;
	void Look()const;
	void create_items()const;
	bool PickItem()const;
	bool LookInventory()const;
	bool DropItem()const;
	~World();
private:	
	bool WayClear(int i)const;
	
};

#endif //WORLD
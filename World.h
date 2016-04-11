

#ifndef WORLD
#define WORLD

#include <stdio.h>
#include "Exits.h"
#include "Player.h"
#include "Rooms.h"
#include "Chain.h"
#include "Entity.h"

class World:public Entity{
public:
	Room* rooms = nullptr;
	Player* player = nullptr;
	Exit* exit = nullptr;
	String command;
	char* item;
	World();
	void CreateWorld()const;
	bool ExitGame()const;
	bool Move(int CommandDir);
	bool LookDirection(int CommandDir)const;
	~World();
private:	
	bool WayClear(int i)const;
	enum items{coin, stick, sword, axe};
};

#endif //WORLD
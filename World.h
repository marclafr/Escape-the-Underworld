

#ifndef WORLD
#define WORLD

#include <stdio.h>
#include "Exits.h"
#include "Player.h"
#include "Rooms.h"
#include "Chain.h"
#include "Entity.h"

class World{
public:
	Room* rooms = nullptr;
	Player* player = nullptr;
	Exit* exit = nullptr;
	World();
	void CreateWorld()const;
	char* command = nullptr;
	bool ExitGame()const;
	bool Move(int CommandDir);
	bool LookDirection(int CommandDir)const;
	~World();
private:	
	bool WayClear(int i)const;	
};

#endif //WORLD
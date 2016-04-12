#include "Rooms.h"
#include "Entity.h"

#ifndef PLAYER
#define PLAYER

#define NUM_ROOMS 13

class Player:public Entity{
public:
	Room* position = nullptr;
	int GetDirection(String command)const;
};

#endif //PLAYER
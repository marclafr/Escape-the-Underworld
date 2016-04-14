#include "Rooms.h"
#include "Entity.h"

#ifndef PLAYER
#define PLAYER

#define NUM_ROOMS 13

class Player:public Entity{
public:
	Player(){}
	~Player(){}
	Room* position = nullptr;
	Player(const char* n, const char* d, Room* pos) :Entity(n, d){
		position = pos;
	}	
};

#endif //PLAYER
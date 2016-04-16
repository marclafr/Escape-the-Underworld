#include "Rooms.h"
#include "Entity.h"

#ifndef PLAYER
#define PLAYER

#define NUM_ROOMS 13

class Player:public Entity{
public:
	Player(){}
	Room* position = nullptr;
	unsigned int attack;
	unsigned int defense;
	int hp;	
	Player(const char* n, const char* d, Room* pos, unsigned int att, unsigned int def, unsigned int hitpoints) :Entity(n, d){
		position = pos;
	}	
};

#endif //PLAYER
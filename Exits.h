#include "Entity.h"

#ifndef EXITS
#define EXITS


#define NUM_EXITS 24
class Room;
class Player;


enum dir{ 
	NORTH,
	SOUTH,
	EAST,
	WEST
};

class Exit:public Entity{
public:
	Room* origin;
	Room* destination;
	dir direction;
	int blocked;
	Exit(const char* n, const char* d, Room* ori, Room* dest, dir direc, int block) :Entity(n, d){
		origin = ori;
		destination = dest;
		direction = direc;
		blocked = block;
	}

};

#endif //EXITS
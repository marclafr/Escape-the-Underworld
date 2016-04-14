#include "Entity.h"

#ifndef ROOMS
#define ROOMS

class Room:public Entity{
public:
	Room(const char* n, const char* d):Entity(n, d){}
	String item_description;
};

#endif //ROOMS
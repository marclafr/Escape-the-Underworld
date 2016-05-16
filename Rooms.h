#include "Entity.h"

#ifndef ROOMS
#define ROOMS

#define NUM_ROOMS 13

class Room :public Entity{
public:
	Room(const char* n, const char* d) :Entity(ROOM, n, d){}
	Room(){}
	~Room(){}
	void Look()const;
	bool LookDirection(int direction, Vector<String> &tokens)const;
	//String item_description;TODO?
};

#endif //ROOMS
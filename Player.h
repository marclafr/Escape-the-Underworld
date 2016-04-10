#include "Rooms.h"
#include "Entity.h"

#ifndef PLAYER
#define PLAYER

#define NUM_ROOMS 13

class Player:public Entity{
public:
	Player();
	const Room* position;
	int GetDirection(char* command)const;
	//void ReceiveCommand()const;
	~Player();
};

#endif //PLAYER
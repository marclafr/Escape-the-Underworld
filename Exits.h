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

class Exit :public Entity{
public:
	Exit(){}
	~Exit(){}

	Room* origin;
	Room* destination;
	dir direction;
	int blocked;
	Exit(const char* n, const char* d, Room* ori, Room* dest, dir direc, int block) :Entity(EXIT, n, d), origin(ori), destination(dest), direction(direc), blocked(block) {}

	int GetDirection(const String& command, const Vector<String> &tokens)const;
	int GetDirection(const String& commandm)const;
	bool WayClear(int i)const;
	bool OpenGate(int direction)const;
	bool CloseGate(int direction)const;
};

#endif //EXITS
#include "Entity.h"

#ifndef EXITS
#define EXITS


#define NUM_EXITS 24
class Room;
class Player;


enum dir{ North, South, East, West };

class Exit:public Entity{
public:
	Exit();
	Room* origin;
	Room* destination;
	dir direction;
	int blocked;
	void OpenGate(int CommandDir)const;
	void CloseGate(int CommandDir)const;
	~Exit();
};

#endif //EXITS
#ifndef EXITS
#define EXITS

class Room;
class Player;

enum dir{North, South, East, West};

class Exit{
public:
	Exit();
	char name[39];
	char description[250];
	const Room* origin;
	const Room* destination;
	dir direction;
	int blocked;
	~Exit();
};

#endif //EXITS
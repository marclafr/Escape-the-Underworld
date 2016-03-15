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
	Room* origin;
	Room* destination;
	dir direction;
	int blocked;
	bool ClosedRooms(int BlockElm, int BlockPalace, char command, int position);

	int Exits(char command, int position);
	bool WayClear(char command, int position);

	~Exit();

};


#endif //EXITS
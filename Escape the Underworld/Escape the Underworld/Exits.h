#ifndef EXITS
#define EXITS

class Rooms;
class Player;

class Exits{
public:
	
	Exits();
	void Exit(Rooms* rooms, char command, int position);
	bool WayClear(Rooms* room, char command, int position);
	int NewPosition(char command, int position);
	~Exits();

};


#endif //EXITS
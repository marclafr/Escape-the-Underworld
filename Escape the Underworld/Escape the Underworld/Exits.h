#ifndef EXITS
#define EXITS

class Rooms;
class Player;

class Exits{
public:
	
	Exits();
	void Exit(Rooms* rooms, char command);
	bool WayClear(Rooms* room, char command);
	~Exits();

};


#endif //EXITS
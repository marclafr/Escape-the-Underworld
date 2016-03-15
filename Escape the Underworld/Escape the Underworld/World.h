#ifndef WORLD
#define WORLD

class World{
public:
	Room* rooms = nullptr;
	Player* player = nullptr;
	Exit* exit = nullptr;
	World();
	char ReceiveCommand();
	int GetDirection(char command);
	bool WayClear(int i);
	void Move(int CommandDir);
	void LookDirection(int CommandDir);
	void CreateWorld();
	~World();
};

#endif //WORLD
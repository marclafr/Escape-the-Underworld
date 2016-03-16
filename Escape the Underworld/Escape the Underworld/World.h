#ifndef WORLD
#define WORLD

class World{
public:
	Room* rooms = nullptr;
	Player* player = nullptr;
	Exit* exit = nullptr;
	World();
	void CreateWorld()const;
	~World();
private:
	char ReceiveCommand()const;
	int GetDirection(char command)const;
	void OpenGate(int CommandDir)const;
	void CloseGate(int CommandDir)const;
	bool WayClear(int i)const;
	int Move(int CommandDir)const;
	int LookDirection(int CommandDir)const;
};

#endif //WORLD
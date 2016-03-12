#ifndef WORLD
#define WORLD

class World{
public:
	Rooms* rooms = nullptr;
	Player* player = nullptr;
	Exits* exits = nullptr;
	World();
	
	void CreateWorld()const;
	~World();

};



#endif //WORLD
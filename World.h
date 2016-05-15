#include <stdio.h>
#include "Vector.h"
#include "String.h"
#include "Entity.h"
#include "Exits.h"
#include "Player.h"

#ifndef WORLD
#define WORLD

#define P_ORI_DAMAGE 45
#define P_ORI_DEFENSE 26
#define P_ORI_B_CHANCE 5
#define P_ORI_HP 2500

#define NUM_ENTITIES 54

class World{
public:
	World(){}
	~World(){}
	
	Vector<Entity*> entities;
	String command;
	Exit exits;
	Player player;
	void CreateWorld();
	bool ExitGame()const;
	void DeleteWorld();
};

extern World* Wor;

#endif //WORLD
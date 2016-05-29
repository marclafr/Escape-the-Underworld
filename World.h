#include <stdio.h>
#include "Vector.h"
#include "String.h"
#include "Entity.h"
#include "Exits.h"
#include "Player.h"
#include "Items.h"
#include "Monsters.h"

#ifndef WORLD
#define WORLD

#define P_ORI_DAMAGE 95
#define P_ORI_DEFENSE 26
#define P_ORI_B_CHANCE 5
#define P_ORI_HP 3500

#define NUM_ENTITIES 68

class World{
public:
	Vector<Entity*> entities;
	Vector<int>Counters;
	String command;
	Exit* exits;
	Item* items;
	Room* rooms;
	Player* player;
	Monster* monster;
	void CreateWorld();
	bool ExitGame()const;
	void DeleteWorld();
};

extern World* Wor;

#endif //WORLD
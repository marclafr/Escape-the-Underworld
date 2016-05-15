#include "Rooms.h"
#include "Entity.h"

#ifndef CREATURES
#define CREATURES

class Creature :public Entity{
public:
	Creature(){}	
	Room* position = nullptr;
	unsigned int attack;
	unsigned int defense;
	unsigned int block_chance;
	int hp;
	Creature(typeE type, const char* n, const char* d, Room* pos, unsigned int att, unsigned int def, unsigned int block_chance, unsigned int hitpoints) :Entity(type, n, d), attack(att), defense(def), block_chance(block_chance), hp(hitpoints), position(pos){}
	Creature(typeE type, String n, const char* d, Room* pos, unsigned int att, unsigned int def, unsigned int block_chance, unsigned int hitpoints) :Entity(type, n, d), attack(att), defense(def), block_chance(block_chance), hp(hitpoints), position(pos){}
	//virtual void Stats()const;
};

#endif //CREATURES
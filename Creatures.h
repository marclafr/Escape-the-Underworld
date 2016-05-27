#include "Rooms.h"
#include "Entity.h"

#ifndef CREATURES
#define CREATURES

class Creature :public Entity{
public:
	Room* position = nullptr;
	uint attack;
	uint defense;
	uint block_chance;
	int hp;
	uint souls;
	Creature(typeE type, const char* n, const char* d, uint att, uint def, uint block_chance, int hitpoints, uint souls)
		:Entity(type, n, d), attack(att), defense(def), block_chance(block_chance), hp(hitpoints), souls(souls){}
	Creature(typeE type, String n, const char* d, Room* pos, uint att, uint def, uint block_chance, int hitpoints, uint souls)
		:Entity(type, n, d), attack(att), defense(def), block_chance(block_chance), hp(hitpoints), position(pos), souls(souls){}
	//virtual void Stats()const;
	void Update(Vector<String>&){}
};

#endif //CREATURES
#include "Creatures.h"
#include "Entity.h"
#include "Rooms.h"

#ifndef __PLAYER__
#define __PLAYER__

class Player :public Creature{
public:
	Player(){}
	Room* position = nullptr;
	unsigned int attack;
	unsigned int defense;
	unsigned int block_chance;
	int hp;
	Player(String n, const char* d, Room* pos, unsigned int att, unsigned int def, unsigned int block_chance, unsigned int hitpoints) :Creature(PLAYER, n, d, pos, att, def, block_chance, hitpoints), attack(att), defense(def), block_chance(block_chance), hp(hitpoints), position(pos){}
	void Stats()const;
	bool Move(int direction);
	void ReceiveCommand(Vector<String> &tokens);
};

#endif //__PLAYER__
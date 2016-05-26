#include "Creatures.h"
#include "Entity.h"
#include "Rooms.h"

#ifndef __PLAYER__
#define __PLAYER__

class Player :public Creature{
public:
	Room* position = nullptr;
	Player(String n, const char* d, Room* pos, uint att, uint def, uint block_chance, int hitpoints, uint gold) :Creature(PLAYER, n, d, pos, att, def, block_chance, hitpoints, gold), position(pos){}
	void Stats()const;
	bool Move(int direction);
	void ReceiveCommand(Vector<String> &tokens, int num_words);
};

#endif //__PLAYER__
#include "Creatures.h"
#include "Entity.h"
#include "Rooms.h"
#include "Monsters.h"
#include <Windows.h>

#ifndef __PLAYER__
#define __PLAYER__

#define SPECIAL_CD 20

class Player :public Creature{
public:
	Room* position = nullptr;
	Player(String n, const char* d, Room* pos, uint att, uint def, uint block_chance, int hitpoints, uint gold)
		:Creature(PLAYER, n, d, pos, att, def, block_chance, hitpoints, gold), position(pos){}
	void Stats()const;
	bool Move(int direction);
	void ReceiveCommand(Vector<String> &tokens, int num_words);
	void ReceiveCombatCommand(Vector<String> &tokens);	
	void EnterCombat(Vector<String> &tokens);
	uint special_att_timer = GetTickCount();
	Monster* enemy = nullptr;
	bool CombatMode = false;
};

#endif //__PLAYER__
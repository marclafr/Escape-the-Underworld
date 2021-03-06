#include "Creatures.h"
#include "Entity.h"
#include "Rooms.h"
#include "Monsters.h"
#include <Windows.h>

#ifndef __PLAYER__
#define __PLAYER__

class Player :public Creature{
public:
	Room* position = nullptr;
	Player(String n, const char* d, Room* pos, uint att, uint def, uint block_chance, int hitpoints, uint souls)
		:Creature(PLAYER, n, d, pos, att, def, block_chance, hitpoints, souls), position(pos){}
	void Stats()const;
	bool Move(int direction)const;
	void ReceiveCommand(Vector<String> &tokens, int num_words)const;
	void ReceiveCombatCommand(Vector<String> &tokens);	
	bool EnterCombat(Vector<String> &tokens);

	uint special_att_timer = GetTickCount();
	uint special_def_timer = GetTickCount();
	Monster* enemy = nullptr;
	bool CombatMode = false;
	int special_att_cd = 20;
	int special_def_cd = 120;
	uint random_protection;
	bool ExtraDef = false;
};

#endif //__PLAYER__
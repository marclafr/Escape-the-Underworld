#include "Creatures.h"
#include "Entity.h"

#ifndef __MONSTERS__
#define __MONSTERS__

class Monster :public Creature{
public:
	Monster(typeE type, const char* n, const char* desc, uint att, uint def, uint b_ch, int hp, uint souls)
		:Creature(type, n, desc, att, def, b_ch, hp, souls){}
	void Update(String&, Monster*);
	void LookStore();
	void BuyItem();
};

#endif //__MONSTERS__
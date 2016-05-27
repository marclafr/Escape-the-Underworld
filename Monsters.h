#include "Creatures.h"
#include "Entity.h"

#ifndef __MONSTERS__
#define __MONSTERS__

class Monster :public Creature{
public:
	Monster(typeE type, const char* n, const char* desc, uint att, uint def, uint b_ch, int hp, uint gold) 
		:Creature(type, n,desc, att, def, b_ch, hp, gold){}
	void Update(String&);
};

#endif //__MONSTERS__
#include "Creatures.h"
#include "Entity.h"

#ifndef __MONSTERS__
#define __MONSTERS__

class Monster :public Creature{
public:
	Monster(typeE type, const char* n, const char* desc, uint att, uint def, uint b_ch, int hp, uint souls)
		:Creature(type, n, desc, att, def, b_ch, hp, souls){}
	void Update();
	void UpdateCombat(String&, Monster*);
	void LookStore();
	bool BuyItem(Vector<String>&, int &);
	bool SellItem(Vector<String>&, int &);
	bool CerberusEnraged = false;
};

#endif //__MONSTERS__
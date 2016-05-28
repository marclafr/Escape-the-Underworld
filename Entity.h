#include "String.h"
#include "DoubleList.h"

#ifndef _ENTITY_
#define _ENTITY_

typedef unsigned int uint;

enum typeE{
	ROOM,
	EXIT,
	ITEM,
	PLAYER,
	MONSTER_AGG,
	MONSTER_NON_AGG,
	CORPSE
};

class Entity{
public:
	Entity(typeE type, String name, String desc) : type(type),name(name), description(desc){}
	String name;
	String description;	
	typeE type;
	DoubleLinkList<Entity*> list;
	
	virtual void Update(){}
};



#endif //_ENTITY_
#include "String.h"
#include "DoubleList.h"


#ifndef _ENTITY_
#define _ENTITY_

enum typeE{
	ROOM,
	EXIT,
	ITEM,
	PLAYER,
	MONSTER
};

class Entity{
public:
	Entity(){}
	~Entity(){}
	Entity(typeE type, String name, String desc) : type(type),name(name), description(desc){}
	String name;
	String description;	
	typeE type;
	DoubleLinkList<Entity*> list;

	virtual void Update(){}

};



#endif //_ENTITY_
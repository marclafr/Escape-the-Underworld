#include "String.h"
#include "List.h"


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
	//LinkList<Entity*> list;  //deleteworld crashed cuz this was empty.

	virtual void Update(){}

};



#endif //_ENTITY_
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
	LinkList<Entity*> list;

	virtual void Update(){}

	/*Entity(const char* n, const char* d){
		name = n;
		description = d;
	}*/

};



#endif //_ENTITY_
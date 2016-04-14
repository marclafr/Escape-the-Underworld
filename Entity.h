#ifndef _ENTITY_
#define _ENTITY_
#include "Chain.h"
class Entity{
public:
	String name;
	String description;
	Entity(){}
	~Entity(){}
	
	Entity(const char* n, const char* d){
		name = n;
		description = d;
	}
//	Vector<Entity*> my_entity;
	enum tipus{
		PLAYER,
		ROOM,
		EXIT
		//----
	};
};

#endif //_ENTITY_
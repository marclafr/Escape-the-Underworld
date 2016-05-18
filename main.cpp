#include "MemLeaks.h"
#include "World.h"


World* Wor = nullptr;

int main()
{
	ReportMemoryLeaks();
	Wor = new World;
	
	Wor->CreateWorld();
	Wor->player->ReceiveCommand();
	Wor->DeleteWorld();

	return 0;
}
/*Wor->entities[1]->type == ITEM;
Item* i = (Item*)Wor->entities[1];
int a = i->value;*/
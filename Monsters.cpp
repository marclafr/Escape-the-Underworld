#include "World.h"
#include "Monsters.h"
#include <Windows.h>

void Monster::Update(String &command)
{
	printf("Update\n");

	if (Wor->player->hp <= 0)
	{
		Wor->player->CombatMode = false;	
		printf("Our hero %s died...", Wor->player->name.c_str());
	}

	/*Room* room = (Room*)Wor->entities[0];
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
	room = (Room*)Wor->entities[i];
	if (room->name == Wor->player->position->name && room->type == ROOM)
	{
	DoubleLinkList<Entity*>::nodeD* room_node = room->list.first_node;
	for (; room_node != nullptr; room_node = room_node->next)
	{
	if (room_node->data->name == tokens[1])		//TODO: 2+ same minion same room?
	{
	Monster* enemy = (Monster*)Wor->entities[0];
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
	if (Wor->entities[i]->name == tokens[1])
	{
	enemy = (Monster*)Wor->entities[i];
	}
	}
	while (Wor->player->hp > 0 && enemy->hp > 0)
	{
	int random = rand() % 100;
	if (random <= Wor->player->block_chance){ printf("You dodged %s's attack!!\n\n", enemy->name); }
	else
	{
	int damage = (enemy->attack - Wor->player->defense);
	printf("%s attacks you and causes %i\n", enemy->name.c_str(), damage);
	if (damage > 0){
	printf("%i damage.\n\n", damage);
	Wor->player->hp -= damage;
	}
	else{ printf("no damage, you have a nice defense. :)\n\n"); }
	}
	}
	}
	}
	}
	}*/
}

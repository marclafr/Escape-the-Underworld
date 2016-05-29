#include "World.h"
#include "Monsters.h"
#include <Windows.h>

//Combat update
void Monster::UpdateCombat(String &command, Monster* enemy)
{
	int random = rand() % 100;
	if (random <= Wor->player->block_chance){ printf("You dodged %s's attack!!\n\n", enemy->name); }
	else
	{
		int damage = (enemy->attack - Wor->player->defense);
		printf("%s attacks you and causes ", enemy->name.c_str(), damage);
		if (damage > 0)
		{
			printf("%i damage.\n\n", damage);
			Wor->player->hp -= damage;
		}
		else{ printf("no damage, you have a nice defense. :)\n\n"); }
	}

	if (Wor->player->hp <= 0)
	{
		Wor->player->CombatMode = false;	
		printf("Our hero %s died...", Wor->player->name.c_str());
	}
}
//--

//Look store
void Monster::LookStore()
{
	bool NoItems = true;
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		if (Wor->entities[i]->type == MONSTER_NON_AGG)
		{
			Monster* monster = (Monster*)Wor->entities[i];
			Room* room = (Room*)Wor->entities[0];
			for (int i = 0; i <= NUM_ENTITIES; i++)
			{
				if (Wor->entities[i]->type == ROOM && Wor->entities[i]->name == "Entrance")
				room = (Room*)Wor->entities[i];
			}
			if (room == Wor->player->position)
			{
				DoubleLinkList<Entity*>::nodeD* npc_node = monster->list.first_node;
				printf("Hello there stranger, would you like any of this?\n");
				for (; npc_node != nullptr; npc_node = npc_node->next)
				{
					for (int j = 0; j <= NUM_ENTITIES; j++)
					{
						if (npc_node->data->name == Wor->entities[j]->name)
						{
							Item* item = (Item*)Wor->entities[j];
							printf(" - %s: %sPrice: %i souls.\n\n\n", npc_node->data->name.c_str(), npc_node->data->description.c_str(), item->price);
							NoItems = false;
						}
					}
				}
			}
			else{ printf("%s is not here...\n\n", monster->name.c_str()); NoItems = false; }
		}
	}
	if (NoItems == true){ printf("Opps... I have nothing to sell sorry.\n\n"); }
}
//--

//Buy item
bool Monster::BuyItem(Vector<String> &tokens)
{
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		if (Wor->entities[i]->type == MONSTER_NON_AGG && tokens[3] == Wor->entities[i]->name)
		{
			Monster* monster = (Monster*)Wor->entities[i];
			Room* room = (Room*)Wor->entities[0];
			for (int i = 0; i <= NUM_ENTITIES; i++)
			{
				if (Wor->entities[i]->type == ROOM && Wor->entities[i]->name == "Entrance")
					room = (Room*)Wor->entities[i];
			}
			if (room == Wor->player->position)
			{
				DoubleLinkList<Entity*>::nodeD* npc_node = monster->list.first_node;
				DoubleLinkList<Entity*>::nodeD* player_node = Wor->player->list.first_node;
				for (; npc_node != nullptr; npc_node = npc_node->next)
				{
					if (npc_node->data->name == tokens[1])
					{
						for (int j = 0; j <= NUM_ENTITIES; j++)
						{
							if (npc_node->data->name == Wor->entities[j]->name)
							{
								Item* item = (Item*)Wor->entities[j];
								if (item->price > Wor->player->souls){ printf("You have not enough souls.\n\n"); return true; }
								else
								{
									printf("Thank you for your purshase!\n\n");
									Wor->player->list.push_back(item);
									item->place = INVENTORY;
									Wor->player->souls -= item->price;
									monster->list.erase(npc_node);
									return true;
								}
							}
						}
					}
				}
			}
			else{ printf("%s is not here...\n\n", monster->name.c_str()); return true; }
		}
	}
	return false;
}
//--

//Sell item
bool Monster::SellItem(Vector<String>& tokens)
{
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		if (Wor->entities[i]->type == MONSTER_NON_AGG && tokens[3] == Wor->entities[i]->name)
		{
			Monster* monster = (Monster*)Wor->entities[i];
			Room* room = (Room*)Wor->entities[0];
			for (int i = 0; i <= NUM_ENTITIES; i++)
			{
				if (Wor->entities[i]->type == ROOM && Wor->entities[i]->name == "Entrance")
					room = (Room*)Wor->entities[i];
			}
			if (room == Wor->player->position)
			{
				DoubleLinkList<Entity*>::nodeD* player_node = Wor->player->list.first_node;
				for (; player_node != nullptr; player_node = player_node->next)
				{
					if (player_node->data->name == tokens[1])
					{
						for (int j = 0; j <= NUM_ENTITIES; j++)
						{
							if (player_node->data->name == Wor->entities[j]->name)
							{
								Item* item = (Item*)Wor->entities[j];
								if (item->place != INVENTORY){ printf("%s must be in the inventory.\n\n", item->name.c_str()); }
								else
								{
									printf("%s sold succesfully!\nYou received %i souls\n\n", item->name.c_str(), item->price);
									Wor->player->souls += item->price;
									Wor->player->list.erase(player_node);
									item->place = STORE;
									monster->list.push_back(item);
									return true;
								}
							}
						}
					}
				}
			}
			else{ printf("%s is not here...\n\n", monster->name.c_str()); return true; }
		}
	}
}
//--

//Movement Update
void Monster::Update()
{
	if (Wor->player->CombatMode == false)
	{
		Monster* harpy = (Monster*)Wor->entities[0];
		for (int i = 0; i <= NUM_ENTITIES; i++)
		{
			if (Wor->entities[i]->name == "harpy")
			{
				harpy = (Monster*)Wor->entities[i];	//harpy is the only one that will move
			}
		}
		if (harpy->type != CORPSE)
		{
			Room* room = (Room*)Wor->entities[0];
			bool RoomCorrect = false;
			for (int i = 0; i <= NUM_ENTITIES; i++)
			{
				if (Wor->entities[i]->type == ROOM)	//TODO change elm for look 4 room
				{
					if (RoomCorrect == true){ RoomCorrect = false; break; }
					room = (Room*)Wor->entities[i];			//harpy actual room
					DoubleLinkList<Entity*>::nodeD* room_node = room->list.first_node;
					for (; room_node != nullptr; room_node = room_node->next)
					{
						if (room_node->data->name == "harpy")
							RoomCorrect = true;
					}
				}
			}
			DoubleLinkList<Entity*>::nodeD* room_node = room->list.first_node;
			DoubleLinkList<Exit*> possible_exits;
			for (int i = 0; i <= NUM_ENTITIES; i++)
			{
				if (Wor->entities[i]->type == EXIT)
				{
					Exit* exit = (Exit*)Wor->entities[i];
					if (exit->origin->name == room->name)
					{
						possible_exits.push_back(exit);		//create a list of the possible exits the harpy can take
					}
				}
			}
			int random = rand() % possible_exits.size();
			DoubleLinkList<Exit*>::nodeD* p_exits_node = possible_exits.first_node;
			for (int i = 0; i < random; i++)
			{
				p_exits_node = p_exits_node->next;		//takes the path randomly
			}
			Room* new_room = (Room*)Wor->entities[0];
			for (int i = 0; i <= NUM_ENTITIES; i++)
			{
				if (Wor->entities[i]->type == ROOM && p_exits_node->data->destination->name == Wor->entities[i]->name)
				{
					new_room = (Room*)Wor->entities[i];
				}
			}
			new_room->list.push_back(harpy);
			for (; room_node != nullptr; room_node = room_node->next)
			{
				if (room_node->data->name == "harpy")
				{
					room->list.erase(room_node);
					break;
				}
			}
			//TODO CREATE CLEAR && clear possible_exits list
		}
	}
}
//--
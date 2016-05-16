#include "World.h"
#include "Rooms.h"

//Look
void Room::Look()const
{
	Player* player = (Player*)Wor->entities[0];
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		if (Wor->entities[i]->type == PLAYER)
		{
			player = (Player*)Wor->entities[i];
		}
	}
	printf("%s\n", player->position->name.c_str());
	printf("%s\n", player->position->description.c_str());
	printf("This room contains this items:\n");
	bool NoItems = true;
	Item* item = (Item*)Wor->entities[0];
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		if (Wor->entities[i]->type == ITEM)
		{
			item = (Item*)Wor->entities[i];
			if (item->item_position->name == player->position->name && item->place == FLOOR)	//looks for the items that are in the same room as the player && are in the floor
			{
				printf(" - %s: %s\n", item->name.c_str(), item->description.c_str());
				NoItems = false;
			}
		}		
	}
	if (NoItems == true){ printf("This room has no items on the floor.\n\n"); }

}
//--

//Looks other rooms
	bool Room::LookDirection(int CommandDir, Vector<String> &tokens)const
{
		Player* player = (Player*)Wor->entities[0];
		for (int i = 0; i <= NUM_ENTITIES; i++)
		{
			if (Wor->entities[i]->type == PLAYER)
			{
				player = (Player*)Wor->entities[i];
			}
		}
		Exit* exit = (Exit*)Wor->entities[0];
		Room* room = (Room*)Wor->entities[0];
		for (int i = 0; i <= NUM_ENTITIES; i++)
		{
			if (Wor->entities[i]->type == EXIT)
			{
				exit = (Exit*)Wor->entities[i];
				if (exit->origin->name == player->position->name)
				{
					CommandDir = Wor->exits->GetDirection(Wor->command, tokens);
					if (CommandDir == exit->direction)			//checks if the direction is the same
					{		
						if (Wor->exits->WayClear(i) == true)		//if the path is blocked you can't see the other side
						{		
							printf("%s\n", exit->destination->description);
							return true;
						}
						else		//the message change if you try to look across a river or across a gate
						{	
							for (int j = 0; j <= NUM_ENTITIES; j++)
							{
								if (Wor->entities[j]->type == ROOM)
								{
									room = (Room*)Wor->entities[j];
									if (exit->destination == room && (room->name == "Right side of river Styx" || room->name == "Left side of river Styx"))
									{
										printf("You will need to cross the river to look what is in the other side.\n\n");	return true;
									}
									else if (exit->destination == room && 
										(room->name == "The Elm from which False Dreams cling" || room->name == "Entrance"
										|| room->name == "Palace of Hades" || room->name == "Fire Forest"))
									{
										printf("Before look what is inside you must open the gate.\n");	return true;
									}
								}
							}
						}
					}
				}
			}
		}
	return false;
}
//--
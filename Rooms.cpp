#include "World.h"
#include "Rooms.h"

//Look
void Room::Look()const
{
	printf("%s\n", Wor->player->position->name.c_str());
	printf("%s\n", Wor->player->position->description.c_str());
	printf("This room contains this items:\n");
	bool NoItems = true;
	Room* room = (Room*)Wor->entities[0];
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		room = (Room*)Wor->entities[i];
		if (room->name == Wor->player->position->name && room->type == ROOM)
		{
			DoubleLinkList<Entity*>::nodeD* room_node = room->list.first_node;
			if (room->list.Empty() == false)
			{
				for (; room_node != nullptr; room_node = room_node->next)
				{
					if (room_node->data->type == ITEM)
					{
						printf(" - %s: %s\n", room_node->data->name.c_str(), room_node->data->description.c_str());
						NoItems = false;
					}
				}
			}
		}
	}
	if (NoItems == true){ printf("This room has no items on the floor.\n\n"); }

}
//--

//Looks other rooms
	bool Room::LookDirection(int CommandDir, Vector<String> &tokens)const
{
		Exit* exit = (Exit*)Wor->entities[0];
		Room* room = (Room*)Wor->entities[0];
		for (int i = 0; i <= NUM_ENTITIES; i++)
		{
			if (Wor->entities[i]->type == EXIT)
			{
				exit = (Exit*)Wor->entities[i];
				if (exit->origin->name == Wor->player->position->name)
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
#include "Exits.h"
#include "World.h"
#include "Items.h"


int Exit::GetDirection(const String& command, const Vector<String> &tokens)const
{
	if		(command == "n" || command == "north" || tokens[0] == ("go") && tokens[1] == ("north"))		{ return 0; }
	else if (command == "s" || command == "south" || tokens[0] == ("go") && tokens[1] == ("south"))		{ return 1; }
	else if (command == "e" || command == "east" || tokens[0] == ("go") && tokens[1] == ("east"))		{ return 2; }
	else if (command == "w" || command == "west" || tokens[0] == ("go") && tokens[1] == ("west"))		{ return 3; }
	//Open/Close Command: Asks where to open.
	else if (command == "open" || command == "close"){
		if (command == "open")			{ printf("Open where?\n"); }
		else if (command == "close")	{ printf("Close where?\n"); }
		String Open_Close_Direction;
		Open_Close_Direction.GetString();
		if		(Open_Close_Direction == "north" || Open_Close_Direction == "n")	{ return 0; }
		else if (Open_Close_Direction == "south" || Open_Close_Direction == "s")	{ return 1; }
		else if (Open_Close_Direction == "east" || Open_Close_Direction == "e")		{ return 2; }
		else if (Open_Close_Direction == "west" || Open_Close_Direction == "w")		{ return 3; }
	}
	else { return -1; }
}

//ONE WORD
int Exit::GetDirection(const String& command)const
{
	if		(command == "n" || command == "north" || command == ("go north"))	{ return 0; }
	else if (command == "s" || command == "south" || command == ("go south"))	{ return 1; }
	else if (command == "e" || command == "east" || command == ("go east"))		{ return 2; }
	else if (command == "w" || command == "west" || command == ("go west"))		{ return 3; }
	//Open/Close Command: Asks where to open.
	else if (command == "open" || command == "close"){
		if (command == "open")			{ printf("Open where?\n"); }
		else if (command == "close")	{ printf("Close where?\n"); }
		String Open_Close_Direction;
		Open_Close_Direction.GetString();
		if		(Open_Close_Direction == "north" || Open_Close_Direction == "n")	{ return 0; }
		else if (Open_Close_Direction == "south" || Open_Close_Direction == "s")	{ return 1; }
		else if (Open_Close_Direction == "east" || Open_Close_Direction == "e")		{ return 2; }
		else if (Open_Close_Direction == "west" || Open_Close_Direction == "w")		{ return 3; }
	}
	else { return -1; }
}

//Checks if the path is clear
bool Exit::WayClear(int i)const
{
	Exit* exit = (Exit*)Wor->entities[i];
	if (exit->blocked == true){		//checks if gates are locked
		printf("Gate locked.\n");
		return false;
	}
	else if (exit->destination == Wor->entities[3] || exit->destination == Wor->entities[6]){	//checks if you have the coins in your inventory to cross the Styx River (right and left side)
		Item* item = (Item*)Wor->entities[0];
		for (int i = 0; i <= NUM_ENTITIES; i++)
		{
			if (Wor->entities[i]->type == ITEM)
			{
				item = (Item*)Wor->entities[i];
			}
		}
		if (item->place == INVENTORY){ return true; }
		else{
			printf("You need to have the coins for Charon the ferryman to cross this river.\n");
			return false;
		}
	}
	else { return true; }
}
//--

//Open
bool Exit::OpenGate(int CommandDir)const
{
	Exit* exit = (Exit*)Wor->entities[0];
	Player* player = (Player*)Wor->entities[0];
	Room* room = (Room*)Wor->entities[0];
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		if (Wor->entities[i]->type == PLAYER)
		{
			player = (Player*)Wor->entities[i];
		}
	}
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		if (Wor->entities[i]->type == EXIT)
		{
			exit = (Exit*)Wor->entities[i];

			for (int j = 0; j <= NUM_ENTITIES; j++)
			{
				if (Wor->entities[j]->type == ROOM)
				{
					room = (Room*)Wor->entities[j];

					if (exit->origin->name == player->position->name && CommandDir == exit->direction && exit->destination == room)
					{
						if (exit->blocked == false){ printf("This door had been already opened dude.\n\n");	return true; }
						else if (exit->blocked == 2){ printf("There is no door in this direction...\n\n"); return true; }
						else
						{
							//for (int j = 0; j < NUM_1_WORD_ITEMS; j++)
							//	{
							//	if (items[j]->name == "keys")
							//	{
							//		if (items[j]->place == INVENTORY)
							//		{
							exit->blocked = false;
							printf("The path to %s has been opened.\n\n", exit->destination->name);
							exit = (Exit*)Wor->entities[i + 2];
							exit->blocked = false;
							return true;
							//		}
							//		else{ printf("You need the keys to open this door.\n\n"); }
							//	}
							//	}
						}
					}
				}
			}
		}
	}
	return false;
}
//--

//Close
bool Exit::CloseGate(int CommandDir)const
{
	Exit* exit = (Exit*)Wor->entities[0];
	Player* player = (Player*)Wor->entities[0];
	Room* room = (Room*)Wor->entities[0];
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		if (Wor->entities[i]->type == PLAYER)
		{
			player = (Player*)Wor->entities[i];
		}
	}
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		if (Wor->entities[i]->type == EXIT)
		{
			exit = (Exit*)Wor->entities[i];

			for (int j = 0; j <= NUM_ENTITIES; j++)
			{
				if (Wor->entities[j]->type == ROOM)
				{
					room = (Room*)Wor->entities[j];

					if (exit->origin->name == player->position->name && CommandDir == exit->direction && exit->destination == room)
					{
						if (exit->blocked == true){ printf("This door is already closed dude.\n\n");	return true; }
						else if (exit->blocked == 2){ printf("There is no door in this direction...\n\n"); return true; }
						else
						{
							//for (int j = 0; j < NUM_1_WORD_ITEMS; j++)
							//	{
							//	if (items[j]->name == "keys")
							//	{
							//		if (items[j]->place == INVENTORY)
							//		{
							exit->blocked = true;
							printf("The path to %s has been clsoed.\n\n", exit->destination->name);
							exit = (Exit*)Wor->entities[i + 2];
							exit->blocked = true;
							return true;
							//		}
							//		else{ printf("You need the keys to close this door.\n\n"); }
							//	}
							//	}
						}
					}
				}
			}
		}
	}
	return false;
}
//--

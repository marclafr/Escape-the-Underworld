#include <stdio.h>
#include "Exits.h"
#include "Player.h"
#include "Rooms.h"
#include "World.h"
#include <string.h>

#define NUM_ROOMS 13


World::World(){
	
	rooms = new Room[NUM_ROOMS];
	player = new Player;
	exit = new Exit[24];
}

void World::CreateWorld(){
	//Name and description from all the rooms in the game:
	char* names[] = { "Entrance", "The Elm from which False Dreams cling", "Marsh", "Left side of river Styx", "Tartarus", "Phelgethon", "Right side of river Styx", "River Lethe", "Elysian Fields", "Fire Forest", "Palace of Hades", "Vale of Mourning", "Exit" };
	for (int i = 0; i < NUM_ROOMS; i++){
		strcpy_s((rooms + i)->name, names[i]);
	}
	char* descriptions[] = { 
		"After crossing the portal you lose your vision for a few seconds, you feel strange in here. \nOnce you recover you see a big door in the south and a path in the north.\n",
		"You don't believe you eyes, it is the most beautiful place you have ever seen, and in a place like in the Underworld! In the middle there are trees.\n",
		"You see a marsh, in the middle of it you see Charon the ferryan.\n",
		"After Charon take you here you only see one path, but you feel it is a dangerous place.\n",
		"You ear insane spirits being tortured, there is a powerful light at your right.\n",
		"The river is not of water, but fire.\n There is no way to cross it.\n ",
		"Charon makes a stop before entering the following river: Lethe, you get out from the boat and see a lot of undead.\n",
		"After crossing Lethe you see more undead near this river, but they seem different from the ones before...\n",
		"Just as you enter you feel a different sensation in this zone from all the ones before. You see some silhouettes in the distance.\n",
		"You see a big forest burning, but the light from the fire is strange.\n ",
		"Once again this place surprise you, this time by an enormous and beutiful palace.\n",
		"You feel the exit nearby, but there are more undead ahead.\n",
		"You can see the exit in the distance, unfortunately its guardian, Cerberus, is right before it...\n"
	};
	for (int i = 0; i < NUM_ROOMS; i++){
		strcpy_s((rooms + i)->description, descriptions[i]);
	}
	//--

	char command;
	player->position = (rooms + 0);
	
	//Exits & Destinations & Directions:
	(exit + 0)->origin = (rooms + 0);
	(exit + 0)->destination = (rooms + 1);
	(exit + 0)->direction = South;
	(exit + 0)->blocked = 0; //This exit has a door that can be opened/closed, it starts closed.
	(exit + 1)->origin = (rooms + 0);
	(exit + 1)->destination = (rooms + 2);
	(exit + 1)->direction = North;
	(exit + 2)->origin = (rooms + 1);
	(exit + 2)->destination = (rooms + 0);
	(exit + 2)->direction = North;
	(exit + 2)->blocked = 0; //This exit has a door that can be opened/closed, it starts closed.
	(exit + 3)->origin = (rooms + 2);
	(exit + 3)->destination = (rooms + 0);
	(exit + 3)->direction = South;
	(exit + 4)->origin = (rooms + 2);
	(exit + 4)->destination = (rooms + 3);
	(exit + 4)->direction = West;
	(exit + 5)->origin = (rooms + 3);
	(exit + 5)->destination = (rooms + 2);
	(exit + 5)->direction = East;
	(exit + 6)->origin = (rooms + 3);
	(exit + 6)->destination = (rooms + 4);
	(exit + 6)->direction = North;
	(exit + 7)->origin = (rooms + 4);
	(exit + 7)->destination = (rooms + 3);
	(exit + 7)->direction = South;
	(exit + 8)->origin = (rooms + 4);
	(exit + 8)->destination = (rooms + 5);
	(exit + 8)->direction = East;
	(exit + 9)->origin = (rooms + 5);
	(exit + 9)->destination = (rooms + 4);
	(exit + 9)->direction = West;
	(exit + 10)->origin = (rooms + 2);
	(exit + 10)->destination = (rooms + 6);
	(exit + 10)->direction = East;
	(exit + 11)->origin = (rooms + 6);
	(exit + 11)->destination = (rooms + 2);
	(exit + 11)->direction = West;
	(exit + 12)->origin = (rooms + 6);
	(exit + 12)->destination = (rooms + 7);
	(exit + 12)->direction = North;
	(exit + 13)->origin = (rooms + 7);
	(exit + 13)->destination = (rooms + 6);
	(exit + 13)->direction = South;
	(exit + 14)->origin = (rooms + 7);
	(exit + 14)->destination = (rooms + 8);
	(exit + 14)->direction = North;
	(exit + 15)->origin = (rooms + 8);
	(exit + 15)->destination = (rooms + 7);
	(exit + 15)->direction = South;
	(exit + 16)->origin = (rooms + 8);
	(exit + 16)->destination = (rooms + 9);
	(exit + 16)->direction = West;
	(exit + 17)->origin = (rooms + 9);
	(exit + 17)->destination = (rooms + 8);
	(exit + 17)->direction = East;
	(exit + 18)->origin = (rooms + 9);
	(exit + 18)->destination = (rooms + 10);
	(exit + 18)->direction = South;
	(exit + 18)->blocked = 0; //This exit has a door that can be opened/closed, it starts closed.
	(exit + 19)->origin = (rooms + 10);
	(exit + 19)->destination = (rooms + 9);
	(exit + 19)->direction = North;
	(exit + 19)->blocked = 0; //This exit has a door that can be opened/closed, it starts closed.
	(exit + 20)->origin = (rooms + 9);
	(exit + 20)->destination = (rooms + 11);
	(exit + 20)->direction = West;
	(exit + 21)->origin = (rooms + 11);
	(exit + 21)->destination = (rooms + 9);
	(exit + 21)->direction = East;
	(exit + 22)->origin = (rooms + 11);
	(exit + 22)->destination = (rooms + 12);
	(exit + 22)->direction = West;
	(exit + 23)->origin = (rooms + 12);
	(exit + 23)->destination = (rooms + 11);
	(exit + 23)->direction = East;


	//First place name and description
	printf("%s\n", player->position->name);
	printf("%s\n", player->position->description);
	//--

	do{
		command = World::ReceiveCommand();

		int CommandDir = World::GetDirection(command);
		if (CommandDir == -1){
			//look 
			if (command == 'l'){
				printf("%s", player->position->description);
			}
			//--



			//help menu
			else if (command == 'h'){
				printf("Help menu: \nTo move north, introduce north, n or go north.\nTo move south, introduce south, s or go south.\nTo move east, introduce east, e or go east.\nTo move west, introduce west, w or go west.\n\nThere are also those other commands: look:descrives the place you are in.\nlook + (direction): describe the path you want to take.\nOpen/Close: Opens or closes a door if it is possible.\nQuit: quits the game.");
			}
			//--

			//printf("Wrong direction.\n");
		}

		else if (CommandDir == 0 || CommandDir == 1 || CommandDir == 2 || CommandDir==3) { 
			if (command == 'n' || command == 's' || command == 'e' || command == 'w'){ World::Move(CommandDir); } //Move Commands Function
			else if (command == 'N' || command == 'S' || command == 'E' || command == 'W'){ World::LookDirection(CommandDir); } //Look Directions Commands Function
		}
		


		//Open commands:

		//--

		//Close commands:

		//--

	} while (command != 'q');
}
	
char World::ReceiveCommand(){
	char command[15];
	char CommandLetter;
	gets_s(command, 15);

	//Simplify the command from a string to a char
	if ((strcmp(command, "north") == 0) || (strcmp(command, "n") == 0) || (strcmp(command, "go north") == 0)){
		CommandLetter = 'n';
	}
	else if ((strcmp(command, "south") == 0) || (strcmp(command, "s") == 0) || (strcmp(command, "go south") == 0)){
		CommandLetter = 's';
	}
	else if ((strcmp(command, "east") == 0) || (strcmp(command, "e") == 0) || (strcmp(command, "go east") == 0)){
		CommandLetter = 'e';
	}
	else if ((strcmp(command, "west") == 0) || (strcmp(command, "w") == 0) || (strcmp(command, "go west") == 0)){
		CommandLetter = 'w';
	}
	else if (strcmp(command, "look north") == 0){ CommandLetter = 'N'; }
	else if (strcmp(command, "look south") == 0){ CommandLetter = 'S'; }
	else if (strcmp(command, "look east") == 0){ CommandLetter = 'E'; }
	else if (strcmp(command, "look west") == 0){ CommandLetter = 'W'; }
	else if (strcmp(command, "look") == 0){ CommandLetter = 'l'; }
	else if (strcmp(command, "open") == 0){ CommandLetter = 'o'; }
	else if (strcmp(command, "close") == 0){ CommandLetter = 'c'; }
	else if (strcmp(command, "quit") == 0){ CommandLetter = 'q'; }
	else if (strcmp(command, "help") == 0){	CommandLetter = 'h'; }
	else{ printf("What?\n"); }
	//--

	return CommandLetter;
}

int World::GetDirection(char command){
	if (command == 'n' || command == 'N'){ return 0; }
	else if (command == 's' || command == 'S'){ return 1; }
	else if (command == 'e' || command == 'E'){ return 2; }
	else if (command == 'w' || command == 'W'){ return 3; }
	else { return - 1; }
}

bool World::WayClear(int i){
	if (exit[i].blocked == 0){ 
		printf("Gate locked.\n");
		return false;
	}
	else { return true; }
}

void World::Move(int CommandDir){
	bool done = false; //makes a path stop as soon as he finds another room.
	for (int i = 0; i < 24; i++){
		if (0 == strcmp(exit[i].origin->name, player->position->name)){ //Compares if the position of the player and the origin of the exit is the same.
			if (CommandDir == exit[i].direction) {//compares if the direction of the exit and the direction of the command is the same.
				if (World::WayClear(i) == true){ //Looks if the path is looked or not.
					player->position = exit[i].destination;
					printf("%s\n", player->position->name);
					printf("%s\n", player->position->description);
					done = true;
					break;
				}
			}
		}
	}
}

void World::LookDirection(int CommandDir){
	bool done = false;
	for (int i = 0; i < 24; i++){
		if (0 == strcmp(exit[i].origin->name, player->position->name)){
			if (CommandDir == exit[i].direction) {
				printf("%s\n", exit[i].destination->description);
				done = true;
				break;
			}
		}
	}
}

World::~World(){
	delete[]exit;
	delete player;
	delete[]rooms;
}


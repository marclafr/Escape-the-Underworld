#include "World.h"
#include "Chain.h"


World::World(){
	rooms = new Room[NUM_ROOMS];
	player = new Player;
	exit = new Exit[NUM_EXITS];
	item = new char[name.capacity()];
}

void World::CreateWorld()const{
	//Name and description from all the rooms in the game:
	(rooms + 0)->name = "Entrance";
	(rooms + 0)->description = "You are back in the entrance, you see a big door in the south and a path in the north.\n";
	(rooms + 1)->name = "The Elm from which False Dreams cling";
	(rooms + 1)->description = "You don't believe you eyes, it is the most beautiful place you have ever seen, and in a place like in the Underworld! In the middle there are trees.\n";
	(rooms + 2)->name = "Marsh";
	(rooms + 2)->description = "You see a marsh, in the middle of it you see Charon the ferryan.\n";
	(rooms + 3)->name = "Left side of river Styx";
	(rooms + 3)->description = "After Charon take you here you only see one path, but you feel it is a dangerous place.\n";
	(rooms + 4)->name = "Tartarus";
	(rooms + 4)->description = "You ear insane spirits being tortured, there is a powerful light in the right.\n";
	(rooms + 5)->name = "Phelgethon";
	(rooms + 5)->description = "The river is not of water, but fire.\n There is no way to cross it.\n ";
	(rooms + 6)->name = "Right side of river Styx";
	(rooms + 6)->description = "This river is full of undead.\n";
	(rooms + 7)->name = "River Lethe";
	(rooms + 7)->description = "In the border of the river  Lethe you see more undead near this river, but they seem different from the ones before...\n";
	(rooms + 8)->name = "Elysian Fields";
	(rooms + 8)->description = "You feel a different sensation in this zone from all the ones before. You see some silhouettes in the distance.\n";
	(rooms + 9)->name = "Fire Forest";
	(rooms + 9)->description = "You see a big forest burning, but the light from the fire is strange.\n ";
	(rooms + 10)->name = "Palace of Hades";
	(rooms + 10)->description = "Once again this place surprise you, this time by an enormous and beutiful palace.\n";
	(rooms + 11)->name = "Vale of Mourning";
	(rooms + 11)->description = "You feel the exit nearby, but there are more undead ahead.\n";
	(rooms + 12)->name = "Exit";
	(rooms + 12)->description = "You can see the exit in the distance, unfortunately its guardian, Cerberus, is right before it...\n";
	//--

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

	//Initializes the position in the Entrance.
	player->position = (rooms + 0);
	player->description = (rooms + 0)->description;

	//First place name and description
	printf("%s\n", player->position->name);
	printf("After crossing the portal you lose your vision for a few seconds, you feel strange in here. \nOnce you recover you see a big door in the south and a path in the north.\n"); //Different description once you return in the entrance.
	//--
}

bool World::Move(int CommandDir){
	bool done = false; //makes a path stop as soon as he finds another room.
	for (int i = 0; i < NUM_EXITS; i++){
		if (exit[i].origin->name == player->position->name){ //Compares if the position of the player and the origin of the exit is the same.
			if (CommandDir == exit[i].direction) {//compares if the direction of the exit and the direction of the command is the same.
				if (World::WayClear(i) == true){ //Looks if the path is looked or not.
					player->position = exit[i].destination;
					printf("%s\n", player->position->name);
					printf("%s\n", player->position->description);
					done = true;
					return true;
					break;
				}
			}
		}
	}
	return false;
}

//Comproving if tha path is closed
bool World::WayClear(int i)const{
	if (exit[i].blocked == 0){
		printf("Gate locked.\n");
		return false;
	}
	else { return true; }
}
//--

//Looks other rooms
bool World::LookDirection(int CommandDir)const{
	bool done = false;
	for (int i = 0; i < NUM_EXITS; i++){
		if (exit[i].origin->name == player->position->name){
			if (CommandDir == exit[i].direction) {
				if (World::WayClear(i) == true){
					printf("%s\n", exit[i].destination->description);
					done = true;
					return 1;
					break;
				}
				else{ printf("Before look what is inside you must open the gate.\n"); }
			}
		}
	}
	return 0;
}
//--

//Exits game
bool World::ExitGame()const{
	if (command == "quit"){ return true; }
	else{ return false; }
}
//--

World::~World(){
	delete[] item;
	delete[]exit;
	delete player;
	delete[]rooms;	
}
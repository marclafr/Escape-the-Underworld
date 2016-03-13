#include <stdio.h>
#include "Exits.h"
#include "Player.h"
#include "Rooms.h"
#include "World.h"

Exits::Exits(){

}

char* PositionName[13] = { "Entrance", "The Elm from which False Dreams cling", "Marsh", "Left side of river Styx", "Tartarus", "Phelgethon", "Right side of river Styx", "River Lethe", "Elysian Fields", "Fire Forest", "Palace of Hades", "Vale of Mourning", "Exit" };


void Exits::Exit(Rooms* rooms, char command, int position){
/*	for (int i = 0; i < 13; i++){
		printf("%s\n", (rooms+i)->name);
	}*/
	

	if (WayClear(rooms, command, position) == 1){position = NewPosition(command, position); }

	printf("You are in %s.\n", PositionName[position]);
}

bool Exits::WayClear(Rooms* rooms, char command, int position){
	//Comproves if the path is avaiable.
	switch (command){
	case 'n': 
		if (position == 0 || position == 1 || position == 3 || position == 6 || position == 7 || position == 10 ){
			return true;
		}
		else { return false; }
		break;
	case 's':
		if (position == 0 || position == 2 || position == 4 || position == 7 || position == 8 || position == 9){
			return true;
		}
		else { return false; }
		break;
	case 'e':
		if (position == 2 || position == 3 || position == 4 || position == 9 || position == 11 || position == 12){
			return true;
		}
		else { return false; }
		break;
	case 'w':
		if (position == 2 || position == 5 || position == 6 || position == 8 || position == 9 || position == 11){
			return true;
		}
		else { return false; }
		break;
	}
	
}

int Exits::NewPosition(char command, int position){
	//Moves the player: In case the way is locked I'll make him return after.
	int* PPosition = &position;
	if (command == 'n'){
		if (position == 0){ position = 2; }
		else if (position == 1){ position = 0; }
		else if (position == 3){ position = 4; }
		else if (position == 6){ position = 7; }
		else if (position == 7){ position = 8; }
		else if (position == 10){ position = 9; }
		return position;
	}
	else if (command == 's'){
		if (position == 0){ position = 1; }
		else if (position == 2){ position = 0; }
		else if (position == 4){ position = 3; }
		else if (position == 7){ position = 6; }
		else if (position == 8){ position = 7; }
		else if (position == 9){ position = 10; }
		return position;
	}
	else if (command == 'e'){
		if (position == 2){ position = 3; }
		else if (position == 5){ position = 4; }
		else if (position == 6){ position = 2; }
		else if (position == 8){ position = 9; }
		else if (position == 9){ position = 11; }
		else if (position == 11){ position = 12; }
		return position;
	}
	else if (command == 'w'){
		if (position == 2){ position = 6; }
		else if (position == 3){ position = 2; }
		else if (position == 4){ position = 5; }
		else if (position == 9){ position = 8; }
		else if (position == 11){ position = 9; }
		else if (position == 12){ position = 11; }
		return position;
	}
}
Exits::~Exits(){

}

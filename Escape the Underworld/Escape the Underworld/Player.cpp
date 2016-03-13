#include <stdio.h>
#include "Exits.h"
#include "Player.h"
#include "Rooms.h"
#include "World.h"
#include <string.h>
#include <iostream>

Player::Player(){
	
}
Player::~Player(){

}

char Player::ReceiveCommand(){
	char command[10]="go east";
	char CommandLetter;
//	scanf_s("%s", &command[0]);
	printf("%s", command);
	getchar();

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
	else if (strcmp(command, "look") == 0){ CommandLetter = 'l'; }
	else if (strcmp(command, "open") == 0){ CommandLetter = 'o'; }
	else if (strcmp(command, "close") == 0){ CommandLetter = 'c'; }
	else if (strcmp(command, "quit") == 0){ CommandLetter = 'q'; }
	else if (strcmp(command, "help") == 0){ CommandLetter = 'h'; }
	else{ printf("What?\n"); }
	//--

	return CommandLetter;
}
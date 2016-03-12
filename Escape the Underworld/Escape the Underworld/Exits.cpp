#include <stdio.h>
#include "Exits.h"
#include "Player.h"
#include "Rooms.h"
#include "World.h"

Exits::Exits(){

}

void Exits::Exit(Rooms* rooms){
	for (int i = 0; i < 13; i++){
		printf("%s\n", (rooms+i)->name);
	}

}

Exits::~Exits(){

}

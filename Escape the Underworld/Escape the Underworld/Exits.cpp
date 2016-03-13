#include <stdio.h>
#include "Exits.h"
#include "Player.h"
#include "Rooms.h"
#include "World.h"

Exits::Exits(){

}




void Exits::Exit(Rooms* rooms, char command){
	for (int i = 0; i < 13; i++){
		printf("%s\n", (rooms+i)->name);
	}

	WayClear(rooms, command);

}

bool Exits::WayClear(Rooms* rooms, char command){

	switch (command){
	case 'n':
	}

}

Exits::~Exits(){

}

#include <stdio.h>
#include "Exits.h"
#include "Player.h"
#include "Rooms.h"
#include "World.h"

Exit::Exit(){

}





int Exit::Exits(char command, int position){
/*	for (int i = 0; i < 13; i++){
		printf("%s\n", (rooms+i)->name);
	}*/
	

	if (WayClear(command, position) == 1){ }
	fflush(stdin);
	
	return position;
}

bool Exit::ClosedRooms(int BlockElm, int BlockPalace, char command, int position){
	if (position == 1 && BlockElm == 1){
		return false;
	}
	else if (position == 10 && BlockPalace == 1){
		return false;
	}
	else return true;
}

bool Exit::WayClear(char command, int position){
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



Exit::~Exit(){

}

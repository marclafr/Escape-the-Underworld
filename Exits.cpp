#include "World.h"

Exit::Exit(){}

Exit::~Exit(){}

World my_world;
Player my_player;
//Open
void Exit::OpenGate(int CommandDir)const{
	for (int i = 0; i < NUM_EXITS; i++){
		if (my_world.exit[i].origin->name == my_player.position->name){
			if (CommandDir == my_world.exit[i].direction) {
				if (my_world.exit[i].destination == (my_world.rooms + 10) || my_world.exit[i].destination == (my_world.rooms + 1) || my_world.exit[i].destination == (my_world.rooms + 9) || my_world.exit[i].destination == (my_world.rooms + 0)){
					if ((my_world.exit + i)->blocked == 1){ printf("This door had been already opened dude.\n"); }
					else{
						(my_world.exit + i)->blocked = 1;
						(my_world.exit + i + 2)->blocked = 1;
						printf("The path to %s has been opened.\n", my_world.exit[i].destination->name);
					}
				}
				else{ printf("I don't see any door to open...\n"); }
			}
		}
	}
}
//--

//Close
void Exit::CloseGate(int CommandDir)const{
	for (int i = 0; i < NUM_EXITS; i++){
		if (my_world.exit[i].origin->name == my_player.position->name){
			if (CommandDir == my_world.exit[i].direction) {
				if (my_world.exit[i].destination == (my_world.rooms + 10) || my_world.exit[i].destination == (my_world.rooms + 1) || my_world.exit[i].destination == (my_world.rooms + 9) || my_world.exit[i].destination == (my_world.rooms + 0)){
					if ((my_world.exit + i)->blocked == 0){ printf("This door is already closed dude.\n"); }
					else{
						(my_world.exit + i)->blocked = 0;
						(my_world.exit + i + 2)->blocked = 0;
						printf("The path to %s has been closed.\n", my_world.exit[i].destination->name);
					}
				}
				else{ printf("I don't see any door to close...\n"); }
			}
		}
	}
}
//--
#include "Player.h"
#include "World.h"

//Player stats
void Player::Stats()const{
	Player* player = (Player*)Wor->entities[0];
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		if (Wor->entities[i]->type == PLAYER)
		{
			player = (Player*)Wor->entities[i];
		}
	}
	printf("%s stats are:\n", player->name);
	printf("HP: %i.\n", player->hp);
	printf("Attack: %i.\n", player->attack);
	printf("Defense: %i.\n", player->defense);
	printf("Block chance: %i.\n\n", player->block_chance);
}
//--

bool Player::Move(int direction)
{
	bool done = false;			//makes a path stop as soon as he finds another room.
	Player* player = (Player*)Wor->entities[0];
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
			Exit* exit = (Exit*)Wor->entities[i];
			if (exit->origin->name == player->position->name){	 //Compares if the position of the player and the origin of the exit is the same.
				if (direction == exit->direction) {			 //compares if the direction of the exit and the direction of the command is the same.
					if (exit->WayClear(i) == true){				 //Looks if the path is looked or not.
						player->position = exit->destination;
						printf("%s\n", player->position->name);
						printf("%s\n\n", player->position->description);
						done = true;
						return true;
						break;
					}
				}
			}
		}
	}
	return false;
}

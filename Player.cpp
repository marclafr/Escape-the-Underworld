#include "World.h"

//Player stats
void Player::Stats()const{
	printf("Your stats are:\n");
	printf("HP: %i.\n", Wor->player.hp);
	printf("Attack: %i.\n", Wor->player.attack);
	printf("Defense: %i.\n", Wor->player.defense);
	printf("Block chance: %i.\n\n", Wor->player.block_chance);
}
//--
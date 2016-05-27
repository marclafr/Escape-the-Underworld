#include "World.h"
#include "Monsters.h"
#include <Windows.h>

void Monster::Update(String &command, Monster* enemy)
{
	printf("Update\n");
	int random = rand() % 100;
	if (random <= Wor->player->block_chance){ printf("You dodged %s's attack!!\n\n", enemy->name); }
	else
	{
		int damage = (enemy->attack - Wor->player->defense);
		printf("%s attacks you and causes %i\n", enemy->name.c_str(), damage);
		if (damage > 0)
		{
			printf("%i damage.\n\n", damage);
			Wor->player->hp -= damage;
		}
		else{ printf("no damage, you have a nice defense. :)\n\n"); }
	}

	if (Wor->player->hp <= 0)
	{
		Wor->player->CombatMode = false;	
		printf("Our hero %s died...", Wor->player->name.c_str());
	}
}

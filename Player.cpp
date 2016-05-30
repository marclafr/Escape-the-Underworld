#include "Player.h"
#include "World.h"
#include <Windows.h>

void Player::ReceiveCommand(Vector<String> &tokens, int num_words)
{
	if (num_words > 1)
	{
		int CommandDir = Wor->exits->GetDirection(Wor->command, tokens);
		if (CommandDir == 0 || CommandDir == 1 || CommandDir == 2 || CommandDir == 3)
		{
			if (tokens[0] == ("go") && tokens[1] == ("north") ||
				tokens[0] == ("go") && tokens[1] == ("south") ||
				tokens[0] == ("go") && tokens[1] == ("east") ||
				tokens[0] == ("go") && tokens[1] == ("west"))
			{
				if (Wor->player->Move(CommandDir) == false)
				{	//Move Commands Function
					printf("You can't go that way.\n\n");
				}
			}
		}
		else if (tokens[0] == ("look") && tokens[1] == ("around")){ Wor->rooms->Look(); }
		else if (tokens[0] == ("look") && tokens[1] == ("north") || tokens[0] == ("look") && tokens[1] == ("south") || tokens[0] == ("look") && tokens[1] == ("east") || tokens[0] == ("look") && tokens[1] == ("west"))
		{
			if (tokens[0] == ("look") && tokens[1] == ("north"))	{ Wor->command = "north"; }		//Need to do this because if not, the CommandDir won't be able to compare with the exit direction
			else if (tokens[0] == ("look") && tokens[1] == ("south"))	{ Wor->command = "south"; }
			else if (tokens[0] == ("look") && tokens[1] == ("east"))	{ Wor->command = "east"; }
			else if (tokens[0] == ("look") && tokens[1] == ("west"))	{ Wor->command = "west"; }
			if (Wor->rooms->LookDirection(CommandDir, tokens) == false)			//Look Directions Commands Function
			{
				printf("Nothing to see here...\n\n");
			}
		}
		else if (tokens[0] == ("pick"))
		{
			if (Wor->items->PickItem(tokens, Wor->Counters[0]) == false)
			{
				printf("The item is not here or doesn't exist.\n");
			}
		}
		else if (tokens[0] == ("drop") == true)
		{
			if (Wor->items->DropItem(tokens, Wor->Counters[0]) == false)
			{
				printf("Your inventory haven't this item, you can't drop it.\n\n");
			}
		}
		else if (tokens[0] == ("look")){ Wor->items->LookItem(tokens); }
		else if (tokens[0] == "equip")
		{
			if (Wor->items->EquipItem(tokens, Wor->Counters[1], Wor->Counters[2], Wor->Counters[3], Wor->Counters[4]) == false)		//[0] == weapon, [1] == armour
			{
				printf("Equip what??\n");
			}
		}
		else if (tokens[0] == "equip")
		{
			if (Wor->items->EquipItem(tokens, Wor->Counters[1], Wor->Counters[2], Wor->Counters[3], Wor->Counters[4]) == false)
			{ //[0] == weapon, [1] == armour
				printf("Equip what??\n");
			}
		}
		else if (tokens[0] == "unequip")
		{
			if (Wor->items->UnequipItem(tokens, Wor->Counters[1], Wor->Counters[2], Wor->Counters[3]) == false)
			{
				printf("Unequip what??\n\n");
			}
		}
		else if (tokens[0] == "put" && num_words == 4)
		{
			if (tokens[2] == "into")
			{
				Wor->items->FuseItems(tokens, Wor->Counters[0], Wor->Counters[4]);
			}
		}
		else if (tokens[0] == "get" && num_words == 4)
		{
			if (tokens[2] == "from")
			{
				Wor->items->UnfuseItems(tokens, Wor->Counters[0], Wor->Counters[4]);
			}
		}
		else if (tokens[0] == "activate"){ Wor->items->ActivateStatue(tokens, Wor->Counters[5], Wor->Counters[0]); }
		else if (tokens[0] == "desactivate"){ Wor->items->DesactivateStatue(tokens, Wor->Counters[5]); }
		else if (tokens[0] == "attack")
		{
			if (Wor->player->EnterCombat(tokens) == false)
			{
				printf("Attack what?.\n");
			}
		}
		else if (tokens[0] == "buy")
		{
			if (num_words == 2){ Wor->monster->LookStore(); }
			else if (num_words == 4)
			{
				if (tokens[2] == "from")
				{
					if (Wor->monster->BuyItem(tokens, Wor->Counters[0]) == false)
					{
						printf("I haven't this.\n\n");
					}
				}
			}
			else{ printf("Buy what?\n"); }
		}
		else if (tokens[0] == "sell")
		{
			if (num_words == 4)
			{
				if (tokens[2] == "to")
				{
					Wor->monster->SellItem(tokens, Wor->Counters[0]);
				}
			}
			else{ printf("Sell what?\n"); }
		}
		else
		{
			printf("I can't understand that.\n\n");
		}
	}
	else if (num_words == 1)
	{
		//God Mode commands (@ before command)
		if (Wor->command == "@money"){ Wor->player->souls = 999999; printf("Souls adquired.\n\n"); }
		if (Wor->command == "@upgrade")
		{
			Wor->player->hp = 10000;
			Wor->player->attack = 2000;
			Wor->player->defense = 1000;
			Wor->player->block_chance = 90;
			printf("Stats upgraded.\n\n");
		}
		if (Wor->command == "@items")
		{
			Item* item;
			for (int i = 0; i <= NUM_ENTITIES; i++)
			{
				if (Wor->entities[i]->type == ITEM)
				{
					item = (Item*)Wor->entities[i];
					if (item->place != EQUIPPED && item->place!=INVENTORY)
					{
						item->place = INVENTORY; 
						Wor->player->list.push_back(item);
						Wor->Counters[0]++;
					}
					
				}
			}
			printf("All items are now in your inventory.\n");
		}
		//--

		int CommandDir = Wor->exits->GetDirection(Wor->command);
		if (CommandDir == -1)
		{
			if (Wor->command == "help")
			{
				printf("Help menu: \nTo move north, introduce north, n or go north.\nTo move south, introduce south, s or go south.\nTo move east, introduce east, e or go east.\nTo move west, introduce west, w or go west.\n\n The command 'look around' descrives the place you are in and the items that are in the room.\n\nlook + (direction): describe the path you want to take, but you can't see the items there are if you are not in the same room.\n\nThere are some locked doors, to open or close them use the commands 'open'/'close': Opens or closes a door if it is possible, then the game will ask you the direction the door is.\nNOTICE: if you type, for example, open north directly it won't work!\n\nThe command 'inventory', 'inv', or 'i' allows you to look the items there are in your inventory and the ones that are equipped (if you have any).\nIt also tells you its free space.\n\nIn order to equip or unequip an item, introduce 'equip / unequip <item>'\nThere is a limit of items that could be equipped (1 armour, 1 weapon and 1 shield).\n\nBefore being able to equip an item it must be in the inventory, with the command 'pick <item>' you will get the item you introduce if it is in the same room as you are, and if you need space in your inventory you can drop an item with 'drop <item>'.\n\nIn order to save inventory space you can put items into anothers and get them after(only a few) with the commands 'put <item> into <item>' and 'get <item> from <item>'\n\nThe statues can be used with the command 'activate <name> statue', but you can only have 2 of them activated at the same time, so you can also desactivate them with 'desactivate <name> statue'\n\nYour player have stats, that can be changed deppending on the items you have equipped, to check them introduce the command 'stats'.\n\nquit: quits the game.\n");
			}	//help menu will be more readable if you start the game and introduce "help" :)
			else if (Wor->command == "inventory" || Wor->command == "inv" || Wor->command == "i"){ Wor->items->LookInventory(Wor->Counters[0]); }
			else if (Wor->command == "stats"){ Wor->player->Stats(); }
			else if (Wor->command == "quit"){ printf("Goodbye! :)\n"); getchar(); }
			else
			{
				printf("I can't understand that.\n\n");
			}
		}
		else if (CommandDir == 0 || CommandDir == 1 || CommandDir == 2 || CommandDir == 3)
		{
			if (Wor->command == "n" || Wor->command == "north" ||
				Wor->command == "s" || Wor->command == "south" ||
				Wor->command == "e" || Wor->command == "east" ||
				Wor->command == "w" || Wor->command == "west")
			{
				if (Wor->player->Move(CommandDir) == false)	//Move Commands Function
				{
					printf("You can't go that way.\n\n");
				}
			}
			else if (Wor->command == "open")	//Open function
			{
				if (Wor->exits->OpenGate(CommandDir) == false)
				{
					printf("I don't see any door to open.\n\n");
				}
			}
			else if (Wor->command == "close")		//Close function
			{
				if (Wor->exits->CloseGate(CommandDir) == false)
				{
					printf("I don't see any door to close.\n\n");
				}
			}
			else
			{
				printf("I can't understand that.\n\n");
			}
		}
	}
}
//--

//Player stats
void Player::Stats()const
{
	printf("%s stats are:\n",		 Wor->player->name);
	printf("HP: %i / %i.\n",		 Wor->player->hp, P_ORI_HP);
	printf("Attack: %i.\n",			 Wor->player->attack);
	printf("Defense: %i.\n",		 Wor->player->defense);
	printf("Block chance: %i.\n",	 Wor->player->block_chance);
	printf("Souls: %i.\n\n",		 Wor->player->souls);
}
//--

//Player Movement
bool Player::Move(int direction)
{
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		if (Wor->entities[i]->type == EXIT)
		{
			Exit* exit = (Exit*)Wor->entities[i];
			if (exit->origin->name == Wor->player->position->name){	 //Compares if the position of the player and the origin of the exit is the same.
				if (direction == exit->direction) {			 //compares if the direction of the exit and the direction of the command is the same.
					if (exit->WayClear(i) == true){				 //Looks if the path is looked or not.
						Wor->player->position = exit->destination;
						printf("%s\n", Wor->player->position->name);
						printf("%s\n\n", Wor->player->position->description);
						DoubleLinkList<Entity*>::nodeD* room_node = Wor->player->position->list.first_node;
						for (; room_node != nullptr; room_node = room_node->next)
						{
							if (room_node->data->name == "harpy")
							{
								printf("You moved into the room harpy actually is. Prepare to fight!\n");
								Monster* harpy = (Monster*)Wor->entities[0];
								for (int j = 0; j <= NUM_ENTITIES; j++)
								{
									if (Wor->entities[j] == room_node->data)
									{
										harpy = (Monster*)Wor->entities[j];
									}
								}
								Wor->player->enemy = harpy;
								Sleep(1250);
								Wor->player->CombatMode = true;
							}
						}
						return true;
						break;
					}
				}
			}
		}
	}
	return false;
}
//--

//Combat commands
void Player::ReceiveCombatCommand(Vector<String> &tokens)
{
	if (tokens[0] == "attack")
	{
		int random = rand() % 100;
		if (random <= enemy->block_chance)
		{
			printf("%s dodged your attack!!\n\n", enemy->name);
		}
		else
		{
			int damage = Wor->player->attack - enemy->defense;
			if (damage > 0)
			{
				printf("You hit %s for %i damage.\n\n", enemy->name.c_str(), damage);
				enemy->hp -= damage;
			}
			else { printf("Your attacks seem to do nothing...\n\n"); }
		}
	}
	else if (tokens[0] == "protect")
	{
		if (GetTickCount() - special_def_timer > (SPECIAL_DEF_CD * 1000))
		{
			if (ExtraDef == false)
			{
				special_def_timer = GetTickCount();
				printf("Defense raised for this combat.\n\n");
				random_protection = rand() % (Wor->player->defense / 2);
				Wor->player->defense += random_protection;
				ExtraDef = true;
			}
			else{ printf("Defense already raised! Try something else\n"); }
		}
		else
		{
			printf("Your protect ability is in cooldown. Time remaining to use it again: %d seconds\n\n", SPECIAL_DEF_CD - ((GetTickCount() - special_def_timer) / 1000));
		}
	}
	else if (tokens[0] == "special")
	{
		if (GetTickCount() - special_att_timer > (SPECIAL_ATT_CD * 1000))
		{
			int damage = Wor->player->attack - enemy->defense;
			int extra_damage = rand() % Wor->player->attack;
			special_att_timer = GetTickCount();
			printf("You used your special attack!!\n");		//special attack can't be dodged
			printf("You hit %s for %i damage.\n\n", enemy->name.c_str(), (damage + extra_damage));
			enemy->hp -= (damage + extra_damage);
		}
		else
		{
			printf("Your special attack is in cooldown. Time remaining to use it again: %d seconds\n\n", SPECIAL_ATT_CD - ((GetTickCount() - special_att_timer) / 1000));
		}
	}
	else if (tokens[0] == "check")
	{
		printf("%s stats:\n", enemy->name.c_str());
		printf("HP: %i.\n", enemy->hp);
		printf("Attack: %i.\n", enemy->attack);
		printf("Defense: %i.\n", enemy->defense);
		printf("Block chance: %i.\n", enemy->block_chance);
		printf("Souls: %i.\n\n", enemy->souls);
	}
	//God Mode
	else if (tokens[0] == "@kill")
	{
		enemy->hp = 0;
		printf("%s defeated\n\n", enemy->name.c_str());
	}
	//
	if (enemy->hp <= 0)
	{
		ExtraDef = false;
		enemy->type = CORPSE;
		CombatMode = false;
		printf("%s died, you received %i souls.\n\n", enemy->name.c_str(), enemy->souls);
		Wor->player->souls += enemy->souls;
	}
}
//--

//Enter combat true/false
bool Player::EnterCombat(Vector<String> &tokens)
{
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		Room* room = (Room*)Wor->entities[i];
		if (room->name == Wor->player->position->name && room->type == ROOM)
		{
			DoubleLinkList<Entity*>::nodeD* room_node = room->list.first_node;
			for (; room_node != nullptr; room_node = room_node->next)
			{
				if (room_node->data->name == tokens[1])
				{
					for (int i = 0; i <= NUM_ENTITIES; i++)
					{
						if (Wor->entities[i]->name == tokens[1] && Wor->entities[i]->type == MONSTER_AGG)
						{
							enemy = (Monster*)Wor->entities[i];
							CombatMode = true;
							int damage = Wor->player->attack - enemy->defense;
							if (damage > 0)
							{
								printf("You hit %s for %i damage.\n\n", enemy->name.c_str(), damage);
								enemy->hp -= damage;
							}
							else { printf("Your attacks seem to do nothing...\n\n"); }
							return true;
						}
						else if (Wor->entities[i]->name == tokens[1] && Wor->entities[i]->type == MONSTER_NON_AGG)
						{
							printf("Why would you like to attack this poor friend...?\n");
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}
//--
#include "World.h"
#include "Items.h"
#include "String.h"
#include "DoubleList.h"

//Look Inventory
void Item::LookInventory(int &InventorySlots)const
{
	DoubleLinkList<Entity*>::nodeD* player_node = Wor->player->list.first_node;
	for (; player_node!=nullptr; player_node = player_node->next)
	{
		if (player_node->data->type == ITEM)
		{
			Item* item = (Item*)Wor->entities[0];
			for (int i = 0; i <= NUM_ENTITIES; i++)
			{
				item = (Item*)Wor->entities[i];
				if (item == player_node->data)
				{
					switch (item->place)
					{
					case EQUIPPED:
						printf("%s(Equipped):  %s\n", player_node->data->name.c_str(), player_node->data->description.c_str());
						break;
					case INVENTORY:
						if (item->fuse == FUSABLE1 || item->fuse == FUSABLE2 || item->fuse == UNFUSABLE)
						{
							printf("%s:  %s\n", player_node->data->name.c_str(), player_node->data->description.c_str());
						}
						else if (item->place == INVENTORY && item->fuse == FUSED)
						{
							printf("%s(Fused):  %s \n", player_node->data->name.c_str(), player_node->data->description.c_str());
						}
						break;
					}
				}
			}
		}
	}
	if (InventorySlots == 0){ printf("Your inventory is empty.\n\n"); }
	else{ printf("Inventory slots: %i/%i.\n\n", InventorySlots, NUM_INVENTORY_SLOTS); }
}
//--

//Pick Items
bool Item::PickItem(Vector<String> &tokens, int &InventorySlots)
{
	if (InventorySlots < NUM_INVENTORY_SLOTS)
	{
		for (int i = 0; i <= NUM_ENTITIES; i++)
		{
			Room* room = (Room*)Wor->entities[i];
			if (room->name == Wor->player->position->name)
			{
				DoubleLinkList<Entity*>::nodeD* room_node = room->list.first_node;
				for (; room_node != nullptr; room_node = room_node->next)
				{
					if (tokens[1] == room_node->data->name)
					{
						printf("%s picked up.\n\n", room_node->data->name.c_str());
						Item* item = (Item*)Wor->entities[0];
						for (int j = 0; j <= NUM_ENTITIES; j++)
						{
							item = (Item*)Wor->entities[j];
							if (item->name == room_node->data->name)
							{ 
								item->place = INVENTORY;
							}
						}
						Wor->player->list.push_back(room_node->data);
						room->list.erase(room_node);
						InventorySlots++;
						return true;
					}
				}
			}
		}
	}
	else{ printf("Inventory full.\n\n"); return true; }
	return false;
}
//--

//Drop Items
bool Item::DropItem(Vector<String> &tokens, int &InventorySlots)
{	
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		Room* room = (Room*)Wor->entities[i];
		if (room->name == Wor->player->position->name && room->type == ROOM)
		{
			DoubleLinkList<Entity*>::nodeD* player_node = Wor->player->list.first_node;
			for (; player_node != nullptr; player_node = player_node->next)
			{
				if (tokens[1] == player_node->data->name)
				{
					for (int j = 0; j <= NUM_ENTITIES; j++)
					{
						Item* item = (Item*)Wor->entities[j];
						if (item->name == player_node->data->name)
						{
							if (item->place == INVENTORY)
							{
								item->place = FLOOR;
								printf("%s dropped on the floor.\n\n", player_node->data->name.c_str());
								room->list.push_back(player_node->data);
								Wor->player->list.erase(player_node);
								InventorySlots--;
								return true;
							}
							else if (item->place == EQUIPPED){ printf("Unequip item first.\n\n"); }
						}
					}
				}
			}
		}
	}
}
//--

//Look Items
void Item::LookItem(Vector<String> &tokens)const
{
	bool ItemCorrect = false;
	DoubleLinkList<Entity*>::nodeD* player_node = Wor->player->list.first_node;
	for (; player_node != nullptr; player_node = player_node->next)
	{
		if (tokens[1] == player_node->data->name)
		{
			printf("%s\n%s\n\n", player_node->data->name.c_str(), player_node->data->description.c_str());
			ItemCorrect = true;
		}
	}
	if (ItemCorrect == false){ printf("You haven't this item.\n\n"); }
}
//--

//Equip Items
bool Item::EquipItem(Vector<String> &tokens, int &WeaponCounter, int &ArmourCounter, int &ShieldCounter, int &QuiverCapacityCounter)
{
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		if (Wor->entities[i]->type == ITEM)
		{
			Item* item = (Item*)Wor->entities[i];
			if ((tokens[1]) == item->name.c_str() && item->place == INVENTORY)
			{
				switch (item->item_type)
				{
				case WEAPON:
					if (WeaponCounter == 1)		//only 1 weapon can be equipped, checks if there is any
					{
						printf("You already have a weapon equipped.\n\n");
						return true;
					}
					else
					{
						if (tokens[1] == "fire bow" || tokens[1] == "ice bow")		//bows stats only added if arrows are in the quiver
						{
							Item* quiver = (Item*)Wor->entities[0];
							for (int i = 0; i <= NUM_ENTITIES; i++)
							{
								if (Wor->entities[i]->name == "quiver")
								{
									quiver = (Item*)Wor->entities[i];
								}
							}
							if (QuiverCapacityCounter > 0 && quiver->place == INVENTORY)		//as only arrows can be put into the quiver, if the capacity of the quiver is > 0 and and it is in the inventory, we will update the player stats
							{
								item->place = EQUIPPED;
								printf("%s equipped.\n\n", item->name.c_str());
								Wor->player->attack += item->value;
								Wor->player->block_chance += item->value2;
								return true;
							}
							else		//in case the previous statments fails, the effects won't apply.
							{
								item->place = EQUIPPED;
								printf("%s equipped, but it won't have effect alone...\nYou should search for arrows and a quiver.\n\n", item->name.c_str());
								return true;
							}
						}
						else
						{
							item->place = EQUIPPED;
							printf("%s equipped.\n\n", item->name.c_str());
							Wor->player->attack += item->value;
							Wor->player->block_chance += item->value2;
							WeaponCounter++;
							return true;
						}
					}
					break;
				case ARMOUR:
					if (ArmourCounter == 1)		//only 1 armour can be equipped, checks if there is any
					{
						printf("You already have an armour equipped.\n\n");
						return true;
					}
					else
					{
						item->place = EQUIPPED;
						printf("%s equipped.\n\n", item->name.c_str());
						Wor->player->defense += item->value;
						Wor->player->block_chance += item->value2;
						ArmourCounter++;
						return true;
					}
					break;
				case SHIELD:
					if (ShieldCounter == 1)		//only 1 shield can be equipped, checks if there is any
					{
						printf("You already have a shield equipped.\n\n");
						return true;
					}
					else
					{
						item->place = EQUIPPED;
						printf("%s equipped.\n\n", item->name.c_str());
						Wor->player->defense += item->value;
						Wor->player->block_chance += item->value2;
						ShieldCounter++;
						return true;
					}
					break;
				case STATUE:
					printf("You can't equip an statue...\n\n");
					return true;
					break;
				case OTHER:
					printf("You can't equip this item...\n\n");
					return true;
					break;
				}
			}
			else if ((tokens[1]) == item->name.c_str() && item->place == EQUIPPED)	{ printf("Item already equipped dude.\n\n");							return true; }
			else if ((tokens[1]) == item->name.c_str() && item->place == FLOOR)		{ printf("Item must be in the inventory in order to equip it.\n\n");	return true; }
		}
	}
	return false;
}
//--

//Unequip Items
bool Item::UnequipItem(Vector<String> &tokens, int &WeaponCounter, int &ArmourCounter, int &ShieldCounter)
{
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		if (Wor->entities[i]->type == ITEM)
		{
			Item* item = (Item*)Wor->entities[i];
			if ((tokens[1]) == item->name.c_str())
			{
				if (item->place == EQUIPPED)
				{
					item->place = INVENTORY;
					switch (item->item_type)
					{
					case WEAPON:
						if (tokens[1] == "fire bow" || tokens[1] == "ice bow")
						{
							if (Wor->player->attack > P_ORI_DAMAGE)
							{
								Wor->player->attack -= item->value;
								Wor->player->block_chance -= item->value2;
							}
							printf("%s unequipped.\n\n", item->name.c_str());
						}
						else
						{
							printf("%s unequipped.\n\n", item->name.c_str());
							Wor->player->attack -= item->value;
							Wor->player->block_chance -= item->value2;
						}
						WeaponCounter--;
						return true;
						break;
					case ARMOUR:
						printf("%s unequipped.\n\n", item->name.c_str());
						Wor->player->defense -= item->value;
						Wor->player->block_chance -= item->value2;
						ArmourCounter--;
						return true;
						break;
					case SHIELD:
						printf("%s unequipped.\n\n", item->name.c_str());
						Wor->player->defense -= item->value;
						Wor->player->block_chance -= item->value2;
						ShieldCounter--;
						return true;
						break;
					case STATUE:
						return false;
						break;
					case OTHER:
						return false;
						break;
					}
				}
				else if (item->place == INVENTORY){ printf("%s is in the inventory.\n\n", item->name.c_str()); return true; }
				else if (item->place == FLOOR){ printf("%s is somewhere in the map...\n\n", item->name.c_str()); return true; }
			}
		}
	}
	return false;
}
//--

//Fuse Items
void Item::FuseItems(Vector<String> &tokens, int &InventoryCapacity, int &QuiverCapacityCounter)
{
	Item* item_1 = (Item*)Wor->entities[0];
	Item* item_2 = (Item*)Wor->entities[0];
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		if (Wor->entities[i]->type == ITEM && tokens[1] == Wor->entities[i]->name)
		{
			item_1 = (Item*)Wor->entities[i]; 
		}
	}
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		if (Wor->entities[i]->type == ITEM && tokens[3] == Wor->entities[i]->name)
		{
			item_2 = (Item*)Wor->entities[i];
		}
	}
	if (item_1->fuse == FUSABLE1 && item_2->fuse == FUSABLE2)		//F1 == can be fused; F2 == can be recipient
	{
		if (item_1->place == INVENTORY && item_2->place == INVENTORY)
		{
			if (item_2->value > QuiverCapacityCounter)
			{
				item_1->fuse = FUSED;
				InventoryCapacity--;
				QuiverCapacityCounter += item_1->value;
				printf("%s put into %s.\n\n", item_1->name.c_str(), item_2->name.c_str());
				//We must search for bows if they are equipped
				Item* fire_bow = (Item*)Wor->entities[0];
				Item* ice_bow = (Item*)Wor->entities[0];
				for (int i = 0; i <= NUM_ENTITIES; i++)
				{
					if (Wor->entities[i]->type == ITEM && Wor->entities[i]->name == "fire bow")
					{
						fire_bow = (Item*)Wor->entities[i];
					}
					if (Wor->entities[i]->type == ITEM && Wor->entities[i]->name == "ice bow")
					{
						ice_bow = (Item*)Wor->entities[i];
					}
				}
				if (fire_bow->place == EQUIPPED && Wor->player->attack == P_ORI_DAMAGE)
				{
					Wor->player->attack += fire_bow->value;
					Wor->player->block_chance += fire_bow->value2;
					printf("The stats from %s are now applied.\n\n", fire_bow->name.c_str());
				}
				else if (ice_bow->place == EQUIPPED && Wor->player->attack == P_ORI_DAMAGE)
				{
					Wor->player->attack += ice_bow->value;
					Wor->player->block_chance += ice_bow->value2;
					printf("The stats from %s are now applied.\n\n", ice_bow->name.c_str());
				}

			}
			else{ printf("The capacity of %s has reached its limit.\n\n", item_2->name.c_str()); }
		}
		else{ printf("Both items must be in the inventory.\n\n"); }
	}
	else if (item_1->fuse == FUSED)		{ printf("%s already fused.\n\n", item_1->name.c_str()); }
	else if (item_1->fuse != FUSABLE1)	{ printf("This can't be put into anything.\n\n", item_1->name.c_str()); }
	else								{ printf("This can't be used as recipient.\n\n", item_2->name.c_str()); }
}
//--

//Unfuse Items
void Item::UnfuseItems(Vector<String> &tokens, int &InventoryCapacity, int &QuiverCapacityCounter)const
{
	Item* item_1 = (Item*)Wor->entities[0];
	Item* item_2 = (Item*)Wor->entities[0];
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		if (Wor->entities[i]->type == ITEM && tokens[1] == Wor->entities[i]->name)
		{
			item_1 = (Item*)Wor->entities[i];
		}
	}
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		if (Wor->entities[i]->type == ITEM && tokens[3] == Wor->entities[i]->name)
		{
			item_2 = (Item*)Wor->entities[i];
		}
	}
	if (item_1->fuse == FUSED && item_2->fuse == FUSABLE2)
	{
		if (item_1->place == INVENTORY && item_2->place == INVENTORY)
		{
			if (InventoryCapacity < NUM_INVENTORY_SLOTS)
			{
				Item* fire_bow = (Item*)Wor->entities[0];
				Item* ice_bow = (Item*)Wor->entities[0];
				for (int i = 0; i <= NUM_ENTITIES; i++)
				{
					if (Wor->entities[i]->type == ITEM && Wor->entities[i]->name == "fire bow")
					{
						fire_bow = (Item*)Wor->entities[i];
					}
					if (Wor->entities[i]->type == ITEM && Wor->entities[i]->name == "ice bow")
					{
						ice_bow = (Item*)Wor->entities[i];
					}
				}
				if (item_1->name == "arrows" && item_2->name == "quiver" && (fire_bow->place == EQUIPPED || ice_bow->place == EQUIPPED))
				{
					printf("You can't get the arrows from the quiver with a bow equipped. What do you want to shot...?\n\n");
				}
				else
				{
					item_1->fuse = FUSABLE1;
					InventoryCapacity++;
					QuiverCapacityCounter -= item_1->value;
					printf("You got the %s from %s.\n\n", item_1->name.c_str(), item_2->name.c_str());
				}
			}
			else{ printf("If you get this item you will excced the inventory limit, drop something first.\n\n"); }
		}
		else{ printf(" both items must be in the inventory.\n\n"); }
	}
	else if (item_1->fuse == FUSABLE1)	{ printf("There are no %s in that.\n\n", item_1->name.c_str()); }
	else								{ printf("This can't be put into anything, so you can't take them from anywhere.\n\n", item_1->name.c_str()); }
}
//--

//Activate Statues
bool Item::ActivateStatue(Vector<String> &tokens, int &ActiveStatues, int &InventorySlots)
{
	if (ActiveStatues < MAX_STATUES_ACTIVATED)
	{
		Item* statue = (Item*)Wor->entities[0];
		for (int i = 0; i <= NUM_ENTITIES; i++)
		{
			if (Wor->entities[i]->type == ITEM && tokens[1] == Wor->entities[i]->name)
			{
				statue = (Item*)Wor->entities[i];
			}
		}
		if (statue->item_type == STATUE)
		{
			if (statue->place == INVENTORY)
			{
				if (statue->state == DESACTIVATED)
				{
					if (statue->name == "hades statue")
					{
						statue->state = ACTIVATED;
						printf("Hades statue activated.\nThis statue upgrades the damages from all bows (including the one that centaur has!!)\n");	
						Item* ice_bow = (Item*)Wor->entities[0];
						Item* fire_bow = (Item*)Wor->entities[0];
						Monster* centaur = (Monster*)Wor->entities[0];
						Item* arrows = (Item*)Wor->entities[0];
						for (int i = 0; i <= NUM_ENTITIES; i++)
						{
							if (Wor->entities[i]->name == "ice bow")
							{
								ice_bow = (Item*)Wor->entities[i];
							}
							if (Wor->entities[i]->name == "fire bow")
							{
								fire_bow = (Item*)Wor->entities[i];
							}
							if (Wor->entities[i]->name == "centaur")
							{
								centaur = (Monster*)Wor->entities[i];
							}
							if (Wor->entities[i]->name == "arrows")
							{
								arrows = (Item*)Wor->entities[i];
							}
						}
						ice_bow->value += 50;
						fire_bow->value += 50;
						centaur->attack += 50;
						if ((ice_bow->place == EQUIPPED || fire_bow->place == EQUIPPED) && arrows->fuse == FUSED)
						{
							Wor->player->attack += 50;
						}
						ActiveStatues++;
						return true;
					}
					else if (statue->name == "hephaestus statue")
					{
						bool StatueUsed = false;
						bool WeapDone = false;
						bool ArmDone = false;
						bool ShiDone = false;
						Item* to_updrage = (Item*)Wor->entities[0];
						for (int i = 0; i <= NUM_ENTITIES; i++)
						{
							if (Wor->entities[i]->type == ITEM)
							{
								to_updrage = (Item*)Wor->entities[i];

								if (to_updrage->place == EQUIPPED)
								{
									switch (to_updrage->item_type)
									{
									case WEAPON:
										if (WeapDone == false)
										{
											to_updrage->value += 50;		//Upgrade weapon stats
											to_updrage->value2 += 8;
											to_updrage->upgrade = UPGRADED;
											to_updrage->description += "\tThis item is upgraded.\n\tIt has a bonus of 50 damage and 8 block chance.\n\n";
											Wor->player->attack += 50;		//Same for the player (as the items are equipped)
											Wor->player->block_chance += 8;
											printf("Weapon upgrade complete.\n");
											StatueUsed = true;
											WeapDone = true;
										}
										break;
									case ARMOUR:
										if (ArmDone == false)
										{
											to_updrage->value += 40;		//Upgrade armour stats
											to_updrage->value2 += 15;
											to_updrage->upgrade = UPGRADED;
											to_updrage->description += "\tThis item is upgraded.\n\tIt has a bonus of 40 defense and 15 block chance.\n\n";
											Wor->player->defense += 40;		//Same for the player (as the items are equipped)
											Wor->player->block_chance += 15;
											printf("Armour upgrade complete.\n");
											StatueUsed = true;
											ArmDone = true;
										}
										break;
									case SHIELD:
										if (ShiDone == false)
										{
											to_updrage->value += 30;		//Upgrade shield stats
											to_updrage->value2 += 25;
											to_updrage->upgrade = UPGRADED;
											to_updrage->description += "\tThis item is upgraded.\n\tIt has a bonus of 30 defense and 25 block chance.\n\n";
											Wor->player->defense += 30;		//Same for the player (as the items are equipped)
											Wor->player->block_chance += 25;
											printf("Shield upgrade complete.\n");
											StatueUsed = true;
											ShiDone = true;
										}
										break;
									}
								}
							}
						}
						if (StatueUsed == true)
						{
							printf("This statue disappeared!!\n\n");
							statue->state = DESTROYED;
							statue->place = DISAPPEARED;
							InventorySlots--;	//if it dissapears -> free slot in the inventory
							return true;
						}
						if (StatueUsed == 0){ printf("Activation failed.\n\n"); return true; }
					}
					else if (statue->name == "aphrodite statue")
					{
						statue->state = ACTIVATED;
						printf("Aphrodite statue activated.\n\n");
						ActiveStatues++;
						return true;
					}
					else if (statue->name == "chronos statue")
					{
						statue->state = ACTIVATED;
						printf("Chronos statue activated.\n\n");
						Wor->player->special_att_cd -= statue->value;
						Wor->player->special_def_cd -= statue->value2;
						ActiveStatues++;
						return true;
					}
				}
				else if (statue->state == ACTIVATED){ printf("%s is already activated.\n\n", statue->name.c_str()); return true; }
				else if (statue->state == DESTROYED){ printf("%s had been destroyed.\n\n", statue->name.c_str()); return true; }
			}
			else{ printf("%s must be in the inventory to be activated.\n\n", statue->name.c_str()); return true; }
		}
		else{ printf("This item is not an statue. Only statues can be activated.\n\n"); return true; }
	}
	else{ printf("You have the maximum number of statues activated.\n\n"); return true; }
	return false;
}
//--

//Desactivate Statues
bool Item::DesactivateStatue(Vector<String> &tokens, int &ActiveStatues)
{
	Item* statue = (Item*)Wor->entities[0];
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		if (Wor->entities[i]->type == ITEM && tokens[1] == Wor->entities[i]->name)
		{
			statue = (Item*)Wor->entities[i];
		}
	}
	if (statue->item_type == STATUE)
	{
		if (statue->place == INVENTORY)
		{
			if (statue->state == ACTIVATED)
			{
				if (statue->name == "hades statue")
				{
					statue->state = DESACTIVATED;
					printf("Hades statue desactivated.\n\n");
					Item* ice_bow = (Item*)Wor->entities[0];
					Item* fire_bow = (Item*)Wor->entities[0];
					Monster* centaur = (Monster*)Wor->entities[0];
					Item* arrows = (Item*)Wor->entities[0];
					for (int i = 0; i <= NUM_ENTITIES; i++)
					{
						if (Wor->entities[i]->name == "ice bow")
						{
							ice_bow = (Item*)Wor->entities[i];
						}
						if (Wor->entities[i]->name == "fire bow")
						{
							fire_bow = (Item*)Wor->entities[i];
						}
						if (Wor->entities[i]->name == "centaur")
						{
							centaur = (Monster*)Wor->entities[i];
						}
						if (Wor->entities[i]->name == "arrows")
						{
							arrows = (Item*)Wor->entities[i];
						}
					}
					ice_bow->value -= 50;
					fire_bow->value -= 50;
					centaur->attack -= 50;
					if ((ice_bow->place == EQUIPPED || fire_bow->place == EQUIPPED) && arrows->fuse == FUSED)
					{
						Wor->player->attack -= 50;
					}
					ActiveStatues--;
					return true;
				}
				else if (statue->name == "aphrodite statue")
				{
					statue->state = DESACTIVATED;
					printf("Aphrodite statue desactivated.\n\n");
					ActiveStatues--;
					return true;
				}
				else if (statue->name == "chronos statue")
				{
					statue->state = DESACTIVATED;
					printf("Chronos statue desactivated.\n\n");
					Wor->player->special_att_cd += statue->value;
					Wor->player->special_def_cd += statue->value2;
					ActiveStatues--;
					return true;
				}
			}
			else if (statue->state == DESACTIVATED){ printf("%s is already desactivated.\n\n", statue->name.c_str()); return true; }
			else if (statue->state == DESTROYED){ printf("%s had been destroyed.\n\n", statue->name.c_str()); return true; }
		}
		else{ printf("%s must be in the inventory to be activated.\n\n", statue->name.c_str()); return true; }
	}
	else{ printf("This item is not an statue. Only statues can be activated and desactivated.\n\n"); return true; }
	return false;
}
//--

//Items Update
//Aphrodite statue activated will heal you over time
void Item::Update()
{
	Item* aphrodite_statue = (Item*)Wor->entities[0];
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		if (Wor->entities[i]->name == "aphrodite statue")
		{
			aphrodite_statue = (Item*)Wor->entities[i];
			if (aphrodite_statue->state == ACTIVATED && Wor->player->hp < P_ORI_HP)
			{
				printf("Aphrodite statue is healing you!\n");
				Wor->player->hp += aphrodite_statue->value;
				if (Wor->player->hp >= P_ORI_HP){ Wor->player->hp = P_ORI_HP; }
				printf("HP:%i / %i\n\n", Wor->player->hp, P_ORI_HP);
			}
		}
	}	
}
//--
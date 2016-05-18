#include "World.h"
#include "Items.h"
#include "String.h"

//Look Inventory
void Item::LookInventory(int &InventorySlots)const
{
	Item* item = (Item*)Wor->entities[0];
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		if (Wor->entities[i]->type == ITEM)
		{
			item = (Item*)Wor->entities[i];
			if (item->place == EQUIPPED)
			{
				printf("%s(Equipped):  %s\n", item->name.c_str(), item->description.c_str());
			}
			if (item->place == INVENTORY && (item->fuse == FUSABLE1 || item->fuse == FUSABLE2 || item->fuse == UNFUSABLE)){
				printf("%s:  %s\n", item->name.c_str(), item->description.c_str());
			}
			if (item->place == INVENTORY && item->fuse == FUSED){
				printf("%s(Fused):  %s \n", item->name.c_str(), item->description.c_str());
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
	Item* item = (Item*)Wor->entities[0];
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
		if (Wor->entities[i]->type == ITEM)
		{
			item = (Item*)Wor->entities[i];
			
			if ((tokens[1]) == item->name.c_str() && item->item_position == player->position)
			{
				if (item->place == FLOOR)
				{
					if (InventorySlots < NUM_INVENTORY_SLOTS)
					{
						printf("%s picked up.\n\n", item->name.c_str());
						item->place = INVENTORY;
						InventorySlots++;
						return true;
					}
					else{ printf("Inventory full.\n\n"); return true; }
				}
				else{ printf("%s is already in the inventory.\n\n", item->name.c_str()); return true; }
			}
		}
	}
	return false;
}
//--

//Drop Items
bool Item::DropItem(Vector<String> &tokens, int &InventorySlots)
{
	Item* item = (Item*)Wor->entities[0];
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
		if (Wor->entities[i]->type == ITEM)
		{
			item = (Item*)Wor->entities[i];
		
			if ((tokens[1]) == item->name.c_str() && item->place == INVENTORY)
			{
				if (item->fuse != FUSED)
				{
					if (item->name.c_str() != "arrows" || item->name.c_str() != "quiver")
					{
						printf("%s dropped on the floor.\n\n", item->name.c_str());		//TODO: active statues cant be dropped
						item->place = FLOOR;
						item->item_position = player->position;
						InventorySlots--;
						return true;
					}
					/*else
					{
					for (int i = 0; i <= NUM_ENTITIES; i++)
					{
					if (Wor->entities[i]->name.ContainsString("bow") == true)
					{
					item = (Item*)Wor->entities[i];
					if (item->place == EQUIPPED)
					{
					printf("Unequip your bow first, you can't use it without arrows or the quiver.\n\n");
					return true;
					}
					}
					}
					}*/
				}
				else{ printf("To drop an item it can't be into another item.\n\n"); return true; }
			}
		}
	}
}
//--

//Look Items
void Item::LookItem(Vector<String> &tokens)const
{
	bool ItemCorrect = false;
	
	Item* item = (Item*)Wor->entities[0];
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		if (Wor->entities[i]->type == ITEM)
		{
			item = (Item*)Wor->entities[i];			
			if ((tokens[1]) == item->name.c_str() && (item->place == INVENTORY || item->place == EQUIPPED))
			{
				printf("%s\n%s\n\n", item->name.c_str(), item->description.c_str());
				ItemCorrect = true;
			}
		}
	}
	if (ItemCorrect == false) { printf("You haven't this item.\n\n"); }
}
//--

//Equip Items
bool Item::EquipItem(Vector<String> &tokens, int &WeaponCounter, int &ArmourCounter, int &ShieldCounter, int &QuiverCapacityCounter)
{
	
	Player* player = (Player*)Wor->entities[0];
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		if (Wor->entities[i]->type == PLAYER)
		{
			player = (Player*)Wor->entities[i];
		}
	}
	Item* item = (Item*)Wor->entities[0];
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		if (Wor->entities[i]->type == ITEM)
		{
			item = (Item*)Wor->entities[i];			
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
								player->attack += item->value;
								player->block_chance += item->value2;
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
							player->attack += item->value;
							player->block_chance += item->value2;
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
						player->defense += item->value;
						player->block_chance += item->value2;
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
						player->defense += item->value;
						player->block_chance += item->value2;
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
	Player* player = (Player*)Wor->entities[0];
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		if (Wor->entities[i]->type == PLAYER)
		{
			player = (Player*)Wor->entities[i];
		}
	}
	Item* item = (Item*)Wor->entities[0];
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		if (Wor->entities[i]->type == ITEM)
		{
			item = (Item*)Wor->entities[i];
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
							if (player->attack > P_ORI_DAMAGE)
							{
								player->attack -= item->value;
								player->block_chance -= item->value2;
							}
							printf("%s unequipped.\n\n", item->name.c_str());
						}
						else
						{
							printf("%s unequipped.\n\n", item->name.c_str());
							player->attack -= item->value;
							player->block_chance -= item->value2;
						}
						WeaponCounter--;
						return true;
						break;
					case ARMOUR:
						printf("%s unequipped.\n\n", item->name.c_str());
						player->defense -= item->value;
						player->block_chance -= item->value2;
						ArmourCounter--;
						return true;
						break;
					case SHIELD:
						printf("%s unequipped.\n\n", item->name.c_str());
						player->defense -= item->value;
						player->block_chance -= item->value2;
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
	Player* player = (Player*)Wor->entities[0];
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		if (Wor->entities[i]->type == PLAYER)
		{
			player = (Player*)Wor->entities[i];
		}
	}
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
				if (fire_bow->place == EQUIPPED && player->attack == P_ORI_DAMAGE)
				{
					player->attack += fire_bow->value;
					player->block_chance += fire_bow->value2;
					printf("The stats from %s are now applied.\n\n", fire_bow->name.c_str());
				}
				else if (ice_bow->place == EQUIPPED && player->attack == P_ORI_DAMAGE)
				{
					player->attack += ice_bow->value;
					player->block_chance += ice_bow->value2;
					printf("The stats from %s are now applied.\n\n", ice_bow->name.c_str());
				}

			}
			else{ printf("The capacity of %s has reached its limit.\n\n", item_2->name.c_str()); }
		}
		else{ printf("Both items must be in the inventory.\n\n"); }
	}
	else if (item_1->fuse == FUSED)		{ printf("%s already fused.\n\n", item_1->name.c_str()); }
	else if (item_1->fuse != FUSABLE1)	{ printf("%s can't be put into anything.\n\n", item_1->name.c_str()); }
	else								{ printf("%s can't be used as recipient.\n\n", item_2->name.c_str()); }
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
	else								{ printf("%s can't be put into anything, so you can't take them from anywhere.\n\n", item_1->name.c_str()); }
}
//--
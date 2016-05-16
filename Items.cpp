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
bool Item::PickItem(Vector<String> &tokens, int &InventorySlots, int num_words)
{
	Item* item = (Item*)Wor->entities[0];
	Player* player = (Player*)Wor->entities[0];
	if (num_words == 3)
	{
		tokens[1] += " ";
	}
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
			if (num_words == 3)
			{
				if ((tokens[1] + tokens[2]) == item->name.c_str() && item->item_position == player->position)
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
			else if (num_words == 2)
			{
				if (tokens[1] == item->name.c_str() && item->item_position == player->position)
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
	}
	return false;
}
//--

//Drop Items
bool Item::DropItem(Vector<String> &tokens, int &InventorySlots, int num_words)
{
	Item* item = (Item*)Wor->entities[0];
	Player* player = (Player*)Wor->entities[0];
	if (num_words == 3)
	{
		tokens[1] += " ";
	}
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
			if (num_words == 3)
			{
				if ((tokens[1] + tokens[2]) == item->name.c_str() && item->place == INVENTORY)
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
			else if (num_words == 2)
			{
				if (tokens[1] == item->name.c_str() && item->place == INVENTORY)
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
}
//--

//Look Items
void Item::LookItem(Vector<String> &tokens, int num_words)const
{
	bool ItemCorrect = false;
	if (num_words == 3)
	{
		tokens[1] += " ";
	}
	Item* item = (Item*)Wor->entities[0];
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		if (Wor->entities[i]->type == ITEM)
		{
			item = (Item*)Wor->entities[i];
			if (num_words == 3)
			{
				if ((tokens[1] + tokens[2]) == item->name.c_str() && (item->place == INVENTORY || item->place == EQUIPPED))
				{
					printf("%s\n%s\n\n", item->name.c_str(), item->description.c_str());
					ItemCorrect = true;
				}
			}
			else if (num_words == 2)
			{
				if ((tokens[1]) == item->name.c_str() && (item->place == INVENTORY || item->place == EQUIPPED))
				{
					printf("%s\n%s\n\n", item->name.c_str(), item->description.c_str());
					ItemCorrect = true;
				}
			}
		}
	}
	if (ItemCorrect == false) { printf("You haven't this item.\n\n"); }
}
//--
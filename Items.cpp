#include "World.h"
#include "Items.h"

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

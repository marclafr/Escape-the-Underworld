#include "World.h"

//Pick items
bool Item::PickItem(Vector<String> tokens, int &InventorySlots, unsigned int num_words){
	if (num_words == 2){
		for (int i = 0; i < NUM_1_WORD_ITEMS; i++){
			if (tokens[1] == Wor->items[i]->name.c_str()){		//looks for the item
				if (Wor->items[i]->item_position->name == Wor->player.position->name){	//comproves that the item is in the same room as the player
					if (Wor->items[i]->place == FLOOR){			//checks if the item is in the floor
						if (InventorySlots < NUM_INVENTORY_SLOTS){	//checks if the inventory is full
							printf("%s picked up.\n\n", Wor->items[i]->name.c_str());
							Wor->items[i]->place = INVENTORY;
							InventorySlots++;
							return true;
						}
						else{
							printf("Inventory full.\n\n");
							return true;
						}
					}
					else{
						printf("Item already in the inventory.\n\n");
						return true;
					}
				}
			}
		}
	}
	if (num_words == 3){
		for (int i = 0; i < NUM_2_WORD_ITEMS; i++){
			if (tokens[1] == Wor->item_tokens[i * 2] && tokens[2] == Wor->item_tokens[i * 2 + 1]){		//looks for the item
				if (Wor->items[i + NUM_1_WORD_ITEMS]->item_position->name == Wor->player.position->name){		//comproves that the item is in the same room as the player
					if (Wor->items[i + NUM_1_WORD_ITEMS]->place == FLOOR){			//checks if the item is in the floor
						if (InventorySlots < NUM_INVENTORY_SLOTS){				//checks if the inventory is full
							printf("%s %s picked up.\n\n", Wor->item_tokens[i * 2].c_str(), Wor->item_tokens[i * 2 + 1].c_str());
							Wor->items[i + NUM_1_WORD_ITEMS]->place = INVENTORY;
							InventorySlots++;
							return true;
						}
						else{
							printf("Inventory full.\n\n");
							return true;
						}
					}
					else{
						printf("Item already in the inventory.\n\n");
						return true;
					}
				}
			}
		}
	}
	return false;
}
//--

//Look at the inventory list
bool Item::LookInventory(int &InventorySlots)const{
	int empty_inventory = 0;
	printf("\n");
	//Items that have 1 word:
	for (int i = 0; i < NUM_1_WORD_ITEMS; i++){
		if (Wor->items[i]->place == EQUIPPED){
			printf("%s(Equipped):  %s\n", Wor->items[i]->name.c_str(), Wor->items[i]->description.c_str());
			empty_inventory = 1;
		}
		if (Wor->items[i]->place == INVENTORY && (Wor->items[i]->fuse == FUSABLE1 || Wor->items[i]->fuse == FUSABLE2 || Wor->items[i]->fuse == UNFUSABLE)){
			printf("%s:  %s\n", Wor->items[i]->name.c_str(), Wor->items[i]->description.c_str());
			empty_inventory = 1;
		}
		if (Wor->items[i]->place == INVENTORY && Wor->items[i]->fuse == FUSED){
			printf("%s(Fused):  %s \n", Wor->items[i]->name.c_str(), Wor->items[i]->description.c_str());
			empty_inventory = 1;
		}
	}
	//Items that have 2 words:
	for (int i = 0; i < NUM_2_WORD_ITEMS; i++){
		if (Wor->items[i + NUM_1_WORD_ITEMS]->place == EQUIPPED){
			printf("%s %s(Equipped):  %s\n", Wor->item_tokens[i * 2].c_str(), Wor->item_tokens[i * 2 + 1].c_str(), Wor->items[i + NUM_1_WORD_ITEMS]->description.c_str());
			empty_inventory = 1;
		}
		if (Wor->items[i + NUM_1_WORD_ITEMS]->place == INVENTORY){
			printf("%s %s:  %s\n", Wor->item_tokens[i * 2].c_str(), Wor->item_tokens[i * 2 + 1].c_str(), Wor->items[i + NUM_1_WORD_ITEMS]->description.c_str());
			empty_inventory = 1;
		}
		//No need to check if it is fused because there is no 2 words item that can be fused.
	}
	printf("Inventory slots: %i/%i.\n\n", InventorySlots, NUM_INVENTORY_SLOTS);
	if (empty_inventory == 1){ return true; }
	else{ return false; }
}
//--

//Drop an item
bool Item::DropItem(Vector<String> tokens, int &InventorySlots, unsigned int num_words){
	if (num_words == 2){
		for (int i = 0; i < NUM_1_WORD_ITEMS; i++){
			if (tokens[1] == Wor->items[i]->name.c_str()){		//looks for the correct item
				if (Wor->items[i]->place == INVENTORY){			//checks if the item is in the inventory
					if (Wor->items[i]->fuse != FUSED){			//checks that the item isn't fused
						if ((Wor->items[i]->name == "arrows" || Wor->items[i]->name == "quiver") && (Wor->items[NUM_1_WORD_ITEMS]->place == EQUIPPED || Wor->items[NUM_1_WORD_ITEMS + 1]->place == EQUIPPED)){
							printf("Unequip your bow first, you can't use it without arrows or the quiver.\n\n");
							return true;
						}
						else{
							printf("%s dropped on the floor.\n\n", Wor->items[i]->name.c_str());		//TODO: active statues cant be dropped && quiver w/ arrows can't be dropped if a bow is equipped
							Wor->items[i]->place = FLOOR;
							Wor->items[i]->item_position = Wor->player.position;
							InventorySlots--;
							return true;
						}
					}
					else{
						printf("To drop an item it can't be into another item.\n\n");
						return true;
					}
				}
			}
		}
	}
	else if (num_words == 3) {
		for (int i = 0; i < NUM_2_WORD_ITEMS; i++){
			if (tokens[1] == Wor->item_tokens[i * 2]){				//looks for the correct item
				if (Wor->items[i + NUM_1_WORD_ITEMS]->place == INVENTORY){		//checks if the item is in the inventory
					printf("%s %s dropped on the floor.\n\n", Wor->item_tokens[i * 2].c_str(), Wor->item_tokens[i * 2 + 1].c_str());	//no need to check if it is fused because there is no 2 words item that can be fused
					Wor->items[i + NUM_1_WORD_ITEMS]->place = FLOOR;
					Wor->items[i + NUM_1_WORD_ITEMS]->item_position = Wor->player.position;
					InventorySlots--;
					return true;
				}
			}
		}
	}
	return false;
}
//--

//Look an item description
//1 word items
void Item::LookItem(String item_w1)const{
	int IncorrectItem = 0; //if an incorrect item is given	
	for (int i = 0; i < NUM_1_WORD_ITEMS; i++){
		if (Wor->items[i]->name == item_w1.c_str()){				//looks for the correct item
			if (Wor->items[i]->place == INVENTORY || Wor->items[i]->place == EQUIPPED){		//check that the item is in the inventory or equipped
				printf("%s\n%s\n", Wor->items[i]->name.c_str(), Wor->items[i]->description.c_str());
				IncorrectItem = 1;
			}
		}
	}
	if (IncorrectItem == 0){ printf("This item isn't in your inventory or equipped.\n\n"); }
}

//2 words items
void Item::LookItem(String item_w1, String item_w2)const{
	int IncorrectItem = 0; //if an incorrect item is given
	for (int i = 0; i < NUM_2_WORD_ITEMS; i++){
		if (Wor->item_tokens[i * 2] == item_w1 && Wor->item_tokens[i * 2 + 1] == item_w2){		//looks for the correct item
			if (Wor->items[i + NUM_1_WORD_ITEMS]->place == INVENTORY || Wor->items[i + NUM_1_WORD_ITEMS]->place == EQUIPPED){			//checks if the item is in the inventory or equipped
				printf("%s %s\n%s\n", Wor->item_tokens[i * 2].c_str(), Wor->item_tokens[i * 2 + 1].c_str(), Wor->items[i + NUM_1_WORD_ITEMS]->description.c_str());
				IncorrectItem = 1;
			}
		}
	}
	if (IncorrectItem == 0){ printf("This item isn't in your inventory or equipped.\n\n"); }
}
//--

//Equip an item
bool Item::EquipItem(Vector<String> tokens, int &WeaponCounter, int &ArmourCounter, int &ShieldCounter, int &QuiverCapacityCounter, unsigned int num_words){
	if (num_words == 2){
		for (int i = 0; i < NUM_1_WORD_ITEMS; i++){
			if (tokens[1] == Wor->items[i]->name.c_str()){		//looks for the item
				if (Wor->items[i]->place == INVENTORY){			//checks that the item is in the inventory
					if (Wor->items[i]->type == WEAPON){			//if it is a weapon:
						if (WeaponCounter == 1){			//only 1 weapon can be equipped, checks if there is any
							printf("You already have a weapon equipped.\n\n");
							return true;
						}
						else{
							if (Wor->items[i]->name == "arrows"){
								printf("You can't equip arrows, put them in a quiver :)\n\n");
								return true;
							}
							else{
								Wor->items[i]->place = EQUIPPED;
								printf("%s equipped.\n\n", Wor->items[i]->name.c_str());
								Wor->player.attack += Wor->items[i]->value;
								Wor->player.block_chance += Wor->items[i]->value2;
							}
							WeaponCounter++;
							return true;
						}
					}
					else if (Wor->items[i]->type == ARMOUR){		//if it is an armour
						if (ArmourCounter == 1){			//only 1 armour can be equipped, checks if there is any
							printf("You already have an armour equipped.\n\n");
							return true;
						}
						else{
							Wor->items[i]->place = EQUIPPED;
							printf("%s equipped.\n\n", Wor->items[i]->name.c_str());
							Wor->player.defense += Wor->items[i]->value;
							Wor->player.block_chance += Wor->items[i]->value2;
							ArmourCounter++;
						}
						return true;
					}
					else if (Wor->items[i]->type == SHIELD){		//if it is a shield
						if (ShieldCounter == 1){			//only 1 shield can be equipped, checks if there is any
							printf("You already have a shield equipped.\n\n");
							return true;
						}
						else{
							Wor->items[i]->place = EQUIPPED;
							printf("%s equipped.\n\n", Wor->items[i]->name.c_str());
							Wor->player.defense += Wor->items[i]->value;
							Wor->player.block_chance += Wor->items[i]->value2;
							ShieldCounter++;
						}
						return true;
					}
				}
				if (Wor->items[i]->type == WEAPON || Wor->items[i]->type == ARMOUR || Wor->items[i]->type == SHIELD){		//if the item is not in the inventory:
					if (Wor->items[i]->place == EQUIPPED){ printf("Item already equipped dude.\n\n"); }
					else if (Wor->items[i]->place == FLOOR) { printf("Item must be in the inventory in order to equip it.\n\n"); }
					return true;
				}
				else{		//if the item isnt a weapon, an armour or a shield you can't equip them
					printf("You can't equip this item\n\n");
					return true;
				}
			}
		}
	}
	else if (num_words == 3){
		int QuiverPosition = 0;
		for (int i = 0; i < NUM_2_WORD_ITEMS; i++){
			if (tokens[1] == Wor->item_tokens[i * 2] && tokens[2] == Wor->item_tokens[i * 2 + 1]){	//looks for the item
				if (Wor->items[i + NUM_1_WORD_ITEMS]->place == INVENTORY){	//checks if the item is in the inventory
					if (Wor->items[i + NUM_1_WORD_ITEMS]->type == WEAPON){	//if it is a weapon
						if (WeaponCounter == 1){						//only 1 weapon can be equipped, checks if there is any
							printf("You already have a weapon equipped.\n\n");
							return true;
						}
						else{
							Wor->items[i + NUM_1_WORD_ITEMS]->place = EQUIPPED;
							if (tokens[2] == "bow"){				//special case: if it is a bow you need to have the arrows put into the quiver to get the stats bonus
								for (int j = 0; j < NUM_1_WORD_ITEMS; j++){
									Wor->items[QuiverPosition]->name == "quiver";
									QuiverPosition = j;			//saves the number of item of the quiver (in case we want to add more items we don't need to worry to find it).
								}
								if (QuiverCapacityCounter > 0 && Wor->items[QuiverPosition]->place == INVENTORY){	//as only arrows can be put into the quiver, if the capacity of the quiver is > 0 
									printf("%s equipped.\n\n", Wor->items[i + NUM_1_WORD_ITEMS]->name.c_str());		//and and it is in the inventory, we will update the player stats
									Wor->player.attack += Wor->items[i + NUM_1_WORD_ITEMS]->value;
									Wor->player.block_chance += Wor->items[i + NUM_1_WORD_ITEMS]->value2;

								}
								else{	//in case the previous statments fails, the effects won't apply.
									printf("%s %s equipped, but it won't have effect alone...\nYou shouls search for arrows and a quiver.\n\n", Wor->item_tokens[i * 2].c_str(), Wor->item_tokens[i * 2 + 1].c_str());
								}
								WeaponCounter++;
								return true;
							}
							else{		//rest of weapons that aren't bows
								printf("%s equipped.\n\n", Wor->items[i + NUM_1_WORD_ITEMS]->name.c_str());
								Wor->player.attack += Wor->items[i + NUM_1_WORD_ITEMS]->value;
								Wor->player.block_chance += Wor->items[i + NUM_1_WORD_ITEMS]->value2;
							}
							WeaponCounter++;
							return true;
						}
					}
					if (Wor->items[i + NUM_1_WORD_ITEMS]->type == ARMOUR){	//if it is an armour
						if (ArmourCounter == 1){						//only 1 armour can be equipped, checks if there is any
							printf("You already have an armour equipped.\n\n");
							return true;
						}
						else{
							Wor->items[i + NUM_1_WORD_ITEMS]->place = EQUIPPED;
							printf("%s equipped.\n\n", Wor->items[i + NUM_1_WORD_ITEMS]->name.c_str());
							Wor->player.defense += Wor->items[i + NUM_1_WORD_ITEMS]->value;
							Wor->player.block_chance += Wor->items[i + NUM_1_WORD_ITEMS]->value2;
							ArmourCounter++;
							return true;
						}
					}
					if (Wor->items[i + NUM_1_WORD_ITEMS]->type == SHIELD){	//if it is a shield
						if (ShieldCounter == 1){						//only 1 shield can be equipped, checks if there is any
							printf("You already have a shield equipped.\n\n");
							return true;
						}
						else{
							Wor->items[i + NUM_1_WORD_ITEMS]->place = EQUIPPED;
							printf("%s equipped.\n\n", Wor->items[i + NUM_1_WORD_ITEMS]->name.c_str());
							Wor->player.defense += Wor->items[i + NUM_1_WORD_ITEMS]->value;
							Wor->player.block_chance += Wor->items[i + NUM_1_WORD_ITEMS]->value2;
							ShieldCounter++;
							return true;
						}
					}
					else { printf("You can't equip this item.\n\n"); }		//if the item isnt a weapon, an armour or a shield you can't equip them
				}
				//if the item is not in the inventory:
				else if (Wor->items[i + NUM_1_WORD_ITEMS]->place == EQUIPPED){ printf("Item already equipped dude.\n\n"); }
				else if (Wor->items[i + NUM_1_WORD_ITEMS]->place == FLOOR) { printf("Item must be in the inventory in order to equip it.\n\n"); }
				return true;
			}
		}
	}
	return false;
}
//--

//Unequip an item
bool Item::UnequipItem(Vector<String> tokens, int &WeaponCounter, int &ArmourCounter, int &ShieldCounter, unsigned int num_words){
	if (num_words == 2){
		for (int i = 0; i < NUM_1_WORD_ITEMS; i++){
			if (tokens[1] == Wor->items[i]->name.c_str()){		//looks for the item
				if (Wor->items[i]->place == EQUIPPED){			//checks that the item is equipped
					if (Wor->items[i]->type == WEAPON){			//in case it is a weapon:
						Wor->items[i]->place = INVENTORY;
						printf("%s unequipped.\n\n", Wor->items[i]->name.c_str());
						Wor->player.attack -= Wor->items[i]->value;
						Wor->player.block_chance -= Wor->items[i]->value2;
						WeaponCounter--;
						return true;
					}
					else if (Wor->items[i]->type == ARMOUR){		//in case it is an armour
						Wor->player.defense -= Wor->items[i]->value;
						Wor->player.block_chance -= Wor->items[i]->value2;
						ArmourCounter--;
						return true;
					}
					else if (Wor->items[i]->type == SHIELD){		//in case it is a shield
						Wor->player.defense -= Wor->items[i]->value;
						Wor->player.block_chance -= Wor->items[i]->value2;
						ShieldCounter--;
						return true;
					}
				}
				if (Wor->items[i]->type == WEAPON || Wor->items[i]->type == ARMOUR || Wor->items[i]->type == SHIELD){
					if (Wor->items[i]->name == "arrows"){ printf("You serious...?\n\n"); }	//you can't equip arrows, only put them into quiver.
					else if (Wor->items[i]->place == INVENTORY){ printf("Item is in the inventory dude.\n\n"); }
					else if (Wor->items[i]->place == FLOOR) { printf("This item is somewhere in the map...\n\n"); }
					return true;
				}
				else{		//items that are not weapons, armours or shields can't be equipped and so, unequipped.
					printf("You can't equip/unequip this item.\n\n");
					return true;
				}
			}
		}
	}
	else if (num_words == 3){
		for (int i = 0; i < NUM_2_WORD_ITEMS; i++){
			if (tokens[1] == Wor->item_tokens[i * 2] && tokens[2] == Wor->item_tokens[i * 2 + 1]){		//looks for the item
				if (Wor->items[i + NUM_1_WORD_ITEMS]->place == EQUIPPED){				//checks the item is equipped
					Wor->items[i + NUM_1_WORD_ITEMS]->place = INVENTORY;
					if (Wor->items[i + NUM_1_WORD_ITEMS]->type == WEAPON){
						if (tokens[2] == "bow"){			//special case: bows: if the bow equippment didnt raise the stats, the unequip neither.
							if (Wor->player.attack > PLAYER_ORIGINAL_DAMAGE){		//if the player has more than its original damage it means it has a weapon
								Wor->player.attack -= Wor->items[i + NUM_1_WORD_ITEMS]->value;
								Wor->player.block_chance -= Wor->items[i + NUM_1_WORD_ITEMS]->value2;
							}
							printf("%s %s unequipped.\n\n", Wor->item_tokens[i * 2].c_str(), Wor->item_tokens[i * 2 + 1].c_str());
						}
						else{		//other weapons
							printf("%s %s unequipped.\n\n", Wor->item_tokens[i * 2].c_str(), Wor->item_tokens[i * 2 + 1].c_str());
							Wor->player.attack -= Wor->items[i + NUM_1_WORD_ITEMS]->value;
							Wor->player.block_chance -= Wor->items[i + NUM_1_WORD_ITEMS]->value2;
						}
						WeaponCounter--;
						return true;
					}
					if (Wor->items[i + NUM_1_WORD_ITEMS]->type == ARMOUR){		//armours
						printf("%s %s unequipped.\n\n", Wor->item_tokens[i * 2].c_str(), Wor->item_tokens[i * 2 + 1].c_str());
						Wor->player.defense -= Wor->items[i + NUM_1_WORD_ITEMS]->value;
						Wor->player.block_chance -= Wor->items[i + NUM_1_WORD_ITEMS]->value2;
						ArmourCounter--;
						return true;
					}
					if (Wor->items[i + NUM_1_WORD_ITEMS]->type == SHIELD){		//shields
						printf("%s %s unequipped.\n\n", Wor->item_tokens[i * 2].c_str(), Wor->item_tokens[i * 2 + 1].c_str());
						Wor->player.defense -= Wor->items[i + NUM_1_WORD_ITEMS]->value;
						Wor->player.block_chance -= Wor->items[i + NUM_1_WORD_ITEMS]->value2;
						ShieldCounter--;
						return true;
					}
				}
				if (Wor->items[i + NUM_1_WORD_ITEMS]->type == WEAPON || Wor->items[i + NUM_1_WORD_ITEMS]->type == ARMOUR || Wor->items[i + NUM_1_WORD_ITEMS]->type == SHIELD){
					if (Wor->items[i + NUM_1_WORD_ITEMS]->place == INVENTORY){ printf("Item is in the inventory dude.\n\n"); }
					else if (Wor->items[i + NUM_1_WORD_ITEMS]->place == FLOOR) { printf("This item is somewhere in the map...\n\n"); }
					return true;
				}
				else{		//if the item isn't a weapon, an armour or a shield, it can't be equipped, and so, unequipped
					printf("You can't equip/unequip this item.\n\n");
					return true;
				}
			}
		}
	}
	return false;
}
//--
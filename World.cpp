#include "World.h"

void World::CreateWorld(){

	//Name and description from all the rooms in the game:
	Room *Entrance;
	Room *Elm;
	Room *Marsh;
	Room *StyxLeft;
	Room *Tartarus;
	Room *Phelgethon;
	Room *StyxRight;
	Room *Lethe;
	Room *ElysianFields;
	Room *FireForest;
	Room *PalaceHades;
	Room *ValeMourning;
	Room *ExitUnderworld;
	rooms.PushBack(Entrance = new Room("Entrance", "You are back in the entrance, you see a big door in the south and a path in the north.\n"));
	rooms.PushBack(Elm = new Room("The Elm from which False Dreams cling", "You don't believe you eyes, it is the most beautiful place you have ever seen, and in a place like in the Underworld! In the middle there are trees.\n"));
	rooms.PushBack(Marsh = new Room("Marsh", "You see a marsh, in the middle of it you see Charon the ferryan.\n"));
	rooms.PushBack(StyxLeft = new Room("Left side of river Styx", "After Charon take you here you only see one path, but you feel it is a dangerous place.\n"));
	rooms.PushBack(Tartarus = new Room("Tartarus", "You ear insane spirits being tortured, there is a powerful light in the right.\n"));
	rooms.PushBack(Phelgethon = new Room("Phelgethon", "The river is not of water, but fire.\n There is no way to cross it.\n"));
	rooms.PushBack(StyxRight = new Room("Right side of river Styx", "This river is full of undead.\n"));
	rooms.PushBack(Lethe = new Room("River Lethe", "In the border of the river  Lethe you see more undead near this river, but they seem different from the ones before...\n"));
	rooms.PushBack(ElysianFields = new Room("Elysian Fields", "You feel a different sensation in this zone from all the ones before. You see some silhouettes in the distance.\n"));
	rooms.PushBack(FireForest = new Room("Fire Forest", "You see a big forest burning, but the light from the fire is strange.\n"));
	rooms.PushBack(PalaceHades = new Room("Palace of Hades", "Once again this place surprise you, this time by an enormous and beutiful palace.\n"));
	rooms.PushBack(ValeMourning = new Room("Vale of Mourning", "You feel the exit nearby, but there are more undead ahead.\n"));
	rooms.PushBack(ExitUnderworld = new Room("Exit", "You can see the exit in the distance, unfortunately its guardian, Cerberus, is right before it...\n"));
	//--

	//Exits & Destinations & Directions:
	exits.PushBack(new Exit("The Elm from which False Dreams cling", "You don't believe you eyes, it is the most beautiful place you have ever seen, and in a place like in the Underworld! In the middle there are trees.\n", Entrance, Elm, SOUTH, true));
	exits.PushBack(new Exit("Marsh", "You see a marsh, in the middle of it you see Charon the ferryan.\n", Entrance, Marsh, NORTH, 2));
	exits.PushBack(new Exit("Entrance", "You are back in the entrance, you see a big door in the south and a path in the north.\n", Elm, Entrance, NORTH, true));
	exits.PushBack(new Exit("Entrance", "You are back in the entrance, you see a big door in the south and a path in the north.\n", Marsh, Entrance, SOUTH, 2));
	exits.PushBack(new Exit("Left side of river Styx", "After Charon take you here you only see one path, but you feel it is a dangerous place.\n", Marsh, StyxLeft, WEST, 2));
	exits.PushBack(new Exit("Marsh", "You see a marsh, in the middle of it you see Charon the ferryan.\n", StyxLeft, Marsh, EAST, 2));
	exits.PushBack(new Exit("Tartarus", "You ear insane spirits being tortured, there is a powerful light in the right.\n", StyxLeft, Tartarus, NORTH, 2));
	exits.PushBack(new Exit("Left side of river Styx", "After Charon take you here you only see one path, but you feel it is a dangerous place.\n", Tartarus, StyxLeft, SOUTH, 2));
	exits.PushBack(new Exit("Phelgethon", "The river is not of water, but fire.\n There is no way to cross it.\n", Tartarus, Phelgethon, EAST, 2));
	exits.PushBack(new Exit("Tartarus", "You ear insane spirits being tortured, there is a powerful light in the right.\n", Phelgethon, Tartarus, WEST, 2));
	exits.PushBack(new Exit("Right side of river Styx", "This river is full of undead.\n", Marsh, StyxRight, EAST, 2));
	exits.PushBack(new Exit("Marsh", "You see a marsh, in the middle of it you see Charon the ferryan.\n", StyxRight, Marsh, WEST, 2));
	exits.PushBack(new Exit("River Lethe", "In the border of the river  Lethe you see more undead near this river, but they seem different from the ones before...\n", StyxRight, Lethe, NORTH, 2));
	exits.PushBack(new Exit("Right side of river Styx", "This river is full of undead.\n", Lethe, StyxRight, SOUTH, 2));
	exits.PushBack(new Exit("Elysian Fields", "You feel a different sensation in this zone from all the ones before. You see some silhouettes in the distance.\n", Lethe, ElysianFields, NORTH, 2));
	exits.PushBack(new Exit("River Lethe", "In the border of the river  Lethe you see more undead near this river, but they seem different from the ones before...\n", ElysianFields, Lethe, SOUTH, 2));
	exits.PushBack(new Exit("Fire Forest", "You see a big forest burning, but the light from the fire is strange.\n", ElysianFields, FireForest, WEST, 2));
	exits.PushBack(new Exit("Elysian Fields", "You feel a different sensation in this zone from all the ones before. You see some silhouettes in the distance.\n", FireForest, ElysianFields, EAST, 2));
	exits.PushBack(new Exit("Palace of Hades", "Once again this place surprise you, this time by an enormous and beutiful palace.\n", FireForest, PalaceHades, SOUTH, true));
	exits.PushBack(new Exit("Fire Forest", "You see a big forest burning, but the light from the fire is strange.\n", PalaceHades, FireForest, NORTH, true));
	exits.PushBack(new Exit("Vale of Mourning", "You feel the exit nearby, but there are more undead ahead.\n", FireForest, ValeMourning, WEST, 2));
	exits.PushBack(new Exit("Fire Forest", "You see a big forest burning, but the light from the fire is strange.\n", ValeMourning, FireForest, EAST, 2));
	exits.PushBack(new Exit("Exit", "You can see the exit in the distance, unfortunately its guardian, Cerberus, is right before it...\n", ValeMourning, ExitUnderworld, WEST, 2));
	exits.PushBack(new Exit("Vale of Mourning", "You feel the exit nearby, but there are more undead ahead.\n", ExitUnderworld, ValeMourning, EAST, 2));
	//--

	//Items:
	Item* Coins;
	Item* Stick;
	Item* Sword;
	Item* Arrows;
	Item* FireBow;
	Item* IceBow;
	items.PushBack(Coins = new Item("coins", "Coins needed to cross the river.\n", Elm, 0, 0, OTHER, FLOOR));
	items.PushBack(Stick = new Item("stick", "Just a large stick.\nDamage: 10.\nBlock chance: 5.\n", Entrance, 10, 5, WEAPON, FLOOR));
	items.PushBack(Sword = new Item("sword", "A shiny sword\nDamage: 70.\nBlock chance: 10.\n", Marsh, 70, 10, WEAPON, FLOOR));	
	items.PushBack(Arrows = new Item("arrows", "A pack of arrows. Useless without a bow.\nDamage: 25.\nBlock chance: 0.\n", Entrance, 25, 0, WEAPON, FLOOR));
	items.PushBack(FireBow = new Item("fire bow", "A bow in flames? Yep you see that right, this bow has flames but they don't burn you...\nDamage: 150.\nBlock chance: 0.\n", Entrance, 150, 0, WEAPON, FLOOR));
	items.PushBack(IceBow = new Item("ice bow", "A bow covered in ice. Seems fragile but strong.\nDamage: 120.\nBlock chance: 0.\n", Entrance, 120, 0, WEAPON, FLOOR));
	
	items[4]->name.Tokenize(" ,.-_", item_tokens);
	item_tokens.PushBack("ice");
	item_tokens.PushBack("bow");

	//		ACLARATION FOR POSTERIOR CODE: As the list of items grows one by one but the list of tokens grows 2 by 2,
	//		for this reason, there will be some multiplications *2 in some of the for loops depending if the code refers
	//		to the list of items or the tokens of them.

	//		Also, for this reason, the list of items must follow this order: first the items which name has one word,
	//		and then the ones that have 2 words.
	
	//--

	//Player:
	player.position = rooms[0];//Initializes the position in the Entrance.
	player.attack = 45;
	player.defense = 20;
	player.hp = 420;
	//--

	//First place name and description
	printf("%s\n", player.position->name);
	printf("After crossing the portal you lose your vision for a few seconds, you feel strange in here. \nOnce you recover you see a big door in the south and a path in the north.\n"); //Different description once you return in the entrance.
	//--
	
}

//Commands that implies direction, else return -1 IN CASE THERE ARE MORE THAN ONE WORD
int World::GetDirection(String commandm, Vector<String> tokens)const{
	if (command == "n" || command == "north" || tokens[0] == ("go") && tokens[1] == ("north")){ return 0; }
	else if (command == "s" || command == "south" || tokens[0] == ("go") && tokens[1] == ("south")){ return 1; }
	else if (command == "e" || command == "east" || tokens[0] == ("go") && tokens[1] == ("east")){ return 2; }
	else if (command == "w" || command == "west" || tokens[0] == ("go") && tokens[1] == ("west")){ return 3; }
	//Open Command: Asks where to open.
	else if (command == "open"){
		printf("Open where?\n");
		String OpenDirection;
		OpenDirection.GetString();
		if (OpenDirection == "north" || OpenDirection == "n"){
			return 0;
		}
		else if (OpenDirection == "south" || OpenDirection == "s"){
			return 1;
		}
		else if (OpenDirection == "east" || OpenDirection == "e"){
			return 2;
		}
		else if (OpenDirection == "west" || OpenDirection == "w"){
			return 3;
		}
	}
	//Close Command: Asks where to close.
	else if (command == "close"){
		String CloseDirection;
		printf("Close where?\n");
		CloseDirection.GetString();
		if (CloseDirection == "north" || CloseDirection == "n"){
			return 0;
		}
		else if (CloseDirection == "south" || CloseDirection == "s"){
			return 1;
		}
		else if (CloseDirection == "east" || CloseDirection == "e"){
			return 2;
		}
		else if (CloseDirection == "west" || CloseDirection == "w"){
			return 3;
		}
	}
	//--
	else { return -1; }
}
//--

//Commands that implies direction, else return -1 IN CASE THERE IS ONLY ONE WORD
int World::GetDirection(String commandm)const{
	if (command == "n" || command == "north" || command == ("go north")){ return 0; }
	else if (command == "s" || command == "south" || command == ("go south")){ return 1; }
	else if (command == "e" || command == "east" || command == ("go east")){ return 2; }
	else if (command == "w" || command == "west" || command == ("go west")){ return 3; }
	//Open Command: Asks where to open.
	else if (command == "open"){
		printf("Open where?\n");
		String OpenDirection;
		OpenDirection.GetString();
		if (OpenDirection == "north" || OpenDirection == "n"){
			return 0;
		}
		else if (OpenDirection == "south" || OpenDirection == "s"){
			return 1;
		}
		else if (OpenDirection == "east" || OpenDirection == "e"){
			return 2;
		}
		else if (OpenDirection == "west" || OpenDirection == "w"){
			return 3;
		}
	}
	//Close Command: Asks where to close.
	else if (command == "close"){
		String CloseDirection;
		printf("Close where?\n");
		CloseDirection.GetString();
		if (CloseDirection == "north" || CloseDirection == "n"){
			return 0;
		}
		else if (CloseDirection == "south" || CloseDirection == "s"){
			return 1;
		}
		else if (CloseDirection == "east" || CloseDirection == "e"){
			return 2;
		}
		else if (CloseDirection == "west" || CloseDirection == "w"){
			return 3;
		}
	}
	//--
	else { return -1; }
}
//--


//Open
void World::OpenGate(int CommandDir)const{
	for (int i = 0; i < NUM_EXITS; i++){
		if (exits[i]->origin->name == player.position->name){
			if (CommandDir == exits[i]->direction) {
				if (exits[i]->destination == rooms[10] ||exits[i]->destination == rooms[1] ||exits[i]->destination == rooms[9] ||exits[i]->destination == rooms[0]){
					if ((exits[i])->blocked == false){ printf("This door had been already opened dude.\n"); }
					else{
						exits[i]->blocked = false;
						exits[i + 2]->blocked = false;
						printf("The path to %s has been opened.\n", exits[i]->destination->name);
					}
				}
				else{ printf("I don't see any door to open...\n"); }
			}
		}
	}
}
//--

//Close
void World::CloseGate(int CommandDir)const{
	for (int i = 0; i < NUM_EXITS; i++){
		if (exits[i]->origin->name == player.position->name){
			if (CommandDir == exits[i]->direction) {
				if (exits[i]->destination == rooms[10] || exits[i]->destination == rooms[1] || exits[i]->destination == rooms[9] || exits[i]->destination == rooms[0]){
					if (exits[i]->blocked == true){ printf("This door is already closed dude.\n"); }
					else{
						exits[i]->blocked = true;
						exits[i + 2]->blocked = true;
						printf("The path to %s has been closed.\n", exits[i]->destination->name);
					}
				}
				else{ printf("I don't see any door to close...\n"); }
			}
		}
	}
}
//--

//Pick items
bool World::PickItem(Vector<String> tokens, int &InventorySlots, unsigned int num_words){
	if (num_words == 2){
		for (int i = 0; i < NUM_1_WORD_ITEMS; i++){
			if (tokens[1] == items[i]->name.c_str()){
				if (items[i]->item_position->name == player.position->name){
					if (items[i]->place == FLOOR){
						if (InventorySlots < 10){
							printf("%s picked up.\n", items[i]->name.c_str());
							items[i]->place = INVENTORY;
							InventorySlots++;
							return true;
						}
						else{
							printf("Inventory full.\n");
							return true;
						}
					}
					else{
						printf("Item already in the inventory.\n");
						return true;
					}
				}
			}
		}
	}
	if (num_words == 3){
		for (int i = 0; i < NUM_2_WORD_ITEMS; i++){	
			if (tokens[1] == item_tokens[i*2] && tokens[2] == item_tokens[i*2 + 1]){
				if (items[i + NUM_1_WORD_ITEMS ]->item_position->name == player.position->name){
					if (items[i + NUM_1_WORD_ITEMS ]->place == FLOOR){
						if (InventorySlots < 10){
							printf("%s %s picked up.\n", item_tokens[i].c_str(), item_tokens[i + 1].c_str());
							items[i + NUM_1_WORD_ITEMS]->place = INVENTORY;
							InventorySlots++;
							return true;
						}
						else{
							printf("Inventory full.\n");
							return true;
						}
					}
					else{
						printf("Item already in the inventory.\n");
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
bool World::LookInventory(int &InventorySlots)const{
	int empty_inventory = 0;	
	for (int i = 0; i < NUM_1_WORD_ITEMS; i++){
		if (items[i]->place == EQUIPPED){
			printf("%s(Equipped):  %s\n", items[i]->name.c_str(), items[i]->description.c_str());
			empty_inventory = 1;
		}
		if (items[i]->place == INVENTORY){
			printf("%s:  %s\n", items[i]->name.c_str(), items[i]->description.c_str());
			empty_inventory = 1;
		}
	}
	for (int i = 0; i < NUM_2_WORD_ITEMS; i++){
		if (items[i + NUM_1_WORD_ITEMS]->place == EQUIPPED){
			printf("%s %s(Equipped):  %s\n", item_tokens[i].c_str(), item_tokens[i + 1].c_str(), items[i + NUM_1_WORD_ITEMS]->description.c_str());
			empty_inventory = 1;
		}
		if (items[i + NUM_1_WORD_ITEMS]->place == INVENTORY){
			printf("%s %s:  %s\n", item_tokens[i].c_str(), item_tokens[i + 1].c_str(), items[i + NUM_1_WORD_ITEMS]->description.c_str());
			empty_inventory = 1;
		}
	}
	printf("Inventory slots: %i/10.\n", InventorySlots);
	if (empty_inventory == 1){ return true; }
	else{ return false; }
}
//--

//Drop an item
bool World::DropItem(Vector<String> tokens, int &InventorySlots, unsigned int num_words){
	if (num_words == 2){
		for (int i = 0; i < NUM_1_WORD_ITEMS; i++){

			if (tokens[1] == items[i]->name.c_str()){
				if (items[i]->place == INVENTORY){
					printf("%s dropped on the floor.\n", items[i]->name.c_str());
					items[i]->place = FLOOR;
					items[i]->item_position = player.position;
					InventorySlots--;
					return true;
				}
			}
		}
	}
	else if (num_words == 3) {
		for (int i = 0; i < NUM_2_WORD_ITEMS; i++){
			if (tokens[1] == item_tokens[i*2] ){
				if (items[i + NUM_1_WORD_ITEMS]->place == INVENTORY){
					printf("%s %s dropped on the floor.\n", item_tokens[i*2].c_str(), item_tokens[i*2].c_str());
					items[i + NUM_1_WORD_ITEMS]->place = FLOOR;
					items[i + NUM_1_WORD_ITEMS]->item_position = player.position;
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
void World::LookItem(String item, unsigned int num_words)const{
	if (num_words == 2){
		for (int i = 0; i < NUM_1_WORD_ITEMS; i++){
			if (items[i]->name == item.c_str()){
				if (items[i]->place == INVENTORY || items[i]->place == EQUIPPED){
					printf("%s\n%s\n", items[i]->name.c_str(), items[i]->description.c_str());
				}
			}
			else{ printf("This item isn't in your inventory or equipped.\n"); }
		}
	}
	else if (num_words == 3){
		for (int i = 0; i < NUM_2_WORD_ITEMS; i++){
			if (items[i + NUM_1_WORD_ITEMS]->name == item.c_str()){
				if (items[i + NUM_1_WORD_ITEMS]->place == INVENTORY || items[i + NUM_1_WORD_ITEMS]->place == EQUIPPED){
					printf("%s %s\n%s\n", item_tokens[i].c_str(), item_tokens[i + 1].c_str(), items[i + NUM_1_WORD_ITEMS]->description.c_str());
				}
			}
			else{ printf("This item isn't in your inventory or equipped.\n"); }
		}
	}

}
//--

//Equip an item
bool World::EquipItem(Vector<String> tokens, int &WeaponCounter, int &ArmourCounter, unsigned int num_words){
	if (num_words == 2){
		for (int i = 0; i < NUM_1_WORD_ITEMS; i++){
			if (tokens[1] == items[i]->name.c_str()){
				if (items[i]->place == INVENTORY){
					if (items[i]->type == WEAPON){
						if (WeaponCounter == 1){ printf("You already have a weapon equipped.\n"); }
						else{
							if (items[i]->name == "arrows"){
								printf("You can't equip arrows, put them in a bow :)");
							}
							else{
								items[i]->place = EQUIPPED;
								printf("%s equipped.\n", items[i]->name.c_str());
								player.attack += items[i]->value;
								player.block_chance += items[i]->block_chance;
							}
							WeaponCounter++;
						}
					}
					else if (items[i]->type == ARMOUR){
						if (ArmourCounter == 1){ printf("You already have an armour equipped.\n"); }
						else{
							items[i]->place = EQUIPPED;
							printf("%s equipped.\n", items[i]->name.c_str());
							player.defense += items[i]->value;
							player.block_chance += items[i]->block_chance;
							ArmourCounter++;
						}
					}
					else if (items[i]->type == OTHER){ printf("You can't equip this item"); }
				}
				else if (items[i]->place == EQUIPPED){ printf("Item already equipped dude.\n"); }
				else if (items[i]->place == FLOOR) { printf("Item must be in the inventory in order to equip it.\n"); }
				return true;
			}
		}
	}
	else if (num_words == 3){
		for (int i = 0; i < NUM_2_WORD_ITEMS; i++){
			if (tokens[1] == item_tokens[i * 2] && tokens[2] == item_tokens[i * 2 + 1]){
				if (items[i + NUM_1_WORD_ITEMS]->place == INVENTORY){
					if (items[i + NUM_1_WORD_ITEMS]->type == WEAPON){
						if (WeaponCounter == 1){ printf("You already have a weapon equipped.\n"); }
						else{
							items[i + NUM_1_WORD_ITEMS]->place = EQUIPPED;
							if (tokens[2] == "bow"){
								printf("%s %s equipped, but it won't have effect alone...\nYou shouls search for arrows.\n", item_tokens[i * 2].c_str(), item_tokens[i * 2 + 1].c_str());
							}
							else{
								printf("%s equipped.\n", items[i + NUM_1_WORD_ITEMS]->name.c_str());
								player.attack += items[i + NUM_1_WORD_ITEMS]->value;
								player.block_chance += items[i + NUM_1_WORD_ITEMS]->block_chance;
							}
							WeaponCounter++;
						}
					}
					//No 2 words armour/object exists
					else if (items[i]->place == EQUIPPED){ printf("Item already equipped dude.\n"); }
					else if (items[i]->place == FLOOR) { printf("Item must be in the inventory in order to equip it.\n"); }
					return true;
				}
			}
		}
	}
	return false;
}
//--

//Unequip an item
void World::UnequipItem(Vector<String> tokens, int &WeaponCounter, int &ArmourCounter, unsigned int num_words){
	if (num_words == 2){
		for (int i = 0; i < NUM_1_WORD_ITEMS; i++){
			if (tokens[1] == items[i]->name.c_str()){
				if (items[i]->place == EQUIPPED){					
					if (items[i]->type == WEAPON){
						items[i]->place = INVENTORY;
						printf("%s unequipped.\n", items[i]->name.c_str());
						player.attack -= items[i]->value;
						player.block_chance -= items[i]->block_chance;
						WeaponCounter--;
					}
					else if (items[i]->type == ARMOUR){
						player.defense -= items[i]->value;
						player.block_chance -= items[i]->block_chance;
						ArmourCounter--;
					}
				}
				else if (items[i]->name == "arrows"){ printf("You serious...?\n"); }
				else if (items[i]->place == INVENTORY){ printf("Item is in the inventory dude.\n"); }
				else if (items[i]->place == FLOOR) { printf("This item is somewhere in the map...\n"); }
			}
		}
	}
	else if (num_words == 3){
		for (int i = 0; i < NUM_2_WORD_ITEMS; i++){
			if (tokens[1] == item_tokens[i*2] && tokens[2] == item_tokens[i*2 + 1]){
				if (items[i + NUM_1_WORD_ITEMS]->place == EQUIPPED){
					items[i + NUM_1_WORD_ITEMS]->place = INVENTORY;
					if (items[i + NUM_1_WORD_ITEMS]->type == WEAPON){
						if (tokens[2] == "bow"){
							printf("%s %s unequipped.\n", item_tokens[i * 2].c_str(), item_tokens[i * 2 + 1].c_str());
						}
						else{
							printf("%s %s unequipped.\n", item_tokens[i * 2].c_str(), item_tokens[i * 2 + 1].c_str());
							player.attack -= items[i]->value;
							player.block_chance -= items[i]->block_chance;
						}
						WeaponCounter--;
					}
					//No armour type of 2 words exists
				}
				else if (items[i]->place == INVENTORY){ printf("Item is in the inventory dude.\n"); }
				else if (items[i]->place == FLOOR) { printf("This item is somewhere in the map...\n");
				}
			}
		}
	}
}
//--

//Movement of the player
bool World::Move(int CommandDir){
	bool done = false; //makes a path stop as soon as he finds another room.
	for (int i = 0; i < NUM_EXITS; i++){
		if (exits[i]->origin->name == player.position->name){ //Compares if the position of the player and the origin of the exit is the same.
			if (CommandDir == exits[i]->direction) {//compares if the direction of the exit and the direction of the command is the same.
				if (World::WayClear(i) == true){ //Looks if the path is looked or not.
					player.position = exits[i]->destination;
					printf("%s\n", player.position->name);
					printf("%s\n", player.position->description);
					done = true;
					return true;
					break;
				}
			}
		}
	}
	return false;
}
//--

//Comproving if tha path is closed
bool World::WayClear(int i)const{
	if (exits[i]->blocked == true){
		printf("Gate locked.\n");
		return false;
	}
	else if (exits[i]->destination == rooms[3] || exits[i]->destination == rooms[6]){
		if (items[0]->place == INVENTORY){ return true; }
		else{
			printf("You need to have the coins for Charon the ferryman to cross this river.\n");
			return false;
		}
	}
	else { return true; }
}
//--

//Looks other rooms
bool World::LookDirection(int CommandDir, Vector<String> tokens)const{
	bool done = false;
	for (int i = 0; i < NUM_EXITS; i++){
		if (exits[i]->origin->name == player.position->name){
			CommandDir = GetDirection(command, tokens);
			if (CommandDir == exits[i]->direction) {
				if (World::WayClear(i) == true){
					printf("%s\n", exits[i]->destination->description);
					done = true;
					return 1;
					break;
				}
				else{
				printf("Before look what is inside you must open the gate.\n");
				}
			}
		}
	}
	return 0;
}
//--

//Look
void World::Look()const{
	printf("%s\n", player.position->name.c_str());
	printf("%s\n", player.position->description.c_str());
}
//--

//Player stats
void World::Stats()const{
	printf("Your stats are:\n");
	printf("HP: %i.\n", player.hp);
	printf("Attack: %i.\n", player.attack);
	printf("Defense: %i.\n", player.defense);
	printf("Block chance: %i.\n", player.block_chance);
}

//Exits game
bool World::ExitGame()const{
	if (command == "quit"){ return true; }
	else{ return false; }
}
//--


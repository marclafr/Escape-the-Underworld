#include "World.h"
#include "Items.h"
#include "Rooms.h"
#include "Exits.h"
#include "Player.h"
#include "String.h"

void World::CreateWorld()
{
	int i = 0; //entity number

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
	entities.PushBack(Entrance = new Room("Entrance", "You are back in the entrance, you see a big door in the south, a path in the north and there still is the friendly shadow.\n"));
	entities.PushBack(Elm = new Room("The Elm from which False Dreams cling", "You don't believe you eyes, it is the most beautiful place you have ever seen, and in a place like in the Underworld! In the middle there are trees.\n"));
	entities.PushBack(Marsh = new Room("Marsh", "You see a marsh, in the middle of it you see Charon the ferryan.\n"));
	entities.PushBack(StyxLeft = new Room("Left side of river Styx", "After Charon take you here you only see one path, but you feel it is a dangerous place.\n"));
	entities.PushBack(Tartarus = new Room("Tartarus", "You ear insane spirits being tortured, there is a powerful light in the right.\n"));
	entities.PushBack(Phelgethon = new Room("Phelgethon", "The river is not of water, but fire.\n There is no way to cross it.\n"));
	entities.PushBack(StyxRight = new Room("Right side of river Styx", "This river is full of undead.\n"));
	entities.PushBack(Lethe = new Room("River Lethe", "In the border of the river  Lethe you see more undead near this river, but they seem different from the ones before...\n"));
	entities.PushBack(ElysianFields = new Room("Elysian Fields", "You feel a different sensation in this zone from all the ones before. You see some silhouettes in the distance.\n"));
	entities.PushBack(FireForest = new Room("Fire Forest", "You see a big forest burning, but the light from the fire is strange.\n"));
	entities.PushBack(PalaceHades = new Room("Palace of Hades", "Once again this place surprise you, this time by an enormous and beutiful palace.\n"));
	entities.PushBack(ValeMourning = new Room("Vale of Mourning", "You feel the exit nearby, but there are more undead ahead.\n"));
	entities.PushBack(ExitUnderworld = new Room("Exit", "You can see the exit in the distance, unfortunately its guardian, Cerberus, is right before it...\n"));
	//--
	i += 13;	//NUM_ROOMS

	//Exits & Destinations & Directions:
	entities.PushBack(new Exit("The Elm from which False Dreams cling", "You don't believe you eyes, it is the most beautiful place you have ever seen, and in a place like in the Underworld! In the middle there are trees.\n", Entrance, Elm, SOUTH, true));
	entities.PushBack(new Exit("Marsh", "You see a marsh, in the middle of it you see Charon the ferryan.\n", Entrance, Marsh, NORTH, 2));
	entities.PushBack(new Exit("Entrance", "You are back in the entrance, you see a big door in the south and a path in the north.\n", Elm, Entrance, NORTH, true));
	entities.PushBack(new Exit("Entrance", "You are back in the entrance, you see a big door in the south and a path in the north.\n", Marsh, Entrance, SOUTH, 2));
	entities.PushBack(new Exit("Left side of river Styx", "After Charon take you here you only see one path, but you feel it is a dangerous place.\n", Marsh, StyxLeft, WEST, 2));
	entities.PushBack(new Exit("Marsh", "You see a marsh, in the middle of it you see Charon the ferryan.\n", StyxLeft, Marsh, EAST, 2));
	entities.PushBack(new Exit("Tartarus", "You ear insane spirits being tortured, there is a powerful light in the right.\n", StyxLeft, Tartarus, NORTH, 2));
	entities.PushBack(new Exit("Left side of river Styx", "After Charon take you here you only see one path, but you feel it is a dangerous place.\n", Tartarus, StyxLeft, SOUTH, 2));
	entities.PushBack(new Exit("Phelgethon", "The river is not of water, but fire.\n There is no way to cross it.\n", Tartarus, Phelgethon, EAST, 2));
	entities.PushBack(new Exit("Tartarus", "You ear insane spirits being tortured, there is a powerful light in the right.\n", Phelgethon, Tartarus, WEST, 2));
	entities.PushBack(new Exit("Right side of river Styx", "This river is full of undead.\n", Marsh, StyxRight, EAST, 2));
	entities.PushBack(new Exit("Marsh", "You see a marsh, in the middle of it you see Charon the ferryan.\n", StyxRight, Marsh, WEST, 2));
	entities.PushBack(new Exit("River Lethe", "In the border of the river  Lethe you see more undead near this river, but they seem different from the ones before...\n", StyxRight, Lethe, NORTH, 2));
	entities.PushBack(new Exit("Right side of river Styx", "This river is full of undead.\n", Lethe, StyxRight, SOUTH, 2));
	entities.PushBack(new Exit("Elysian Fields", "You feel a different sensation in this zone from all the ones before. You see some silhouettes in the distance.\n", Lethe, ElysianFields, NORTH, 2));
	entities.PushBack(new Exit("River Lethe", "In the border of the river  Lethe you see more undead near this river, but they seem different from the ones before...\n", ElysianFields, Lethe, SOUTH, 2));
	entities.PushBack(new Exit("Fire Forest", "You see a big forest burning, but the light from the fire is strange.\n", ElysianFields, FireForest, WEST, 2));
	entities.PushBack(new Exit("Elysian Fields", "You feel a different sensation in this zone from all the ones before. You see some silhouettes in the distance.\n", FireForest, ElysianFields, EAST, 2));
	entities.PushBack(new Exit("Palace of Hades", "Once again this place surprise you, this time by an enormous and beutiful palace.\n", FireForest, PalaceHades, SOUTH, true));
	entities.PushBack(new Exit("Fire Forest", "You see a big forest burning, but the light from the fire is strange.\n", PalaceHades, FireForest, NORTH, true));
	entities.PushBack(new Exit("Vale of Mourning", "You feel the exit nearby, but there are more undead ahead.\n", FireForest, ValeMourning, WEST, 2));
	entities.PushBack(new Exit("Fire Forest", "You see a big forest burning, but the light from the fire is strange.\n", ValeMourning, FireForest, EAST, 2));
	entities.PushBack(new Exit("Exit", "You can see the exit in the distance, unfortunately its guardian, Cerberus, is right before it...\n", ValeMourning, ExitUnderworld, WEST, 2));
	entities.PushBack(new Exit("Vale of Mourning", "You feel the exit nearby, but there are more undead ahead.\n", ExitUnderworld, ValeMourning, EAST, 2));
	//--
	i += 24;	//NUM_EXITS

	//Gets player name
	printf("Enter your character name:\t");
	String player_name;
	player_name.GetString();
	//--

	//Player:
	entities.PushBack(player = new Player(player_name, " ", Entrance, P_ORI_DAMAGE + 7, P_ORI_DEFENSE, P_ORI_B_CHANCE, P_ORI_HP, 0));
	//--
	i++; //PLAYER

	//Items:
	Item* Coins;
	Item* Keys;
	Item* Stick;
	Item* Sword;
	Item* Shield;
	Item* Arrows;
	Item* Quiver;
	Item* FireBow;
	Item* IceBow;
	Item* WornArmour;
	Item* SilverArmour;
	Item* Armour;
	Item* DestroyedShield;
	Item* UnknownShield;
	Item* StrangeArtifact;
	Item* HadesStatue;
	Item* HephaestusStatue;
	Item* AphroditeStatue;
	Item* ChronosStatue;
	entities.PushBack(Coins = new Item("coins", "Coins needed to cross the river.\nPrice: 0 Souls.\n\n", 0, 0, 0, OTHER, FLOOR, UNFUSABLE, UNACTIVABLE, REGULAR));
	Elm->list.push_back(Coins);
	entities.PushBack(Keys = new Item("keys", "keys needed to open gates.\nPrice: 0 Souls.\n\n", 0, 0, 0, OTHER, FLOOR, UNFUSABLE, UNACTIVABLE, REGULAR));
	Marsh->list.push_back(Keys);
	entities.PushBack(Stick = new Item("stick", "Just a large stick.\nDamage: 7.\nBlock chance: 3.\nPrice: 25 Souls.\n\n", 7, 3, 25, WEAPON, EQUIPPED, UNFUSABLE, UNACTIVABLE, REGULAR));
	player->list.push_back(Stick);
	entities.PushBack(Sword = new Item("sword", "A shiny sword\nDamage: 70.\nBlock chance: 5.\nPrice: 1000 Souls.\n\n", 70, 5, 1000, WEAPON, STORE, UNFUSABLE, UNACTIVABLE, REGULAR));
	entities.PushBack(Shield = new Item("shield", "A big shield to protect you.\nDefense: 25.\nBlock chance: 20.\nPrice: 750 Souls.\n\n", 25, 20, 750, SHIELD, STORE, UNFUSABLE, UNACTIVABLE, REGULAR));
	entities.PushBack(Arrows = new Item("arrows", "A pack of arrows. Useless without a bow. You should put them into a quiver...\nAmount: 50.\nPrice: 25 Souls.\n\n", 50, 0, 25, OTHER, FLOOR, FUSABLE1, UNACTIVABLE, REGULAR));
	Elm->list.push_back(Arrows);
	entities.PushBack(Quiver = new Item("quiver", "Use it to store and use your arrows.\nCapacity: 50.\nPrice: 10 Souls.\n\n", 50, 0, 10, OTHER, FLOOR, FUSABLE2, UNACTIVABLE, REGULAR));
	Marsh->list.push_back(Quiver);
	entities.PushBack(FireBow = new Item("fire bow", "A bow in flames? Yep you see that right, this bow has flames but they don't burn you...\nDamage: 120.\nBlock chance: 0.\nPrice: 3500 Souls.\n\n", 120, 0, 3500, WEAPON, FLOOR, UNFUSABLE, UNACTIVABLE, REGULAR));
	Tartarus->list.push_back(FireBow);
	entities.PushBack(IceBow = new Item("ice bow", "A bow covered in ice. Seems fragile but strong, specially in this world.\nDamage: 150.\nBlock chance: 0.\nPrice: 4000 Souls.\n\n", 150, 0, 4000, WEAPON, STORE, UNFUSABLE, UNACTIVABLE, REGULAR));
	entities.PushBack(WornArmour = new Item("worn armour", "This armour doesn't seem to be really useful anymore...\nDefense: 5.\nBlock chance: 1.\nPrice: 20 Souls.\n\n", 5, 1, 20, ARMOUR, EQUIPPED, UNFUSABLE, UNACTIVABLE, REGULAR));
	player->list.push_back(WornArmour);
	entities.PushBack(SilverArmour = new Item("silver armour", "This shiny armour looks so resistant and\nDefense: 95.\nBlock chance: 5.\nPrice: 3000 Souls.\n\n", 95, 5, 3000, ARMOUR, STORE, UNFUSABLE, UNACTIVABLE, REGULAR));
	entities.PushBack(Armour = new Item("armour", "A regular armour. Looks resistant and\nDefense: 55.\nBlock chance: 5.\nPrice: 1000 Souls.\n\n", 55, 5, 1000, ARMOUR, STORE, UNFUSABLE, UNACTIVABLE, REGULAR));
	entities.PushBack(DestroyedShield = new Item("destroyed shield", "This shield isn't a shield anymore...\nDefense: 1.\nBlock chance: 0.\nPrice: 15 Souls.\n\n", 1, 0, 15, SHIELD, EQUIPPED, UNFUSABLE, UNACTIVABLE, REGULAR));
	player->list.push_back(DestroyedShield);
	entities.PushBack(UnknownShield = new Item("unknown shield", "You have never seen a shield like this one, its colours change...\nDefense: 90.\nBlock chance: 50.\nPrice: 5000 Souls.\n\n", 90, 50, 5000, SHIELD, STORE, UNFUSABLE, UNACTIVABLE, REGULAR));
	entities.PushBack(StrangeArtifact = new Item("strange artifact", "You had never seen something like this, maybe it is the artifact you were looking for?\nPrice: 5900 Souls.\n\n", 0, 0, 5900, OTHER, STORE, UNFUSABLE, UNACTIVABLE, REGULAR));
	entities.PushBack(HadesStatue = new Item("hades statue", "A shiny statue of the god Hades.\nIt may be useful in his world.\nPrice: 750 Souls.\n\n", 0, 0, 750, STATUE, STORE, UNFUSABLE, DESACTIVATED, REGULAR));
	entities.PushBack(HephaestusStatue = new Item("hephaestus statue", "A shiny statue of the god Hephaestus.\nIt may be useful in his world.\nPrice: 2000 Souls.\n\n", 0, 0, 2000, STATUE, FLOOR, UNFUSABLE, DESACTIVATED, REGULAR));
	Phelgethon->list.push_back(HephaestusStatue);
	entities.PushBack(AphroditeStatue = new Item("aphrodite statue", "A shiny statue of the goddess Aphrodite.\nIt may be useful in his world.\nPrice: 750 Souls.\n\n", 150, 0, 750, STATUE, STORE, UNFUSABLE, DESACTIVATED, REGULAR));
	entities.PushBack(ChronosStatue = new Item("chronos statue", "A shiny statue of the god Chronos.\nIt may be useful in his world.\nPrice: 750 Souls.\n\n", 8, 60, 1250, STATUE, STORE, UNFUSABLE, DESACTIVATED, REGULAR));
	//--
	i += 19;	//NUM_ITEMS

	//NPCs
		//enemies
	entities.PushBack(new Monster(MONSTER_AGG, "harpy", "A monster with a big bird body and a human face, her claws seems sharpy.\n", 300, 0, 30, 400, 500));
	ExitUnderworld->list.push_back(entities[i++]);
	entities.PushBack(new Monster(MONSTER_AGG, "centaur", "A centaur with a bow equipped, doesn't seem really friendly, like nearly everything on this world.\n", 200, 40, 15, 700, 750));
	ElysianFields->list.push_back(entities[i++]);
	entities.PushBack(new Monster(MONSTER_AGG, "undead horde", "A big horde of undead, they don't seem tough but there is A LOT of them. You better be prepared.\n", 300, 0, 0, 2000, 1250));
	Tartarus->list.push_back(entities[i++]);
	entities.PushBack(new Monster(MONSTER_AGG, "hydra", "Probably the biggest creature you have seen so far. She seems tough.\n", 350, 70, 5, 2000, 3000));
	ValeMourning->list.push_back(entities[i++]);
	entities.PushBack(new Monster(MONSTER_AGG, "minotaur", "he is kind of big, but that's not the problem, the problem is his skin seems able o stop everything...\n", 225, 125, 33, 1500, 1000));
	Phelgethon->list.push_back(entities[i++]);
	entities.PushBack(new Monster(MONSTER_AGG, "medusa", "What an horrifying creature, doesn't seem to have a lot of defense...\n", 300, 5, 0, 750, 1000));
	StyxRight->list.push_back(entities[i++]);
	entities.PushBack(new Monster(MONSTER_AGG, "crazy undead", "an undead that went crazy. Doesn't seem any problem to kill.\n", 50, 10, 10, 250, 500));
	Marsh->list.push_back(entities[i++]);
	entities.PushBack(new Monster(MONSTER_AGG, "manticore", "a creature with a human head and the body of a lion, seems dangerous.\n", 325, 50, 10, 900, 1250));
	PalaceHades->list.push_back(entities[i++]);
	entities.PushBack(new Monster(MONSTER_AGG, "cyclop", "big one eyed guy, it's big but doesn't seem skilled.\n", 225, 40, 20, 850, 1000));
	Elm->list.push_back(entities[i++]);
	entities.PushBack(new Monster(MONSTER_AGG, "spirit", "it is said that spirits are pure souls.\n", 100, 0, 80, 225, 3000));
	Elm->list.push_back(entities[i++]);
	entities.PushBack(new Monster(MONSTER_AGG, "shadow", "shadows won't be easy to touch, but if they can't dodge you doesn't seem to resist a lot.\n", 75, 0, 80, 350, 650));
	Elm->list.push_back(entities[i++]);
	entities.PushBack(new Monster(MONSTER_AGG, "cerberus", "The guardian of the gate that connect both worlds... The end is near, if you kill him you will be able to escape, but it looks like you will need some good equipment and still, this won't be easy.\n", 600, 100, 10, 5000, 0));
	ExitUnderworld->list.push_back(entities[i++]);

		//non enemies
	entities.PushBack(new Monster(MONSTER_NON_AGG, "friendly shadow", "A shadow from this world, he doesn't seem agressive like others.\n", 0, 0, 0, 1, 0));
	entities[i]->list.push_back(AphroditeStatue);
	entities[i]->list.push_back(HadesStatue);
	entities[i]->list.push_back(Shield);
	entities[i]->list.push_back(Sword);
	entities[i]->list.push_back(Armour);
	entities[i]->list.push_back(ChronosStatue);
	entities[i]->list.push_back(SilverArmour);
	entities[i]->list.push_back(IceBow);
	entities[i]->list.push_back(UnknownShield);
	entities[i]->list.push_back(StrangeArtifact);
	Entrance->list.push_back(entities[i++]);

	Counters.PushBack(3);	// 0 - Inventory capacity counter: starts with 3 items
	Counters.PushBack(1);	// 1 - Weapon equipped counter
	Counters.PushBack(1);	// 2 - Armour equipped counter
	Counters.PushBack(1);	// 3 - Shield equipped counter
	Counters.PushBack(0);	// 4 - Quiver capacity counter
	Counters.PushBack(0);	// 5 - Activated Statues counter
	

	//First place name and description
	printf("%s\n", player->position->name);
	printf("After crossing the portal you lose your vision for a few seconds, you feel strange in here. \nOnce you recover you see a big door in the south and a path in the north.\nYou also see a shadow close to you, but he doesn't seem agressive.\nThe portal destroyed your shield, your spear is now just a stick and your armour is highly damaged, but you seem to be fine.\n\n");
	//Different description once you return in the entrance.
	//--
}

bool World::ExitGame()const
{
	if	(command == "quit")	{ return true; }
	return false;
}

void World::Victory()
{
	DoubleLinkList<Entity*>::nodeD* player_node = Wor->player->list.first_node;
	for (; player_node != nullptr; player_node = player_node->next)
	{
		if (player_node->data->name == "strange artifact")
			GoodEnding = true;
	}
	if (GoodEnding == true)
	{
		printf("Congratulations on your victory, you not only escaped, but got the artifact with you and now you can save your city from your enemies.\nYou are a truly hero!\n\n");
	}
	else
	{
		printf("Congratulations on your victory, you were able to escape the underworld, unfortunately you couldn't get the artifact you were looking for and your city is condemned... at least you are alive.\n\n");
	}
	printf("Thanks for playing Escape the Underworld!\n\n\t- Created by Marc Latorre");
	getchar();
}

void World::DeleteWorld()const
{
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		delete entities[i];
	}
	//TODO CLEAR LISTS 
}
//MEM_LEAKS at: 0x00720640    0x00721998  0x00721B50


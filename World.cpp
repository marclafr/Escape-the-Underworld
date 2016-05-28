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
	entities.PushBack(Entrance = new Room("Entrance", "You are back in the entrance, you see a big door in the south and a path in the north.\n"));
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
	entities.PushBack(player = new Player(player_name, "ain't using this description yet", Entrance, P_ORI_DAMAGE + 7, P_ORI_DEFENSE, P_ORI_B_CHANCE, P_ORI_HP, 0));
	//--
	i++; //PLAYER
			//TODO CHANGE PLAYER DESCRIPTION//

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
	Item* DestroyedShield;
	Item* UnknownShield;
	Item* StrangeArtifact;
	Item* HadesStatue;
	Item* HephaestusStatue;
	Item* AphroditeStatue;
	entities.PushBack(Coins = new Item( "coins", "Coins needed to cross the river.\n\n", 0, 0, 0, OTHER, FLOOR, UNFUSABLE, UNACTIVABLE, REGULAR));
	Elm->list.push_back(Coins);
	entities.PushBack(Keys = new Item("keys", "keys needed to open gates.\n\n", 0, 0, 0, OTHER, FLOOR, UNFUSABLE, UNACTIVABLE, REGULAR));
	Marsh->list.push_back(Keys);
	entities.PushBack(Stick = new Item("stick", "Just a large stick.\nDamage: 7.\nBlock chance: 3.\n\n", 7, 3, 25, WEAPON, EQUIPPED, UNFUSABLE, UNACTIVABLE, REGULAR));
	player->list.push_back(Stick);
	entities.PushBack(Sword = new Item("sword", "A shiny sword\nDamage: 70.\nBlock chance: 10.\n\n", 70, 10, 200, WEAPON, FLOOR, UNFUSABLE, UNACTIVABLE, REGULAR));
	StyxLeft->list.push_back(Sword);
	entities.PushBack(Shield = new Item("shield", "A big shield to protect you.\nDefense: 25.\nBlock chance: 30.\n\n", 25, 30, 125, SHIELD, FLOOR, UNFUSABLE, UNACTIVABLE, REGULAR));
	Tartarus->list.push_back(Shield);
	entities.PushBack(Arrows = new Item("arrows", "A pack of arrows. Useless without a bow. You should put them into a quiver...\nAmount: 50.\n\n", 50, 0, 25, OTHER, FLOOR, FUSABLE1, UNACTIVABLE, REGULAR));	//TODO PREVIOUS WAS WEAPON
	Elm->list.push_back(Arrows);
	entities.PushBack(Quiver = new Item("quiver", "Use it to store and use your arrows.\nCapacity: 50.\n", 50, 0, 10, OTHER, FLOOR, FUSABLE2, UNACTIVABLE, REGULAR));
	Entrance->list.push_back(Quiver);
	entities.PushBack(FireBow = new Item("fire bow", "A bow in flames? Yep you see that right, this bow has flames but they don't burn you...\nDamage: 150.\nBlock chance: 0.\n\n", 150, 0, 750, WEAPON, FLOOR, UNFUSABLE, UNACTIVABLE, REGULAR));
	Phelgethon->list.push_back(FireBow);
	entities.PushBack(IceBow = new Item("ice bow", "A bow covered in ice. Seems fragile but strong.\nDamage: 120.\nBlock chance: 0.\n\n", 120, 0, 1000, WEAPON, FLOOR, UNFUSABLE, UNACTIVABLE, REGULAR));
	//PalaceHades->list.push_back(IceBow);
	entities.PushBack(WornArmour = new Item("worn armour", "This armour doesn't seem to be really useful anymore...\nDefense: 5.\nBlock chance: 1.\n\n", 5, 1, 20, ARMOUR, EQUIPPED, UNFUSABLE, UNACTIVABLE, REGULAR));
	player->list.push_back(WornArmour);
	entities.PushBack(SilverArmour = new Item("silver armour", "This shiny armour looks so resistant and\nDefense: 95.\nBlock chance: 5.\n\n", 95, 5, 400, ARMOUR, FLOOR, UNFUSABLE, UNACTIVABLE, REGULAR));
	//PalaceHades->list.push_back(SilverArmour);
	entities.PushBack(DestroyedShield = new Item("destroyed shield", "This shield isn't a shield anymore...\nDefense: 1.\nBlock chance: 0.\n\n", 1, 0, 15, SHIELD, EQUIPPED, UNFUSABLE, UNACTIVABLE, REGULAR));
	player->list.push_back(DestroyedShield);
	entities.PushBack(UnknownShield = new Item("unknown shield", "You have never seen a shield like this one, its colours change...\nDefense: 140.\nBlock chance: 50.\n\n", 140, 50, 1000, SHIELD, FLOOR, UNFUSABLE, UNACTIVABLE, REGULAR));
	ValeMourning->list.push_back(UnknownShield);
	entities.PushBack(StrangeArtifact = new Item("strange artifact", "You had never seen something like this, maybe it is the artifact you were looking for?\n\n", 0, 0, 1500, OTHER, FLOOR, UNFUSABLE, UNACTIVABLE, REGULAR));
	PalaceHades->list.push_back(StrangeArtifact);
	entities.PushBack(HadesStatue = new Item("hades statue", "A shiny statue of the god Hades.\nIt may be useful in his world.\n\n", 0, 0, 1000, STATUE, FLOOR, UNFUSABLE, DESACTIVATED, REGULAR));
	Entrance->list.push_back(HadesStatue);
	entities.PushBack(HephaestusStatue = new Item("hephaestus statue", "A shiny statue of the god Hephaestus.\nIt may be useful in his world.\n\n", 0, 0, 2000, STATUE, FLOOR, UNFUSABLE, DESACTIVATED, REGULAR));
	Phelgethon->list.push_back(HephaestusStatue);
	entities.PushBack(AphroditeStatue = new Item("aphrodite statue", "A shiny statue of the goddess Aphrodite.\nIt may be useful in his world.\n\n", 0, 0, 750, STATUE, FLOOR, UNFUSABLE, DESACTIVATED, REGULAR));
	Entrance->list.push_back(AphroditeStatue);
	//--
	i += 17;	//NUM_ITEMS

	//NPCs
		//enemies
	entities.PushBack(new Monster(MONSTER_AGG, "harpy", "A monster with a big bird body and a human face, her claws seems sharpy.\n", 50, 0, 30, 400, 500));
	Entrance->list.push_back(entities[i++]);
	/*entities.PushBack(new Monster(MONSTER_AGG, "harpy", "A monster with a big bird body and a human face, her claws seems sharpy", 50, 0, 30, 400, 100));
	Elm->list.push_back(entities[i++]);*/

		//no enemies
	entities.PushBack(new Monster(MONSTER_NON_AGG, "friendly shadow", "A shadow from this world, he doesn't seem agressive like others.\n", 50, 0, 30, 400, 100));
	entities[i]->list.push_back(SilverArmour);
	entities[i]->list.push_back(IceBow);
	Entrance->list.push_back(entities[i++]);

	Counters.PushBack(3);	// 0 - Inventory capacity counter: starts with 3 items
	Counters.PushBack(1);	// 1 - Weapon equipped counter
	Counters.PushBack(1);	// 2 - Armour equipped counter
	Counters.PushBack(1);	// 3 - Shield equipped counter
	Counters.PushBack(0);	// 4 - Quiver capacity counter
	Counters.PushBack(0);	// 5 - Activated Statues counter
	

	//First place name and description
	printf("%s\n", player->position->name);
	printf("After crossing the portal you lose your vision for a few seconds, you feel strange in here. \nOnce you recover you see a big door in the south and a path in the north.\nThe portal destroyed your shield, your spear is now just a stick and your armour is highly damaged, but you seem to be fine.\n\n");
	//Different description once you return in the entrance.
	//--
}

bool World::ExitGame()const
{
	if	(command == "quit")	{ return true; }
	return false;
}

void World::DeleteWorld()
{
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		delete entities[i];
	}
	//TODO CLEAR LISTS 
}
//MEM_LEAKS at: 0x00720640    0x00721998  0x00721B50


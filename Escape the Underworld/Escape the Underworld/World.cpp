#include <stdio.h>
#include "Exits.h"
#include "Player.h"
#include "Rooms.h"
#include "World.h"
#include <string.h>

enum direction{ Entrance, Marsh, Elm, StyxL, Tartarus, Phelgethon, StyxR, Lethe, Elysian, Forest, Palace, Vale, Cerberus };//<--NEEDS WORK

World::World(){
	
	rooms = new Rooms[13];
	player = new Player;
	exits = new Exits[13];
}

void World::CreateWorld()const{
	//Name and description from all the rooms in the game:
	char* names[] = { "Entrance", "The Elm from which False Dreams cling", "Marsh", "Left side of river Styx", "Tartarus", "Phelgethon", "Right side of river Styx", "River Lethe", "Elysian Fields", "Fire Forest", "Palace of Hades", "Vale of Mourning", "Exit" };
	for (int i = 0; i < 13; i++){
		strcpy_s((rooms + i)->name, names[i]);
	}
	char* descriptions[] = { 
		"After crossing the portal you lose your vision for a few seconds, you feel strange in here. \nOnce you recover you see a big door in the south and a path in the north.\n",
		"You don't believe you eyes, it is the most beautiful place you have ever seen, and in a place like in the Underworld! In the middle there are trees.\n",
		"You are in a marsh, in the middle of it you see Charon the ferryan.\n",
		"After Charon take you here you only see one path, but you feel it is a dangerous place.\n",
		"You ear insane spirits being tortured, there is a powerful light at your right.\n",
		"The river is not of water, but fire.\n There is no way to cross it.\n ",
		"Charon makes a stop before entering the following river: Lethe, you get out from the boat and see a lot of undead.\n",
		"After crossing Lethe you see more undead near this river, but they seem different from the ones before...\n",
		"Just as you enter you feel a different sensation in this zone from all the ones before. You see some silhouettes in the distance.\n",
		"You see a big forest burning, but the light from the fire is strange.\n ",
		"Once again this place surprise you, this time by an enormous and beutiful palace.\n",
		"You feel the exit nearby, but there are more undead ahead.\n",
		"You can see the exit in the distance, unfortunately its guardian, Cerberus, is right before it...\n"
	};
	for (int i = 0; i < 13; i++){
		strcpy_s((rooms + i)->description, descriptions[i]);
	}
	//--
	Player player;
	Exits exit;
	char command;
	int position = 0;
	do{
		command = player.ReceiveCommand();
		
		exit.Exit(rooms, command, position);
	} while (command != 'q');
}

World::~World(){
	delete[]rooms;
	delete player;
	delete[]exits;
}
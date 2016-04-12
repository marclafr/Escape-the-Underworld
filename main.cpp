#include "World.h"


int main(){
	World my_world;
	Player my_player;
	Room my_room;
	Exit my_exit;

	my_world.CreateWorld();
	my_world.create_items();

	do{
		my_world.command.GetString();
		int CommandDir = my_player.GetDirection(my_world.command);
		if (CommandDir == -1){
			if (my_world.command == "look"){ my_world.Look(); }
			else if (my_world.command == "help"){
				printf("Help menu: \nTo move north, introduce north, n or go north.\nTo move south, introduce south, s or go south.\nTo move east, introduce east, e or go east.\nTo move west, introduce west, w or go west.\n\nThere are also those other commands: \nlook:descrives the place you are in.\nlook + (direction): describe the path you want to take.\nopen/close: Opens or closes a door if it is possible, then the game will ask you the direction the door is.\nNOTICE: if you type, for example, open north directly it won't work!\n\nquit: quits the game.\n");
			}
			else if (my_world.command == "look north" || my_world.command == "look south" || my_world.command == "look east" || my_world.command == "look west"){
				if (my_world.command == "look north"){ my_world.command = "north"; }		//Need to do this because if not, the CommandDir won't be able to compare with the exit direction
				else if (my_world.command == "look south"){ my_world.command = "south"; }
				else if (my_world.command == "look east"){ my_world.command = "east"; }
				else if (my_world.command == "look west"){ my_world.command = "west"; }
				if (my_world.LookDirection(CommandDir) == false){ //Look Directions Commands Function
					printf("Nothing to see here...\n");
				}
			}
			else if (my_world.command.ContainsString("pick") == true){
				if (my_world.PickItem() == false){
					printf("The item is not here or doesn't exist.\n");}
			}
			else if (my_world.command == "look inventory"){
				if (my_world.LookInventory() == false){
					printf("Your inventory is empty.\n");
				}
			}
			else if (my_world.command.ContainsString("drop") == true){
				if (my_world.DropItem() == false){
					printf("Your inventory haven't this item.\n");
				}
			}
		}
		else if (CommandDir == 0 || CommandDir == 1 || CommandDir == 2 || CommandDir == 3){
			if (my_world.command == "n" || my_world.command == "north" || my_world.command == "go north" ||
				my_world.command == "s" || my_world.command == "south" || my_world.command == "go south" ||
				my_world.command == "e" || my_world.command == "east" || my_world.command == "go east" ||
				my_world.command == "w" || my_world.command == "west" || my_world.command == "go west"){
				if (my_world.Move(CommandDir) == false){ //Move Commands Function
					printf("You can't go that way.\n");
				}
			}
			else if (my_world.command == "open"){ my_exit.OpenGate(CommandDir); } //Open function
			else if (my_world.command == "close"){ my_exit.CloseGate(CommandDir); } //Close function			
		}
	} while (my_world.ExitGame() == false);
	return 0;
}

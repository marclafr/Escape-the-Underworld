#include "World.h"


int main(){
	World my_world;
	my_world.CreateWorld();
	do{
		my_world.command.GetString();
		Vector<String> tokens;
		my_world.command.Tokenize(" ,.-_", tokens);
		int CommandDir = my_world.GetDirection(my_world.command, tokens);
		if (CommandDir == -1){
			if (tokens[0] == ("look") && tokens[1] == ("around")){ my_world.Look(); }
			else if (my_world.command == "help"){
				printf("Help menu: \nTo move north, introduce north, n or go north.\nTo move south, introduce south, s or go south.\nTo move east, introduce east, e or go east.\nTo move west, introduce west, w or go west.\n\nThere are also those other commands: \nlook around:descrives the place you are in.\nlook + (direction): describe the path you want to take.\nopen/close: Opens or closes a door if it is possible, then the game will ask you the direction the door is.\nNOTICE: if you type, for example, open north directly it won't work!\n\nquit: quits the game.\n");
			}
			else if (tokens[0] == ("look") && tokens[1] == ("north") || tokens[0] == ("look") && tokens[1] == ("south") || tokens[0] == ("look") && tokens[1] == ("east") || tokens[0] == ("look") && tokens[1] == ("west")){
				if (tokens[0] == ("look") && tokens[1] == ("north"))		{ my_world.command = "north"; }		//Need to do this because if not, the CommandDir won't be able to compare with the exit direction
				else if (tokens[0] == ("look") && tokens[1] == ("south"))	{ my_world.command = "south"; }
				else if (tokens[0] == ("look") && tokens[1] == ("east"))	{ my_world.command = "east"; }
				else if (tokens[0] == ("look") && tokens[1] == ("west"))	{ my_world.command = "west"; }
				if (my_world.LookDirection(CommandDir, tokens) == false){ //Look Directions Commands Function
					printf("Nothing to see here...\n");
				}
			}
			else if (tokens[0]==("pick")){
				if (my_world.PickItem(tokens) == false){
					printf("The item is not here or doesn't exist.\n");}
			}
			else if (my_world.command == "inventory" || my_world.command == "inv" || my_world.command == "i"){
				if (my_world.LookInventory() == false){
					printf("Your inventory is empty.\n");
				}
			}
			else if (my_world.command.ContainsString("drop") == true){
				if (my_world.DropItem(tokens) == false){
					printf("Your inventory haven't this item, you can't drop it.\n");
				}
			}
			else if (tokens[0]==("look")){
				my_world.LookItem(tokens[1]);
			}
			else if (tokens[0] == "equip"){
				if (my_world.EquipItem() == false){
					printf("Item already equipped");
				}
			}
			else if (my_world.command == "stats"){
				my_world.Stats();
			}
		}
		else if (CommandDir == 0 || CommandDir == 1 || CommandDir == 2 || CommandDir == 3){
			if (my_world.command == "n" || my_world.command == "north" || tokens[0] == ("go") && tokens[1] == ("north") ||
				my_world.command == "s" || my_world.command == "south" || tokens[0] == ("go") && tokens[1] == ("south") ||
				my_world.command == "e" || my_world.command == "east"  || tokens[0] == ("go") && tokens[1] == ("east")  ||
				my_world.command == "w" || my_world.command == "west"  || tokens[0] == ("go") && tokens[1] == ("west")) {
				if (my_world.Move(CommandDir) == false){ //Move Commands Function
					printf("You can't go that way.\n");
				}
			}
			else if (my_world.command == "open"){ my_world.OpenGate(CommandDir); } //Open function
			else if (my_world.command == "close"){ my_world.CloseGate(CommandDir); } //Close function			
		}
	} while (my_world.ExitGame() == false);
	return 0;
}

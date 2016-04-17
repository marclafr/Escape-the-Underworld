#include "World.h"


int main(){
	World my_world;
	Vector<int>Counters;
	Counters.PushBack(3);	//Inventory capacity counter: starts with 2 items
	Counters.PushBack(1);	//Weapon equipped counter
	Counters.PushBack(1);	//Armour equipped counter
	Counters.PushBack(1);	//Shield equipped counter
	Counters.PushBack(0);	//Quiver capacity counter
	my_world.CreateWorld();
	do{
		my_world.command.GetString();		
		//Commands that have more than one word:
		if (my_world.command.ContainsString(" ") == true){
			Vector<String> tokens;
			unsigned int num_words = my_world.command.Tokenize(" ,.-_", tokens);
			int CommandDir = my_world.GetDirection(my_world.command, tokens);
			if (CommandDir == -1){
				if (tokens[0] == ("look") && tokens[1] == ("around")){ my_world.Look(); }
				else if (tokens[0] == ("look") && tokens[1] == ("north") || tokens[0] == ("look") && tokens[1] == ("south") || tokens[0] == ("look") && tokens[1] == ("east") || tokens[0] == ("look") && tokens[1] == ("west")){
					if		(tokens[0] == ("look") && tokens[1] == ("north"))	{ my_world.command = "north";}		//Need to do this because if not, the CommandDir won't be able to compare with the exit direction
					else if (tokens[0] == ("look") && tokens[1] == ("south"))	{ my_world.command = "south";}
					else if (tokens[0] == ("look") && tokens[1] == ("east"))	{ my_world.command = "east"; }
					else if (tokens[0] == ("look") && tokens[1] == ("west"))	{ my_world.command = "west"; }
					if (my_world.LookDirection(CommandDir, tokens) == false){ //Look Directions Commands Function
						printf("Nothing to see here...\n\n");
					}
				}
				else if (tokens[0] == ("pick")){
					if (my_world.PickItem(tokens, Counters[0], num_words) == false){
						printf("The item is not here or doesn't exist.\n");
					}
				}
				else if (tokens[0] == ("drop") == true){
					if (my_world.DropItem(tokens, Counters[0], num_words) == false){
						printf("Your inventory haven't this item, you can't drop it.\n\n");
					}
				}
				else if (tokens[0] == ("look")){
					if (num_words == 2){
						my_world.LookItem(tokens[1]);
					}
					else if (num_words == 3){
						my_world.LookItem(tokens[1], tokens[2]);
					}
				}
				else if (tokens[0] == "equip"){
					if (my_world.EquipItem(tokens, Counters[1], Counters[2], Counters[3], Counters[4], num_words) == false){ //[0] == weapon, [1] == armour
						printf("Equip what??\n");
					}
				}
				else if (tokens[0] == "unequip"){
					if (my_world.UnequipItem(tokens, Counters[1], Counters[2], Counters[3], num_words) == false){
						printf("Unequip what??\n\n");
					}
				}
				if (num_words >= 4){		//if this is not used it asserts if you introduce get/put + <less than 2 words> e.g. "get stick"
					if (num_words == 5){
						if (tokens[2] == "statue"){ printf("Statues can't be put into nothing.\n\n"); }
						if (tokens[4] == "statue"){ printf("Statues can't be used to put nothing\n\n"); }
					}
					else{
						if (tokens[0] == "put" && tokens[2] == "into"){
							my_world.FuseItems(tokens, Counters[0], Counters[4]);
						}
						else if (tokens[0] == "get" && tokens[2] == "from"){
							my_world.UnfuseItems(tokens, Counters[0], Counters[4]);
						}
					}
				}
			}
			else if (CommandDir == 0 || CommandDir == 1 || CommandDir == 2 || CommandDir == 3){
				if (tokens[0] == ("go") && tokens[1] == ("north") ||
					tokens[0] == ("go") && tokens[1] == ("south") ||
					tokens[0] == ("go") && tokens[1] == ("east") ||
					tokens[0] == ("go") && tokens[1] == ("west"))  {
					if (my_world.Move(CommandDir) == false){ //Move Commands Function
						printf("You can't go that way.\n\n");
					}
				}
			}		
		}
		//--

		//Commands that only have one word
		else{
			int CommandDir = my_world.GetDirection(my_world.command);
			if (CommandDir == -1){
				if (my_world.command == "help"){
					printf("Help menu: \nTo move north, introduce north, n or go north.\nTo move south, introduce south, s or go south.\nTo move east, introduce east, e or go east.\nTo move west, introduce west, w or go west.\n\n The command 'look around' descrives the place you are in and the items that are in the room.\n\nlook + (direction): describe the path you want to take, but you can't see the items there are if you are not in the same room.\n\nThere are some locked doors, to open or close them use the commands 'open'/'close': Opens or closes a door if it is possible, then the game will ask you the direction the door is.\nNOTICE: if you type, for example, open north directly it won't work!\n\nThe command 'inventory', 'inv', or 'i' allows you to look the items there are in your inventory and the ones that are equipped (if you have any).\nIt also tells you its free space.\n\nIn order to equip or unequip an item, introduce 'equip / unequip <item>'\nThere is a limit of items that could be equipped (1 armour, 1 weapon and 1 shield).\n\nBefore being able to equip an item it must be in the inventory, with the command 'pick <item>' you will get the item you introduce if it is in the same room as you are, and if you need space in your inventory you can drop an item with 'drop <item>'.\n\nIn order to save inventory space you can put items into anothers and get them after(only a few) with the commands 'put <item> into <item>' and 'get <item> from <item>'\n\nYour player have stats, that can be changed deppending on the items you have equipped, to check them introduce the command 'stats'.\n\nquit: quits the game.\n");
				}	//help menu will be more readable if you start the game and introduce "help" :)
				else if (my_world.command == "inventory" || my_world.command == "inv" || my_world.command == "i"){
					if (my_world.LookInventory(Counters[0]) == false){
						printf("Your inventory is empty.\n\n");
					}
				}
				else if (my_world.command == "stats"){
					my_world.Stats();
				}
			}
			else if (CommandDir == 0 || CommandDir == 1 || CommandDir == 2 || CommandDir == 3){
				if (my_world.command == "n" || my_world.command == "north"||
					my_world.command == "s" || my_world.command == "south"||
					my_world.command == "e" || my_world.command == "east" ||
					my_world.command == "w" || my_world.command == "west" ){
					if (my_world.Move(CommandDir) == false){ //Move Commands Function
						printf("You can't go that way.\n\n");
					}
				}		
				else if (my_world.command == "open")			{ my_world.OpenGate(CommandDir); }  //Open function
				else if (my_world.command == "close")	{ my_world.CloseGate(CommandDir); } //Close function	
			}
		}
		//--	
		
	} while (my_world.ExitGame() == false);
	return 0;
}
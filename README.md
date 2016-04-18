Once you have recovered from  crossing the portal you see that you are trapped in here and your weapon, armour and shield are destroyed, but you seem fine.

____________
VERSION 0.1
____________

Instructions to play the game:

	MOVEMENT INSTRUCTIONS:
		There are 4 directions, north, south, east and west,
		The commands to move in each direction are 3, all of them functionals:
			Typing "n", "north", or "go north", you will move north.
			Typing "s", south" or "go south" you will move south.
			Typing "e", "east", or "go east", you will move east.
			Typing "w", "west", or "go west", you will move west.
		If you type a direction and there is no path, the game will say "You can't go that way.".
		The command "go" alone doesn't work but the game itself request you to use a direction with it.

	LOOK COMMAND:
		if you type "look around", the game will descrive the place where you are.
		if you type a direction with "look", e.g. "look north" you will get the description of the place you have in the north
		of your position, if there is nothing in the north, the game will say "Nothing to see here...".

	OPEN/CLOSE COMMANDS:
		There are a couple of rooms that can be closed and opened (they start closed, so you will notice which they are), to
		open or close them, first type "open"/"close", then the game will ask you the direction the door is. If there is no
		door you won't be able to open/close it.
		NOTICE!: The game won't understand if you type, e.g. "Open north" directly.

	HELP:
		If you don't remember the instructions, by writing "help" a menu with all the commands will appear in the screen.

	EXIT THE GAME:
		Just introduce the command "quit".

____________
VERSION 0.5
____________

New commands:

	PICK/DROP ITEMS:
		There are some items around the map, if you are in the same room, you can use the command "pick <item>" to get it on your inventory.
		There is a slot limit in your inventory, so if you want to throw something you can use the command "drop <item>" and the item will remain in the room you drop it.

	EQUIP/UNEQUIP ITEMS:
		You can equip them if there are in your inventory with the command "equip <item>" and unequip with "unequip <item>".

	INVENTORY:
		Now you have an inventory with a slot limit to put the items you want. You can check the items you have in with the commands "inventory" / "inv" / "i".
	This command will also tell you the items that are equipped and the ones that are not, and the number of items you have and the maximum you can have.

	STATS:
		In the next version I will implement a combat system, so in advance the player now have stats that are modified with the items you have equipped. You can check your stats with the command "stats".

	LOOK ITEMS:
		Now you can check the description of the items there are in your inventory with the command "look <item>".
	
	PUT/GET ITEMS INTO OTHER ITEMS:
		Now the game allows you to put items into other items to reduce the slots occuped in the inventory. Actually you are able to put the arrows into the quiver. (and it is needed to use all bows).

	ACTIVATE/DESACTIVATE:
			Some items are Gods statues, those items can be activated and each one have an special effect. Right now there are only 3 activable statues out of 3 that are in the game, the Hades one, that need and NPC to cause its effect (not implemented yet), the Aphrodite statue (which haven't anything yet as i have to think what it will do, but you can activate/desactivate it) and the Hephaestus statue, which upgrades the weapon, armour and shield that you have equipped and then it is destroyed. To use this introduce "activate <GodName> statue" or "desactivate <GodName> statue" (all in lower case).


	COMMANDS UPDATES FROM LAST VERSION:

	- "look around" now also gives the names of the items there are in the room.


Note: If you introduce look + (something that does not match) it will interpret you are trying to look at an item that is in your inventory and the game will say "This item isn't in your inventory".

_________________________________________________________________

Author: Marc Latorre, https://github.com/marclafr

Github link to repository: https://github.com/marclafr/Escape-the-Underworld

link to wiki: https://github.com/marclafr/Escape-the-Underworld/wiki

link to webpage: http://marclafr.github.io/Escape-the-Underworld/
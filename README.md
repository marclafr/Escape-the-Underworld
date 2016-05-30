Once you have recovered from  crossing the portal you see that you are trapped in here and your weapon, armour and shield are destroyed, but you seem fine.
Will you be able to find the artifact, escape this world and save your city?

ADVICES:

	At the start you should look for monsters who won't be a challange and get their souls to buy some equipment: Remember that your equipment was destroyed!
	Also, look for the coins to get though the river Styx and the keys to open doors, they are around the map.

	Before the final battle versus Cerberus, get a good equipment.

	STATUES EXPLANATION(they must be activated):

		HADES:
			Upgrades the damage caused by bows but also the damage caused by the monster centaur.

		HEPHAESTUS:
			Upgrades your equiped weapon, armour and shield. It only has one use, so be smart using it.

		APHRODITE:
			Heals you over time.

		CHRONOS:
			Reduces your special combat abilities cooldown.

________________________

In order to win you have to defeat Cerberus and you will escape this World immediately. There are two finals depending if you found the artifact you were looking for or not.

If your hp are reduced to 0 you will die and lose the game.	
____________
VERSION 1.0
____________

New commands:

	BUY *MONSTER*:
		In the entrance there is a shop (the monster is called "friendly shadow"). In order to look what he can sell you type 'buy "friendly shadow"'. You will need souls (earned by defeating enemies) to buy those items.

	BUY <ITEM> FROM *MONSTER*:
		To buy the items he is selling use the command ' buy "item" from "monster"'.

	SELL <ITEM> TO *MONSTER*:
		To sell an item use the command 'sell "item" to "monster"'.

	ATTACK *MONSTER*:
		Now we can fight the creatures that this world have! by entering the command 'attack "monster"' you will enter in a fight. Be ready to win it because once you attack you can't escape!.
		There is only one creature that will attack you if he reaches the same room that you (the harpy, she is moving around the map so be prepared).

		DURING COMBAT:
		New commands that can only be used while in combat:

			ATTACK:
				A regular attack. Could be dodged by monsters.

			PROTECT:
				One of your 2 special abilities. Raises your defense for this combat. Only one time for combat and has a cooldown of 2 minutes.

			SPECIAL:
				The other special ability you have, an attack with an incremented damage that can't be dodged by enemies. The extra damage is based on your attack to the point it can be doubled.

			CHECK:
				In order to check the stats of your opponent you can use this command.


GOD MODE implemented:

	@money:
		Gives you money.

	@upgrade:
		Gives our hero incredible stats.

	@items:
		Put an exact copy of all existant items in your inventory.

	@kill (only in combat):
		Kills the enemy you were against immediately.


COMMANDS UPDATES FROM LAST VERSION:

	- "look around" now also gives the monsters that are in the room.

____________
VERSION 0.5
____________

New commands:

	PICK/DROP <ITEMS>:
		There are some items around the map, if you are in the same room, you can use the command "pick <item>" to get it on your inventory.
		There is a slot limit in your inventory, so if you want to throw something you can use the command "drop <item>" and the item will remain in the room you drop it.

	EQUIP/UNEQUIP <ITEMS>:
		You can equip them if there are in your inventory with the command "equip <item>" and unequip with "unequip <item>".

	INVENTORY:
		Now you have an inventory with a slot limit to put the items you want. You can check the items you have in with the commands "inventory" / "inv" / "i".
	This command will also tell you the items that are equipped and the ones that are not, and the number of items you have and the maximum you can have.

	STATS:
		In the next version I will implement a combat system, so in advance the player now have stats that are modified with the items you have equipped. You can check your stats with the command "stats".

	LOOK <ITEMS>:
		Now you can check the description of the items there are in your inventory with the command "look <item>".
	
	PUT/GET <ITEMS> INTO OTHER <ITEMS>:
		Now the game allows you to put items into other items to reduce the slots occuped in the inventory. Actually you are able to put the arrows into the quiver. (and it is needed to use all bows).

	ACTIVATE/DESACTIVATE <STATUE>:
			Some items are Gods statues, those items can be activated and each one have an special effect. Right now there are only 3 activable statues out of 3 that are in the game, the Hades one, that need and NPC to cause its effect (not implemented yet), the Aphrodite statue (which haven't anything yet as i have to think what it will do, but you can activate/desactivate it) and the Hephaestus statue, which upgrades the weapon, armour and shield that you have equipped and then it is destroyed. To use this introduce "activate <GodName> statue" or "desactivate <GodName> statue" (all in lower case).


	COMMANDS UPDATES FROM LAST VERSION:

	- "look around" now also gives the names of the items there are in the room.


Note: If you introduce look + (something that does not match) it will interpret you are trying to look at an item that is in your inventory and the game will say "This item isn't in your inventory".

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

	LOOK AROUND:
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

_________________________________________________________________

Author: Marc Latorre, https://github.com/marclafr

Github link to repository: https://github.com/marclafr/Escape-the-Underworld

link to wiki: https://github.com/marclafr/Escape-the-Underworld/wiki

link to webpage: http://marclafr.github.io/Escape-the-Underworld/
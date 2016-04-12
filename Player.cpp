#include <stdio.h>
#include "Player.h"
#include "World.h"


//Commands that implies direction, else return -1
int Player::GetDirection(String command)const{
	if (command == "n" || command == "north" || command == "go north"){ return 0; }
	else if (command == "s" || command == "south" || command == "go south"){ return 1; }
	else if (command == "e" || command == "east" || command == "go east"){ return 2; }
	else if (command == "w" || command == "west" || command == "go west"){ return 3; }
	//Open Command: Asks where to open.
	else if (command == "open"){
		char OpenDirection[15];
		printf("Open where?\n");
		gets_s(OpenDirection, 15);
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
	}//--

	//Close Command: Asks where to close.
	else if (command == "close"){
		char CloseDirection[15];
		printf("Close where?\n");
		gets_s(CloseDirection, 15);
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


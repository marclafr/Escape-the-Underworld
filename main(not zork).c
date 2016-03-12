//Marc Latorre

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

enum position_t {DinningRoom, Kitchen, Bathroom, Bedroom, Pantry};

int main(){

	char direction;
	enum position_t position;
	position = DinningRoom;
	do{
		switch (position){
		case 0: printf("You are in the dinning room.\n");
			printf("Which direction you want to go (n/s/e/w/q)? \n");
			fflush(stdin);
			scanf("%c", &direction);
			if (direction == 'n'){ position = 1; }
			else if (direction == 's'){ position = 3; }
			else if (direction == 'e'){ position = 2; }
			else if (direction == 'w'){
				position = 0;
				printf("You can't go that way.\n\n");
			}
			else{ printf("Incorrect imput. Try again.\n\n"); }
			break;

		case 1: printf("You are in the Kitchen.\n");
			printf("Which direction you want to go (n/s/e/w/q)? \n");
			fflush(stdin); 
			scanf("%c", &direction);
			if (direction == 'n' || direction == 'w'){
				position = 1;
				printf("You can't go that way.\n\n");
			}
			else if (direction == 's'){ position = 0; }
			else if (direction == 'e'){ position = 4; }
			else{ printf("Incorrect imput. Try again.\n\n"); }
			break;

		case 2: printf("You are in the Bathroom.\n");
			printf("Which direction you want to go (n/s/e/w/q)? \n");
			fflush(stdin); 
			scanf("%c", &direction);
			if (direction == 'n' || direction == 's' || direction == 'e'){
				position = 2;
				printf("You can't go that way.\n\n");
			}
			else if (direction == 'w'){ position = 0; }
			else{ printf("Incorrect imput. Try again.\n\n"); }
			break;

		case 3: printf("You are in the Bedroom.\n");
			printf("Which direction you want to go (n/s/e/w/q)? \n");
			fflush(stdin); 
			scanf("%c", &direction);
			if (direction == 'w' || direction == 's' || direction == 'e'){
				position = 3;
				printf("You can't go that way.\n\n");
			}
			else if (direction == 'n'){ position = 0; }
			else{ printf("Incorrect imput. Try again.\n\n"); }
			break;
		case 4: printf("You are in the Pantry.\n");
			printf("Which direction you want to go (n/s/e/w/q)? \n");
			fflush(stdin); 
			scanf("%c", &direction);
			if (direction == 'n' || direction == 's' || direction == 'e'){
				position = 4;
				printf("You can't go that way.\n\n");
			}
			else if (direction == 'w'){ position = 1; }
			else{ printf("Incorrect imput. Try again.\n\n"); }
			break;
		default: printf("Incorrect imput.\n\n");
		}
	} while (direction != 'q');
	printf("\n\n");
	system("pause");
	return 0;
}
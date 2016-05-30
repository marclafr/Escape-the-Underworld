#include "MemLeaks.h"
#include "World.h"
#include <conio.h>
#include <Windows.h>

World* Wor = nullptr;

int main()
{
	ReportMemoryLeaks();
	Wor = new World;
	char key = 'a';
	char input[100];
	int num = 0;
	Vector<String> tokens;
	Wor->CreateWorld();
	uint start_time = GetTickCount();
	uint start_time_combat = GetTickCount();
	uint start_time_item = GetTickCount();
	Monster* cerberus = (Monster*)Wor->entities[0];
	for (int i = 0; i <= NUM_ENTITIES; i++)
	{
		if (Wor->entities[i]->name == "cerberus")
			cerberus = (Monster*)Wor->entities[i];
	}
	while (1)
	{
		if (GetTickCount() - start_time_combat > 2250 && Wor->player->CombatMode == true)
		{
			start_time_combat = GetTickCount();
			Wor->monster->UpdateCombat(Wor->command, Wor->player->enemy);
		}
		if (GetTickCount() - start_time_item > 15000)	//items update are every 15 seconds
		{
			start_time_item = GetTickCount();
			for (int i = 0; i <= NUM_ENTITIES; i++)
			{
				if (Wor->entities[i]->type == ITEM)
				{
					Wor->entities[i]->Update();
					break;
				}				
			}
		}
		if (GetTickCount() - start_time > 20000)	//the rest of updates every 20 seconds
		{
			start_time = GetTickCount();
			for (int i = 0; i <= NUM_ENTITIES; i++)
			{
				if (Wor->entities[i]->name == "harpy")
				{
 					Wor->entities[i]->Update();
				}
			}
		}
		if (_kbhit() != 0)
		{
			key = _getch();
			input[num++] = key;
			printf("%c", key);			
			if (key == '\r')	//enter
			{
				int num_words = 0;
				printf("\n\n");
				input[--num] = '\0';
				num = 0;
				Wor->command = input;
				if (Wor->command.ContainsString(" ") == true)
				{
					num_words = Wor->command.Tokenize(" ,.-_", tokens);
					for (int i = 0; i < tokens.Size(); i++)
					{
						if (tokens[i].ContainsString(""""))
						{
							tokens[i].RemoveChar('"');
						}
					}
				}
				else{ num_words = Wor->command.Tokenize(" ,.-_", tokens); }
				if (tokens.Empty() == false)
				{
					if (Wor->player->CombatMode == false)
					{
						Wor->player->ReceiveCommand(tokens, num_words);
					}
					else
					{
						Wor->player->ReceiveCombatCommand(tokens);
					}
				}
				tokens.Clear();	
			}

			else if (key == '\b' && num > 1) //backspace
			{
				num -= 2;
			}
			
			if (Wor->player->hp <= 0)
			{
				printf("Our hero %s died in this adventure...\n\n", Wor->player->name.c_str());
				printf("Thanks for playing Escape the Underworld!\n\n\t- Created by Marc Latorre");
				getchar();
				break;
			}
			if (cerberus->hp <= 0)
			{
				Wor->Victory();
				break;
			}
			

			if (Wor->command == "quit")
			{
				break;
			}
		}
	}	
	Wor->DeleteWorld();
	delete Wor;
	return 0;
}
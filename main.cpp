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
	while (1)
	{
		if (GetTickCount() - start_time > 3000 && Wor->player->CombatMode == true)	//TODO: Only enters here if you click some key.
		{
			start_time = GetTickCount();
			Wor->monster->Update(Wor->command, Wor->player->enemy);
		}
		if (_kbhit != 0)
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
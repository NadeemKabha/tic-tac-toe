#include <stdio.h>
void show_table(char table[])
{

	for (int i = 0; i < 9; i++)
	{
		printf("|  %c  |", table[i]);
		if ((i + 1) % 3 == 0)
		{
			printf("\n");
		}
	}
}

int check_table(char table[])
{

	for (int i = 0; i < 3; i++)
	{

		if (table[i] == table[i + 3] && table[i] == table[i + 6] && table[i] != ' ')
		{
			return 1;
		}
	}
	for (int i = 0; i < 7; i += 3)
	{
		if (table[i] == table[i + 1] && table[i] == table[i + 2] && table[i] != ' ')
		{
			return 1;
		}
	}

	if ((table[0] == table[4] && table[0] == table[8] && table[0] != ' ') || (table[2] == table[4] && table[2] == table[6] && table[2] != ' '))
	{
		return 1;
	}

	for (int i = 0; i < 9; i++)
	{
		if (table[i] == ' ')
		{
			return 2;
		}
	}
	return 0;
}

int main()
{

	char table[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	int won = 0;
	int inp;
	char end;
	char player = 'X';
	while (!won)
	{
		printf("%c please insert a number between 1-9: \n", player);
		while (scanf("%d", &inp) != 1 || !(inp <= 9 && inp >= 1) || table[inp - 1] != ' ')
		{
			printf("Please choose a valid input!\n");
		}

		table[inp - 1] = player;
		show_table(table);

		switch (check_table(table))
		{
		case 1:

			printf("%c won!\n", player);
			won = 1;
			break;
		case 0:

			printf("draw\n");
			won = 1;
			break;
		}

		if (player == 'X')
			player = 'O';
		else
			player = 'X';
	}
	return 0;
}

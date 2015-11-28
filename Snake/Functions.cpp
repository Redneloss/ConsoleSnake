#include "Functions.h"

int score = 0;
bool gameover = false;
Field standard_field;

void Menu()
{
	int dif;
	cout << "Welcome to the Snake game!\nThe controls are W A S D (small letters)\nDon`t touch the walls!\n";
	cout << "Enter the difficuty:\n(it affects your speed and points you get)\n1 - easy;\n2 - normal;\n3 - hard;\n";
	cout << "4 - lightning;\n";
	cout << "0 - snail (don`t choose it unless you want to sleep).\n";
	cin >> dif;
	cout << "And now press any button to start the game!\n";
	_getch();
	system("cls");
	Game(dif);
}

void Game(int dif)
{
	srand(time(0));
	Snake snake;
	Food food;

	while (!gameover)
	{
		ManageDifficulty(dif);

		if (_kbhit())
		{
			snake.ChangeDirection(_getch());
		}

		snake.Move(food, dif);

		if (gameover == true)
		{
			system("cls");
			break;
		}
		else Output::Show();

		clearscreen();
	}

	Output::MessageForLosers();
}

void ManageDifficulty(int dif)
{
	switch (dif)
	{
	case 0:
		Sleep(1500);
		break;
	case 1:
		Sleep(230);
		break;
	case 2:
		Sleep(110);
		break;
	case 3:
		Sleep(60);
		break;
	case 4:
		break;
	}
}

void Sleep(int milliseconds)
{
	clock_t time_end = clock() + milliseconds;
	while (clock() < time_end)
	{
	}
}

void clearscreen()
{
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
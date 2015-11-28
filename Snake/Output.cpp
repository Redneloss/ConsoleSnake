#include "Output.h"
#define WALL 176 //the ASCII of a wall

void Output::Show()
{
	stringstream ss;

	for (int i = 0; i <= standard_field.GetWidth() + 1; i++)
	{
		for (int j = 0; j <= standard_field.GetLength() + 1; j++)
		{
			if (i == 0 || i == standard_field.GetWidth() + 1)
				ss << static_cast<char>(WALL);
			else
			{
				if (j == 0 || j == standard_field.GetLength() + 1)
					ss << static_cast<char>(WALL);
				else
				if (standard_field.GetMap()[j - 1][i - 1] == SNAKE_PART)
					ss << "o";
				else if (standard_field.GetMap()[j - 1][i - 1] == FOOD)
					ss << "@";
				else if (standard_field.GetMap()[j - 1][i - 1] == SPACE)
					ss << " ";
			}
		}
		ss << '\n';
	}
	
	ss <<  "\nYour score: " << score <<"\n";
	cout << ss.str();
}

void Output::MessageForLosers()
{
	cout << "\aYou died!\nYour final score: " << score << "\n";
}
#include "Food.h"

Food::Food()
{
	Generate();
}

void Food::Generate()
{
	do
	{
		fo_x = rand() % (standard_field.GetLength() - 1);
		fo_y = rand() % (standard_field.GetWidth() - 1);
	} while (standard_field.GetMap()[fo_x][fo_y] == SNAKE_PART);

	standard_field.AddToMap(fo_x, fo_y, FOOD);
}

int Food::GetX() const
{
	return fo_x;
}

int Food::GetY() const
{
	return fo_y;
}
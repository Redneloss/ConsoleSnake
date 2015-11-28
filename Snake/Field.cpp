#include "Field.h"

Field::Field(int length, int width)
{
	f_length = length;
	f_width = width;

	map = new int*[f_length];
	for (int i = 0; i < f_length; i++)
	{
		map[i] = new int[f_width];
		for (int j = 0; j < f_width; j++)
		{
			map[i][j] = SPACE;
		}
	}
}

Field::~Field()
{
	for (int i = 0; i < f_length; i++)
	{
		delete[] map[i];
		map[i] = nullptr;
	}
	delete[] map;
	map = nullptr;
}

void Field::AddToMap(int x, int y, MapLegend legend)
{
	map[x][y] = legend;
}

void Field::EraseAtMap(int x, int y)
{
	map[x][y] = SPACE;
}

int** Field::GetMap() const
{
	return map;
}

int Field::GetLength() const
{
	return f_length;
}

int Field::GetWidth() const
{
	return f_width;
}


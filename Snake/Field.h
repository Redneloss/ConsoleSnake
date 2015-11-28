#include "Enums.h"
#ifndef FIELD
#define FIELD
class Field
{
public:
	Field(int = 40, int = 25);

	~Field();
	
	void AddToMap(int, int, MapLegend);

	void EraseAtMap(int, int);

	int** GetMap() const;
	
	int GetLength() const;
	
	int GetWidth() const;
	
private:
	int f_length;
	int f_width;
	int** map;
};
#endif  FIELD
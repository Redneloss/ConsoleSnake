#include <stdlib.h>
#include "Enums.h"
#include "Field.h"

extern Field standard_field;

#ifndef FOOD_
#define FOOD_
class Food
{
public:
	Food();
	
	void Generate();
	
	int GetX() const;
	
	int GetY() const;

private:
	int fo_x, fo_y;
};
#endif FOOD_
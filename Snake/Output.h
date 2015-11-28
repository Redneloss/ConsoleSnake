#include <iostream>
#include <sstream>
#include "Field.h"

extern int score;
extern Field standard_field;

using namespace std;

#ifndef OUTPUT
#define OUTPUT
class Output
{
public:
	static void Show();
	static void MessageForLosers();
};
#endif OUTPUT
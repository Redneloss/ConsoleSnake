#include <vector>
#include "Enums.h"
#include "Field.h"
#include "Food.h"

extern int score;
extern bool gameover;
extern Field standard_field;

using namespace std;

#ifndef SNAKE
#define SNAKE
#define INIT_SNAKE_LENGTH 3
class Snake
{
public:
	Snake();
	
	void ChangeDirection(char);  //Changes the direction of the head  of a snake
	
	void EatFood(Food&, int);
	
	void TestBorderCollision();

	void TestSelfCollision();

	void Move(Food&, int);
	
private:
	class Part
	{
	public:
		Part(int, int, Direction);

		int GetX() const;

		int GetY() const;

		Direction GetDirection() const;

		void SetX(int);

		void SetY(int);

		void SetDirection(Direction);

	private:
		int p_x;				//Cordinate x
		int p_y;				//Cordinate y
		Direction p_direction;
	};

	vector<Part> s_parts;      //describes coordinates and direction of parts
};
#endif SNAKE
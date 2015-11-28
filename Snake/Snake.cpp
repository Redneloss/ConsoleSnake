#include "Snake.h"

Snake::Part::Part(int x, int y, Direction direction)
{
	p_x = x;
	p_y = y;
	p_direction = direction;
	standard_field.AddToMap(p_x, p_y, SNAKE_PART);
}

int Snake::Part::GetX() const
{
	return p_x;
}

int Snake::Part::GetY() const
{
	return p_y;
}

Direction Snake::Part::GetDirection() const
{
	return p_direction;
}

void Snake::Part::SetX(int x)
{
	p_x = x;
}

void Snake::Part::SetY(int y)
{
	p_y = y;
}

void Snake::Part::SetDirection(Direction d)
{
	p_direction = d;
}

Snake::Snake()
{
	for (int i = 0; i < INIT_SNAKE_LENGTH; i++)
		s_parts.push_back(Part(INIT_SNAKE_LENGTH - i + standard_field.GetLength() / 4, standard_field.GetWidth() / 2, RIGHT));
}

void Snake::ChangeDirection(char ch)  //Changes the direction of the head  of a snake
{
	switch (ch)
	{
	case 'w':
		if (s_parts[0].GetDirection() != DOWN) s_parts[0].SetDirection(UP);
		break;
	case 'd':
		if (s_parts[0].GetDirection() != LEFT) s_parts[0].SetDirection(RIGHT);
		break;
	case 's':
		if (s_parts[0].GetDirection() != UP) s_parts[0].SetDirection(DOWN);
		break;
	case 'a':
		if (s_parts[0].GetDirection() != RIGHT) s_parts[0].SetDirection(LEFT);
		break;
	}
}

void Snake::EatFood(Food& food, int dif)
{
	switch (s_parts.back().GetDirection())
	{
	case LEFT:
		s_parts.push_back(Part(s_parts.back().GetX() + 1, s_parts.back().GetY(), LEFT));
		break;
	case RIGHT:
		s_parts.push_back(Part(s_parts.back().GetX() - 1, s_parts.back().GetY(), RIGHT));
		break;
	case UP:
		s_parts.push_back(Part(s_parts.back().GetX(), s_parts.back().GetY() + 1, UP));
		break;
	case DOWN:
		s_parts.push_back(Part(s_parts.back().GetX(), s_parts.back().GetY() - 1, DOWN));
		break;
	}

	switch (dif)
	{
	case 0:
		score += 150;
		break;
	case 1:
		score += 10;
		break;
	case 2:
		score += 20;
		break;
	case 3:
		score += 30;
		break;
	case 4:
		score += 70;
		break;
	}

	standard_field.AddToMap(food.GetX(), food.GetY(), SNAKE_PART);
}

void Snake::TestBorderCollision()
{
	if (s_parts[0].GetX() == 0 && s_parts[0].GetDirection() == LEFT ||
		s_parts[0].GetX() == standard_field.GetLength() - 1 && s_parts[0].GetDirection() == RIGHT ||
		s_parts[0].GetY() == 0 && s_parts[0].GetDirection() == UP ||
		s_parts[0].GetY() == standard_field.GetWidth() - 1 && s_parts[0].GetDirection() == DOWN)
	{
		gameover = true;
	}
}

void Snake::TestSelfCollision()
{
	for (int i = 1; i < s_parts.size(); i++)
	{
		if (s_parts[0].GetX() == s_parts[i].GetX() && s_parts[0].GetY() == s_parts[i].GetY())
		{
			gameover = true;
		}
	}
}

void Snake::Move(Food& food, int dif)
{
	TestBorderCollision();
	if (gameover)
	{
		return;
	}

	for (int i = 0; i < s_parts.size(); i++)
	{
		standard_field.EraseAtMap(s_parts[i].GetX(), s_parts[i].GetY());
		switch (s_parts[i].GetDirection())
		{
		case UP:
			s_parts[i].SetY(s_parts[i].GetY() - 1);
			break;
		case RIGHT:
			s_parts[i].SetX(s_parts[i].GetX() + 1);
			break;
		case DOWN:
			s_parts[i].SetY(s_parts[i].GetY() + 1);
			break;
		case LEFT:
			s_parts[i].SetX(s_parts[i].GetX() - 1);
			break;
		}

		standard_field.AddToMap(s_parts[i].GetX(), s_parts[i].GetY(), SNAKE_PART);
	}

	if (s_parts[0].GetX() == food.GetX() && s_parts[0].GetY() == food.GetY())
	{
		EatFood(food, dif);
		food.Generate();										    
	}

	for (int i = s_parts.size() - 1; i > 0; i--)
	{
		if (s_parts[i].GetDirection() != s_parts[i - 1].GetDirection())
		{
			s_parts[i].SetDirection(s_parts[i - 1].GetDirection());
		}
	}

	TestSelfCollision();
}
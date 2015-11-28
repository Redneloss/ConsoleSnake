#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>

#include "Field.h"
#include "Food.h"
#include "Snake.h"
#include "Output.h"

using namespace std;

#ifndef MENU
#define MENU
void Menu();
#endif MENU

#ifndef GAME
#define GAME
void Game(int);
#endif GAME

#ifndef MANAGEDIFFICULTY
#define MANAGEDIFFICULTY
void ManageDifficulty(int);
#endif MANAGEDIFFICULTY

#ifndef SLEEP
#define SLEEP
void Sleep(int);
#endif SLEEP

#ifndef CLEARSCREEN
#define CLEARSCREEN
void clearscreen();
#endif CLEARSCREEN
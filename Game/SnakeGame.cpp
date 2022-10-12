#include <iostream>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;
const int MaxSize = 10000;
enum Direction { RIGHT, LEFT, UP, DOWN };
bool perp = false;
int delay = 50;
int TimeBarBeginCol = 150;
int TimeScore = 10;
int ScoreIncrease = 1;
unsigned long long int TStart;
struct Position
{
	int ri = 0;
	int ci = 0;
};
Position ConsoleSize;
struct Snake
{
	Position Ps[MaxSize];
	int size = 0;
	signed char ch = { (signed char)(-37) };
	Position Food;
	Position SFood;	//Special food generated after some food items eaten
	int Score = 0;
	int Eaten = 0;
	bool classic = false;
};

string UserChoices(Snake& S, bool& load, Direction &Dir)
{
	string choice, Name;
	string classic;
	char ch = -37;
	char contchoice;
	cout << "Enter Your Name ";
	getline(cin, Name);
	cout << "Hey " << Name << " ";

	do
	{
		cout << "Enter the level:\n"
			<< "1. Easy\t\t" << ch << endl << endl
			<< "2. Medium\t" << ch << ch << endl << endl
			<< "3. Hard\t\t" << ch << ch << ch << endl;
		getline(cin, choice);
		for (int i = 0; i < (choice.length()); i++)
		{
			choice[i] = tolower(choice[i]);
		}
	} while (choice != "easy" && choice != "medium" && choice != "hard" && choice != "1" && choice != "2" && choice != "3");
	if (choice == "easy" || choice == "1")
	{
		delay = 100;
		ScoreIncrease = 1;
	}
	else if (choice == "medium" || choice == "2")
	{
		delay = 50;
		ScoreIncrease = 2;
	}
	else if (choice == "hard" || choice == "3")
	{
		delay = 20;
		ScoreIncrease = 3;
	}
	do
	{
		cout << "Do you want classic mode ";
		getline(cin, classic);
		for (int i = 0; i < (classic.length()); i++)
		{
			classic[i] = tolower(classic[i]);
		}
	} while (classic != "classic" && classic != "yes" && classic != "y" && classic != "no" && classic != "not classic" && classic != "notclassic" && classic != "n");
	if (classic[0] != 'n')
		S.classic = true;
	cout << "\n\n\t\t\t THE GAME Is Starting...";
	Sleep(1000);
	return Name;
}
void CursorControl(bool CursorFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = CursorFlag;
	cursorInfo.dwSize = 2;				//Someone on stackoverflow said to set the dwSize value between 1 and 100 otherwise SetConsoleCursorInfo will fail
	SetConsoleCursorInfo(out, &cursorInfo);
}
void GotoRowCol(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOutput, scrn);
}
void GetConsoleSize(int& rows, int& columns)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
}
void PrintWall()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);
	for (int i = 1; i < ConsoleSize.ri; i++)
	{
		GotoRowCol(i, 0);
		cout << (char)-37;
		GotoRowCol(i, ConsoleSize.ci - 1);
		cout << (char)-37;
	}
	for (int j = 0; j < ConsoleSize.ci; j++)
	{
		GotoRowCol(1, j);
		cout << (char)-37;
		GotoRowCol(ConsoleSize.ri - 1, j);
		cout << (char)-37;
	}
	SetConsoleTextAttribute(hConsole, 15);
}
void TimerBar(char& ch)
{
	TimeBarBeginCol = 15;
	TimeScore = 10;
	GotoRowCol(0, TimeBarBeginCol);
	for (int i = 0; i < 10; i++)
	{
		cout << ch;
	}
}
void OneTimeBarCharacterDelete(Snake& S)
{
	GotoRowCol(0, TimeBarBeginCol);
	cout << " ";
	TimeBarBeginCol++;
	TimeScore--;
	if (TimeScore == 0)
	{
		GotoRowCol(S.SFood.ri, S.SFood.ci);
		cout << " ";
	}
}
void TimeElapsed(Snake& S)
{
	unsigned int TNow = time(0);
	if (TNow == TStart + 1 && TimeScore >= 0)
	{
		TStart++;
		OneTimeBarCharacterDelete(S);
	}
}
void FoodGeneration(Snake& S)
{
	unsigned int seed = time(0);
	srand(seed); 												//S.Score's value changes every time
	S.Food.ri = (rand() % (ConsoleSize.ri - 3)) + 2;			//Food Should not be in the first two rows(2) or in the last row(-(2+1)) 
	S.Food.ci = (rand() % (ConsoleSize.ci - 2)) + 1;
	for (int i = 0; i <= S.size; i++)
	{
		if (S.Ps[i].ri == S.Food.ri && S.Ps[i].ci == S.Food.ci)
			FoodGeneration(S);
		else
			continue;
	}
	GotoRowCol(S.Food.ri, S.Food.ci);
	cout << (char)232;
}
void SpecialFoodGeneration(Snake& S)
{
	int x = 0, y = 0;
	char ch = (char)254;				//time-bar charachter
	srand(S.Score);
	S.SFood.ri = (rand() % (ConsoleSize.ri - 3)) + 2;		//Food should not be generated in the first row
	S.SFood.ci = (rand() % (ConsoleSize.ci - 2)) + 1;
	for (int i = 0; i <= S.size; i++)
	{
		if (S.Ps[i].ri == S.SFood.ri && S.Ps[i].ci == S.SFood.ci)
			SpecialFoodGeneration(S);
	}
	GotoRowCol(S.SFood.ri, S.SFood.ci);
	cout << "@";
	TStart = time(0);
	TimerBar(ch);
}
void SpecialFoodEaten(Snake& S)
{
	char ch = ' ';
	TimeElapsed(S);
	if (S.Ps[0].ri == S.SFood.ri && S.Ps[0].ci == S.SFood.ci)
	{
		S.size++;
		Beep(1400, 10);
		S.Score = (S.Score + TimeScore);
		TimerBar(ch);
	}
}
void FoodEaten(Snake& S)
{
	if (S.Ps[0].ri == S.Food.ri && S.Ps[0].ci == S.Food.ci)
	{
		S.size++;
		Beep(1400, 10);
		S.Score += ScoreIncrease;
		S.Eaten++;
		if (delay > 1)
		{
			delay--;
		}
		if (S.Eaten % 8 == 0)
		{
			SpecialFoodGeneration(S);
		}
		FoodGeneration(S);
	}
}
void InitSnake(Snake& S)
{
	//srand((unsigned int)time(0));
	S.Ps[0].ri = (rand() % (ConsoleSize.ri - 3)) + 2;
	S.Ps[0].ci = (rand() % (ConsoleSize.ci - 2)) + 1;
	S.Ps[1].ri = S.Ps[0].ri;
	S.Ps[1].ci = S.Ps[0].ci - 1;
	S.Ps[2].ri = S.Ps[0].ri;
	S.Ps[2].ci = S.Ps[0].ci - 2;
	S.size = 3;
	FoodGeneration(S);
}
void PrintSnake(Snake& S)
{
	char ch = -37;
	if (S.Ps[0].ri > (ConsoleSize.ri - 2))
		S.Ps[0].ri = 2;
	if (S.Ps[0].ri <= 1)
		S.Ps[0].ri = (ConsoleSize.ri - 2);
	if (S.Ps[0].ci >= (ConsoleSize.ci - 1))
		S.Ps[0].ci = 1;
	if (S.Ps[0].ci <= 0)
		S.Ps[0].ci = (ConsoleSize.ci - 2);
	for (int i = 0; i < S.size; i++)
	{
		GotoRowCol(S.Ps[i].ri, S.Ps[i].ci);
		cout << S.ch;
	}
}
bool SnakeKill(Snake& S)
{
	for (int i = 1; i < S.size; i++)
	{
		if (S.Ps[0].ri == S.Ps[i].ri && S.Ps[0].ci == S.Ps[i].ci)
			return true;
	}
	if (S.classic)
	{
		if (S.Ps[0].ri > (ConsoleSize.ri - 2))
			return true;
		if (S.Ps[0].ri <= 1)
			return true;
		if (S.Ps[0].ci >= (ConsoleSize.ci - 1))
			return true;
		if (S.Ps[0].ci <= 0)
			return true;
	}
	return false;
}
void EraseSnake(Snake& S)
{

	for (int i = 0; i < S.size; i++)
	{
		GotoRowCol(S.Ps[i].ri, S.Ps[i].ci);
		cout << " ";
	}
}
bool ChangeDir(Direction& Dir)
{
	int key = _getch();
	if (key == 224)
	{
		key = _getch();
		switch (key)
		{
		case 72:
			if (Dir != DOWN)
				Dir = UP;
			break;
		case 80:
			if (Dir != UP)
				Dir = DOWN;
			break;
		case 75:
			if (Dir != RIGHT)
				Dir = LEFT;
			break;
		case 77:
			if (Dir != LEFT)
				Dir = RIGHT;
			break;
		}
	}
	else if (key == 27)
	{
		return true;
	}
	return false;
}
void ChangeSnakeDirection(Snake& S, Direction Dir)
{
	switch (Dir)
	{
	case UP:
		S.Ps[0].ri--;
		break;
	case DOWN:
		S.Ps[0].ri++;
		break;
	case LEFT:
		S.Ps[0].ci--;
		break;
	case RIGHT:
		S.Ps[0].ci++;
		break;
	}
}
void MoveSnake(Snake& S, Direction Dir)
{
	for (int i = S.size; i > 0; i--)
	{
		S.Ps[i] = S.Ps[i - 1];
	}
	ChangeSnakeDirection(S, Dir);
}

int main()
{
	Snake S;
	Direction Dir = RIGHT;
	Position ConsoleResize;
	bool save = false, loaded = false;
	string Name = UserChoices(S, loaded, Dir);
	bool Setdel = false;
	system("CLS");
	GetConsoleSize(ConsoleSize.ri, ConsoleSize.ci);
	if (S.classic) {
		PrintWall();
	}
	if (!loaded)
		InitSnake(S);
	else
		FoodGeneration(S);
	do
	{
		GotoRowCol(0, 0);
		cout << "Score is " << S.Score;
		GetConsoleSize(ConsoleResize.ri, ConsoleResize.ci);
		if (ConsoleResize.ri != ConsoleSize.ri || ConsoleResize.ci != ConsoleSize.ci)
		{
			ConsoleSize = ConsoleResize;
			system("cls");
			if (S.classic) {
				PrintWall();
			}
			FoodGeneration(S);
		}
		FoodEaten(S);
		SpecialFoodEaten(S);
		CursorControl(false);

		if (_kbhit())
		{
			if (ChangeDir(Dir))
			{
				GotoRowCol(ConsoleSize.ri + 1, 0);
				cout << "Saving the game and Exiting ";
				save = true;
				break;
			}
			//To clear the keyboard buffer
			while (_kbhit())
				_getch();
		}
		else
		{
			EraseSnake(S);
			MoveSnake(S, Dir);
			if (SnakeKill(S))
			{
				PrintSnake(S);
				GotoRowCol(40 / 2, 160 / 2);
				cout << "\nGAME _OVER\n\n\n\n\n\n\n\n\n\n\n\a";
				save = true;
				break;
			}
			PrintSnake(S);
			if (Dir == UP || Dir == DOWN)
			{
				delay += 20;
				Setdel = true;
			}
			Sleep(delay);
			if (Setdel)
			{
				delay -= 20;
				Setdel = false;
			}
		}
	} while (!save);
}

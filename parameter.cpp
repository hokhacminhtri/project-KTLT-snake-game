#include "parameter.h"

void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Ham to mau
void TextColor(int color)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, color);
}


void drawChar(int x, int y, int color, int character) {
	char symbol = character;
	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	destCoord.X = x;
	destCoord.Y = y;
	SetConsoleCursorPosition(hStdout, destCoord);
	SetConsoleTextAttribute(hStdout, color);
	cout << symbol;
	// Draw symbol

	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleTextAttribute(hStdout, 15);
	SetConsoleCursorInfo(hStdout, &info);
	// Remove cursor 
}

void drawStr(int x, int y, int color, string longString) {
	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	destCoord.X = x;
	destCoord.Y = y;
	SetConsoleCursorPosition(hStdout, destCoord);
	SetConsoleTextAttribute(hStdout, color);
	cout << longString;
	// Draw symbol

	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleTextAttribute(hStdout, 15);
	SetConsoleCursorInfo(hStdout, &info);
	// Remove cursor 
}

bool IsValid(SNAKE* snake, int x, int y)
{
	int i;
	for (i = 0; i < snake->length; i++)
	{
		if (snake->body[i].x == x && snake->body[i].y == y)
		{
			return false;
		}
	}
}

void GenerateFruit(SNAKE* snake, POS& fruit, int& vt)
{
	int x, y;
	//char fruit_name[39] = { 8,1,2,0,5,8,6,1,8,1,2,0,6,0,9,1,8,1,2,0,5,9,8,1,8,1,2,0,3,2,2,1,8,1,2,0,3,1,6 };
	srand((unsigned int)time(NULL));
	do
	{
		x = rand() % (WIDTH_CONSOLE - 2) + 1;
		y = rand() % (HEIGHT_CONSOLE - 2) + 1;
	} while (IsValid(snake, x, y) == false);
	fruit.x = x;
	fruit.y = y;
	fruit.c = char(fruit_name[vt]);
	vt++;
}

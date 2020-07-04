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

bool IsValid(SNAKE* snake, int x, int y) {
	int i;
	for (i = 0; i < snake->length; i++) {
		if (snake->body[i].x == x && snake->body[i].y == y) {
			return false;
		}
	}
	return true;
}

//Ham kiem tra vi tri fruit có trung voi Gate
bool IsValid1(POS* gate, int x, int y)
{
	int i;
	//Kiem tra fruit trung voi cong
	for (i = 0; i < GATE_SIZE; i++) {
		if (gate[i].x == x && gate[i].y == y) {
			return false;
		}
	}
	//Kiem tra cac vi tri xung quanh cong
	for (i = 0; i < GATE_SIZE; i++) {
		if (gate[i].x - 1 == x || gate[i].y - 1 == y || gate[i].x - 4 == x || gate[i].y + 1 == y) {
			return false;
		}
	}
	return true;
}


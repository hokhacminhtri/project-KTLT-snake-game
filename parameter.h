#pragma once

#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include<string>
#include "timer.h"
#include<thread>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
#include "snake.h"
#include<fstream>
#include<sstream>
#include "saveandload.h"
using namespace std;
void FixConsoleWindow();
void GotoXY(int x, int y);
void TextColor(int color);
#define headColor 11
#define tailColor 12
#define pauseGame    0x50 // P
#define exitGame     0x58 // X
#define saveGame	 0x4C // L
#define loadGame	 0x54 // T
#define continueGame 0x43 // C
#define up 105
#define down 107
#define left 106
#define right 108
#define space 32
#define red            12
#define green          10
#define WIDTH_CONSOLE  70
#define HEIGHT_CONSOLE 20
#define GATE_SIZE 4
const char fruit_name[] = "812058618120609181205981812032218120316";
void drawChar(int x, int y, int color, int character);
void drawStr(int x, int y, int color, string longString);
bool IsValid(SNAKE* snake, int x, int y);
void GenerateFruit(SNAKE* snake, POS& fruit, int& vt);

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
#include "object.h"
#include<fstream>
#include<sstream>
#include "saveandload.h"
using namespace std;
void FixConsoleWindow();
void GotoXY(int x, int y);
void TextColor(int color);
#define red            12
#define green          10
#define pink           13
#define headColor 12
#define tailColor 10
#define fruitColor 13
#define continueGame 0x43 // C
#define up 105
#define down 107
#define left 106
#define right 108
#define space 32
#define WIDTH_CONSOLE  70
#define HEIGHT_CONSOLE 20
#define OFFSET_X 25
#define OFFSET_Y 3
#define GATE_SIZE 4
#define MAX_LEVEL 7
const char fruit_name[] = "1812058618120609";
void drawChar(int x, int y, int color, int character);
void drawStr(int x, int y, int color, string longString);
bool IsValid(SNAKE* snake, int x, int y);

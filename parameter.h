#pragma once

#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include "timer.h"
#include<thread>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
#include "snake.h"
using namespace std;
void FixConsoleWindow();
void GotoXY(int x, int y);
void TextColor(int color);


// Ham ve 
#define headColor 11
#define tailColor 12
#define pauseGame    0x50 // P
#define exitGame     0x58 // X
#define continueGame 0x43 // C
#define up 105
#define down 107
#define left 106
#define right 108
#define space 32
#define red            12
#define green          10
#define WIDTH_CONSOLE  10
#define HEIGH_CONSOLE 10
const char fruit_name[] =  "812058618120609181205981812032218120316";
void drawChar(int x, int y, int color, int character);
void drawStr(int x, int y, int color, string longString);




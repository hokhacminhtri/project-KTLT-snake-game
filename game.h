#pragma once

#ifndef _GAME_
#define _GAME_

#include "parameter.h"
#include "saveandload.h"
#include <mmsystem.h>	//thu vien chen nhac

#pragma comment (lib, "winmm.lib")

/***************Cac ham tao giao dien game***************/
void DrawBoard(int x, int y, int width, int height);
void OpenGame();
void Loading();
void Option(int option1, int option2);
void Menu();
void NewGame();
void NewGame(GAMEOBJECT* gameObject);
bool Input(GAMEOBJECT* gameObject);
void Update(GAMEOBJECT* gameObject);
void Render(GAMEOBJECT* gameObject);
bool EndGame(SNAKE* snake);		//xu ly ket thuc game
void GuideTable();	//bang huong dan choi game

#endif // !_GAME_



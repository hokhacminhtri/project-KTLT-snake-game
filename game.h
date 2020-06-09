#pragma once
#include "parameter.h"
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

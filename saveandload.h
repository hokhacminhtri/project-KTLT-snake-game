#pragma once
#include "parameter.h"

using namespace std;

bool EndGame();
int SaveGame(GAMEOBJECT* gameObject);

GAMEOBJECT* LoadGame(string saveFile);
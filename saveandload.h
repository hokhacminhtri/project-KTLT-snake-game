#pragma once
#include "parameter.h"

using namespace std;

int SaveGame(GAMEOBJECT* gameObject);

GAMEOBJECT* LoadGame(string saveFile);
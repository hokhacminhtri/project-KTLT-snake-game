#include "saveandload.h"


int SaveGame(GAMEOBJECT* gameObject)
{
	string saveFile;
	GotoXY(OFFSET_X + 20, 25);
	cout << "                               ";
	GotoXY(OFFSET_X + 20, 25);
	cout << "Nhap ten file save: ";
	cin >> saveFile;
	ofstream outputStream(saveFile, ios::trunc);	//tao hoac mo file, ios::trunc de xoa content neu file da co san
	unsigned int i;
	outputStream << gameObject->fruit->x << "-" << gameObject->fruit->y << "-" << gameObject->fruit->c << endl;
	for (i = 0; i < 4; i++)
		outputStream << gameObject->gate[i].x << "-" << gameObject->gate[i].y << "-" << gameObject->gate[i].c << endl;	//position cua gate
	outputStream << gameObject->snake->length << "-" << gameObject->snake->speed << "-" << gameObject->snake->dir << "-" << gameObject->snake->tmpDir << "-" << gameObject->snake->haveGate << "-" << gameObject->snake->prevEat << "-" << gameObject->snake->vt << endl;
	for (i = 0; i < gameObject->snake->length; i++)
		outputStream << gameObject->snake->body[i].x << "-" << gameObject->snake->body[i].y << "-" << gameObject->snake->body[i].c << endl;	// position cua cac phan co the con ran
	outputStream.close();
	return 1;
}

GAMEOBJECT* LoadGame(string saveFile)
{
	ifstream inputStream(saveFile);
	string fruit_x, fruit_y, fruit_c;
	string gate_x, gate_y, gate_c;
	string length, speed, dir, tmpDir, haveGate, prevEat, vt;
	string snake_x, snake_y, snake_c;
	string readingLine;
	GAMEOBJECT* gameObject = initGameObject();
	if (inputStream.is_open())
	{
		getline(inputStream, readingLine);
		stringstream ss_fruit(readingLine);
		unsigned int i;
		// Read fruit info
		getline(ss_fruit, fruit_x, '-');
		gameObject->fruit->x = stoi(fruit_x);
		getline(ss_fruit, fruit_y, '-');
		gameObject->fruit->y = stoi(fruit_y);
		getline(ss_fruit, fruit_c, '-');
		gameObject->fruit->c = fruit_c[0];
		// Read gate info
		for (i = 0; i < 4; i++)
		{
			getline(inputStream, readingLine);
			stringstream ss_gate(readingLine);
			getline(ss_gate, gate_x, '-');
			getline(ss_gate, gate_y, '-');
			getline(ss_gate, gate_c, '-');
			gameObject->gate[i].x = stoi(gate_x);
			gameObject->gate[i].y = stoi(gate_y);
			gameObject->gate[i].c = gate_c[0];
		}
		// Read snake info
		getline(inputStream, readingLine);
		stringstream ss_snake(readingLine);
		getline(ss_snake, length, '-');
		gameObject->snake->length = stoi(length);
		getline(ss_snake, speed, '-');
		gameObject->snake->speed = stoi(speed);
		getline(ss_snake, dir, '-');
		gameObject->snake->dir = stoi(dir);
		getline(ss_snake, tmpDir, '-');
		gameObject->snake->tmpDir = stoi(tmpDir);
		getline(ss_snake, haveGate, '-');
		if (stoi(haveGate)) gameObject->snake->haveGate = true;
		else gameObject->snake->haveGate = false;
		getline(ss_snake, prevEat, '-');
		if (stoi(prevEat)) gameObject->snake->prevEat = true;
		else gameObject->snake->prevEat = false;
		getline(ss_snake, vt, '-');
		gameObject->snake->vt = stoi(vt);

		gameObject->snake->body = (POS*)malloc(gameObject->snake->length * sizeof(POS));
		i = 0;
		while (getline(inputStream, readingLine))
		{
			stringstream ss(readingLine);
			getline(ss, snake_x, '-');
			getline(ss, snake_y, '-');
			getline(ss, snake_c, '-');
			gameObject->snake->body[i].x = stoi(snake_x);
			gameObject->snake->body[i].y = stoi(snake_y);
			gameObject->snake->body[i].c = snake_c[0];
			i++;
		}
	}
	inputStream.close();
	return gameObject;
}
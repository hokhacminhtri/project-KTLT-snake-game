#include "saveandload.h"

int SaveGame(SNAKE* snake)
{
	string saveFile;
	GotoXY(80, 10);
	system("pause");
	GotoXY(80, 10);
	cout << "                               ";
	GotoXY(80, 10);
	cout << "Type save file name: ";
	cin >> saveFile;
	ofstream outputStream(saveFile, ios::trunc);
	unsigned int i;
	outputStream << snake->length << "-" << snake->speed << "-" << snake->dir << "-" << snake->tmpDir << "-" << snake->haveGate << "-" << snake->prevEat << endl;
	for (i = 0; i < snake->length; i++)
		outputStream << snake->body[i].x << "-" << snake->body[i].y << "-" << snake->body[i].c << endl;
	outputStream.close();
	return 1;
}

SNAKE* LoadGame(string saveFile)
{
	ifstream inputStream(saveFile);
	string length, speed, dir, tmpDir, haveGate, prevEat;
	string x, y, c;
	string readingLine;
	SNAKE* snake = (SNAKE*)malloc(sizeof(SNAKE));
	getline(inputStream, readingLine);
	stringstream ss(readingLine);

	getline(ss, length, '-');
	snake->length = stoi(length);
	getline(ss, speed, '-');
	snake->speed = stoi(speed);
	getline(ss, dir, '-');
	snake->dir = stoi(dir);
	getline(ss, tmpDir, '-');
	snake->tmpDir = stoi(tmpDir);
	getline(ss, haveGate, '-');
	if (stoi(haveGate)) snake->haveGate = true;
	else snake->haveGate = false;
	getline(ss, prevEat, '-');
	if (stoi(prevEat)) snake->prevEat = true;
	else snake->prevEat = false;

	// cout << length << "-" << speed << "-" << dir << "-" << tmpDir << "-" << haveGate << "-" << prevEat << endl;
	snake->body = (POS*)malloc(snake->length * sizeof(POS));
	int i = 0;
	while (getline(inputStream, readingLine))
	{
		stringstream ss(readingLine);
		getline(ss, x, '-');
		getline(ss, y, '-');
		getline(ss, c, '-');
		snake->body[i].x = stoi(x);
		snake->body[i].y = stoi(y);
		snake->body[i].c = c[0];
		i++;
	}
	inputStream.close();
	return snake;
}
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
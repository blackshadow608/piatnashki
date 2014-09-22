
#include "header.h"

#include <iomanip>
#include <conio.h>
#include <iostream>
#include <clocale>
#include <ctime>
#include <cstdlib>
using namespace std;

Field::Field()
{
	pozX = 3;
	pozY = 3;
	int n = 1;
	for (int i = 0; i < 4; i++)
	for (int j = 0; j < 4; j++)
	{
		mas[i][j] = n;
		n++;
	}
	mas[3][3] = 0;
}

void Field::view()
{
	system("cls");
	cout << "----------------" << endl;

	for (int i = 0; i < 4; i++)
	{

		for (int j = 0; j < 4; j++)
		{

			cout << setw(3);
			if (mas[i][j] == 0)cout << "| ";
			else
				cout << mas[i][j];
			cout << "|";
		}
		cout << endl;
		cout << "----------------" << endl;
	}
	if (location()){ cout << endl << "YOU WIN!!!"; }
	else
	{
		cout << "press ESC to exit";
	}
}

void Field::moveRight()
{
	if (pozX<3){
		mas[pozY][pozX] = mas[pozY][pozX + 1];
		mas[pozY][pozX + 1] = 0;
		pozX++;
	}
}

void Field::moveLeft()
{
	if (pozX>0){
		mas[pozY][pozX] = mas[pozY][pozX - 1];
		mas[pozY][pozX - 1] = 0;
		pozX--;
	}
}

void Field::moveUp()
{
	if (pozY<3){
		mas[pozY][pozX] = mas[pozY + 1][pozX];
		mas[pozY + 1][pozX] = 0;
		pozY++;
	}
}

void Field::moveDown()
{
	if (pozY>0){
		mas[pozY][pozX] = mas[pozY - 1][pozX];
		mas[pozY - 1][pozX] = 0;
		pozY--;
	}
}

bool Field::location()
{
	int n = 1, controlarray[4][4];
	for (int i = 0; i < 4; i++)
	for (int j = 0; j < 4; j++)
	{
		controlarray[i][j] = n;
		n++;
	}
	controlarray[3][3] = 0;
	for (int i = 0; i < 4; i++)
	for (int j = 0; j < 4; j++)
	{
		if (mas[i][j] != controlarray[i][j])return false;
	}
	return true;
}


void Field::rnd()
{
	srand(time(0));
	for (int i = 0; i < 1000; i++)
	{
		int k = rand() % 4 + 1;
		if (k == 1){ moveLeft(); }
		else
		if (k == 2){ moveRight(); }
		else
		if (k == 3){ moveDown(); }
		else
		if (k == 4){ moveUp(); };


	}
}


int Field::operator[] (int i)
{
	if (i < 0 || i > 15)
	{
		cout << "InputError" << endl;
		system("PAUSE");
		exit(1);
	}

	if (i < 5)
		return mas[0][i];
	if ((i > 4) && (i < 9))
		return mas[1][i % 4 - 1];
	if ((i > 8) && (i < 13))
		return mas[2][i % 8 - 1];
	if ((i > 12) && (i < 16))
		return mas[3][i % 12 - 1];
}

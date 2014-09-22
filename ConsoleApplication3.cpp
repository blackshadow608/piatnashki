/**@mainpage "Piatnashki" game

*/
#include <iomanip>
#include <conio.h>
#include <iostream>
#include <clocale>
#include <ctime>
#include <cstdlib>
#include "header.h"

using namespace std;


/**@brief Game menu
@detalied Visualises game menu and control player's choice
@return Player's choice
*/
int menu();


void main()
{
	Field ptn;
	ptn.rnd();

start:
	int choice = menu();
	setlocale(LC_CTYPE, "Russian");
	if (choice == 2){ cout << "Move the empty element to retrieve correct cells position (from 1 to 15)"; };
	if (choice == 3)
	{
		cout << "Enter the cell number (from 0 to 15)" << endl;
		int ch;
		cin >> ch;
		cout << "The value of " << ch << " is " << ptn[ch] << endl;
		system("PAUSE");
		goto start;
	}
	if (choice == 4){ return; }
	if (choice == 1)
	{
		ptn.view();
		char act;
		int ch;
		while (1)
		{
			act = _getch();
			ch = static_cast<int>(act);

			if (ch == 27)
			{
				exit(0);
				break;
			}
			else if (ch == 77)
			{
				ptn.moveLeft();
				ptn.view();
			}
			else if (ch == 75)
			{
				ptn.moveRight();
				ptn.view();
			}
			else if (ch == 72)
			{
				ptn.moveUp();
				ptn.view();
			}
			else if (ch == 80)
			{
				ptn.moveDown();
				ptn.view();
			}

			if (ptn.location()){ cout << endl; menu(); }
		}
	}

	_getch();
}


int menu()
{
	system("cls");
	setlocale(LC_CTYPE, "Russian");
	cout << "1.Play " << endl << "2.Rules" << endl << "3. Get cell value by cell number" << endl << "4.Exit" << endl;
	int k;
	cin >> k;
	switch (k){
	case 1:return 1; break;
	case 2:return 2; break;
	case 3:return 3; break;
	case 4:return 4; break;
	default: cout << "Incorect input. Try again";
	}
}

#include <iomanip>
#include <conio.h>
#include <iostream>
#include <clocale>
#include <ctime>
#include <cstdlib>
#include "Field.h"

using namespace std;



int menu();


void main()
{
	int choice = menu();
	  setlocale (LC_CTYPE, "Russian");
		  if(choice == 2){cout<<"Данный раздел находится в разработке";};
		  if(choice == 3){return;}
	  if (choice == 1)
	  {
     Field ptn;
	 ptn.rnd();
	 ptn.view();
	
	 
	 char act;
    int ch;
    while (1)
    {
        act=_getch();
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
        
		if(ptn.location()){cout<<endl;menu();}
    }
	  }

	 _getch();
}


int menu()
{
	system ("cls");
	setlocale (LC_CTYPE, "Russian");
	cout<<"1.Play "<<endl<<"2.Rules"<<endl<<"3.Exit"<<endl;
	int k;
	cin>>k;
	switch (k){
		case 1:return 1;break;
		case 2:return 2;break;
		case 3:return 3;break;
		default : cout<<"Выберите правильно";
	}
}
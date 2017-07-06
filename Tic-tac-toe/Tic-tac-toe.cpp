// Tic-tac-toe.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
using namespace std;

int main()
{
	GameLogic gamelogic;
	gamelogic.DrawField(); //Initialization field
	gamelogic.SelectSide();
	gamelogic.ViewField();
	while (true) {
		gamelogic.Move();
		gamelogic.ViewField();

		if (gamelogic.Win() == 1) {
			system("cls");
			cout << " Your opponent win";
			break;
		}
		if (gamelogic.Win() == -1) {
			system("cls");
			cout << " You win";
			break;
		}
	}
	system("pause");
    return 0;
}


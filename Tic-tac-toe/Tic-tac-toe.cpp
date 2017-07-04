// Tic-tac-toe.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
using namespace std;

int main()
{
	GameLogic gamelogic;
	int x, y; 
	gamelogic.DrawField(); //Initialization field
	gamelogic.SelectSide();
	gamelogic.ViewField();
	while (true) {
		gamelogic.Move();
		gamelogic.ViewField();
	}
    return 0;
}


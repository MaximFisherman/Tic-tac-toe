// Tic-tac-toe.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
using namespace std;

int main()
{
	GameLogic gamelogic;
	int x, y; 

	gamelogic.DrawField();
	gamelogic.ViewField();
	cin >> x >> y;
	gamelogic.Move(x,y);
	gamelogic.ViewField();
	system("pause");
    return 0;
}


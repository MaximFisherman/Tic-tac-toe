// Tic-tac-toe.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main()
{
	GameLogic gamelogic;
	gamelogic.DrawField();
	gamelogic.ViewField();
	system("pause");
    return 0;
}


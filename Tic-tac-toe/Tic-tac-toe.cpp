// Tic-tac-toe.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
using namespace std;

int main()
{
	GameLogic gamelogic;
	int x, y; 
	gamelogic.DrawField(); //Initialization field
	gamelogic.SelectSide();
	while (true) {
		gamelogic.ViewField();
		gamelogic.Move();
	}
    return 0;
}


// Tic-tac-toe.cpp: ���������� ����� ����� ��� ����������� ����������.
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


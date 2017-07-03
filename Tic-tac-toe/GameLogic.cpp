#include "stdafx.h"
#include "GlobalVariables.h"

using namespace GlobalVaribles;
using namespace std;

void GameLogic::SelectSide() {
	char side;
	while (true) {
		cout << "Select side by typing O or X: ";
		cin >> side;

		if (side == 'X') {
			GlobalVaribles::selectedSideUser = 'X';
			GlobalVaribles::selectedSideComputer = 'O';
			USER_MOVE = true;
			break;
		}
		else {
			cout << "Wrong inputing";
		}

		if (side == 'O') {
			GlobalVaribles::selectedSideUser = 'O';
			GlobalVaribles::selectedSideComputer = 'X';
			USER_MOVE = false;
			break;
		}
		else {
			cout << "Wrong inputing";
		}
	}
};

void GameLogic::DrawField() {
	for (int i = 0; i < SIZE_FIELD; i++)
		for (int j = 0; j < SIZE_FIELD; j++)
			GlobalVaribles::Field[i][j] = ' ';
};

void GameLogic::ViewField() {
	for (int i = 0; i < SIZE_FIELD; i++) {
		for (int j = 0; j < SIZE_FIELD; j++) {
			cout <<"|"<< GlobalVaribles::Field[i][j]<<"|";
		}
		cout << endl;
	}
};

void GameLogic::Move() {
	int x, y;
	if (USER_MOVE) {
		cout << "Please input x and y coordinate: " << endl;
		cin >> x >> y;
		if (x != 0 && y != 0 && !(x > 3) && !(y > 3)&&!(GlobalVaribles::Field[x - 1][y - 1]=='X')&& !(GlobalVaribles::Field[x - 1][y - 1] == 'O')) {
			GlobalVaribles::Field[x-1][y-1] = 'X';
			USER_MOVE = false;
		}else {
			system("cls");
			cout << "Wrong input"<<endl;
		}
	}
}

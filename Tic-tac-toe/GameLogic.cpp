#include "stdafx.h"
#include "GlobalVariables.h"

using namespace GlobalVaribles;
using namespace std;

void GameLogic::DrawField() {
	for (int i = 0; i < SIZE_FIELD; i++)
		for (int j = 0; j < SIZE_FIELD; j++)
			GlobalVaribles::Field[i][j] = ' ';
};

void GameLogic::ViewField() {
	for (int i = 0; i < SIZE_FIELD; i++) {
		for (int j = 0; j < SIZE_FIELD; j++) {
			cout << GlobalVaribles::Field[i][j]<<"|";
		}
		cout << endl;
	}
};

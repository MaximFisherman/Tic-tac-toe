#include "stdafx.h"
#include "GlobalVariables.h"

using namespace GlobalVaribles;
using namespace std;

GameLogic::GameLogic() {
	board.reserve(SIZE_FIELD*SIZE_FIELD);
	for (int i = 0; i < SIZE_FIELD*SIZE_FIELD; i++) {
		board.push_back(0);
	}
};

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

	for (int i = 0; i < board.size(); i++) {
		board[i] = 0;
	}
};

void GameLogic::ConvertToField() {
	int k = 0;
	for (int i = 0; i < SIZE_FIELD; i++) {
		for (int j = 0; j < SIZE_FIELD; j++) {
			if(board[k]==1)
				GlobalVaribles::Field[i][j] = GlobalVaribles::selectedSideComputer;
			if (board[k] == -1)
				GlobalVaribles::Field[i][j] = GlobalVaribles::selectedSideUser;
			if (board[k] == 0)
				GlobalVaribles::Field[i][j] = ' ';
			k++;
			//cout << k << endl;
		}
	}
};

void GameLogic::ViewField() {
	ConvertToField();
	for (int i = 0; i < SIZE_FIELD; i++) {
		for (int j = 0; j < SIZE_FIELD; j++) {
			cout <<"|"<< GlobalVaribles::Field[i][j]<<"|";
		}
		cout << endl;
	}
};

void GameLogic::Move() {
	int x;
	
	//Move user
	if (USER_MOVE) {
		cout << "Please input place move 1..9: " << endl;
		cin >> x;
		x -= 1;

		if (!(x < 0) && !(board[x] == -1) && !(board[x] == 1)) {
			USER_MOVE = false;
			board[x] = -1;
			for (int i = 0; i < SIZE_FIELD * SIZE_FIELD; i++)
				cout << board[i] << " ";
			cout << endl;
		}else {
			system("cls");
			cout << "Wrong input"<<endl;
		}
	}

	//Move computer
	if (!USER_MOVE) {
		cout << "Move computer"<<endl;
		/*for (int i = 0; i < SIZE_FIELD * SIZE_FIELD; i++)
			cout << board[i] << " ";
		cout<<endl;*/
		//board = ConvertBoard(board);
	/*	for (int i = 0; i < SIZE_FIELD * SIZE_FIELD; i++)
			cout << board[i] << " ";
		cout << endl;*/

		move = -1;
		int score = -2;
		int i;
		for (i = 0; i < 9; ++i) {
			if (board[i] == 0) {
				board[i] = 1;
				int tempScore = -MinMaxAlhoritm(board, -1);
				board[i] = 0;
				if (tempScore > score) {
					score = tempScore;
					move = i;
				}
			}
		}
		//returns a score based on minimax tree at a given node.
		board[move] = 1;
		USER_MOVE = true;
	}
}


int GameLogic::Win() {
	//determines if a player has won, returns 0 otherwise.
	int wins[8][3] = { { 0,1,2 },{ 3,4,5 },{ 6,7,8 },{ 0,3,6 },{ 1,4,7 },{ 2,5,8 },{ 0,4,8 },{ 2,4,6 } };
	int countWinsUser = 0; 
	int countWinsComputer = 0;
		for (int i = 0; i < 8; i++) {
			countWinsComputer = 0;
			countWinsUser = 0;
			for (int j = 0; j < 3; j++) {
				if (board[wins[i][j]] == 1)
					countWinsComputer++;
				if (countWinsComputer == 3) {
					return 1;
				}

				if (board[wins[i][j]] == -1)
					countWinsUser++;
				if (countWinsUser == 3) {
					return -1;
				}
		}
	}
	return 0;
};

int GameLogic::MinMaxAlhoritm(vector<int> board, int player) {

	move = -1;
	int score = -2;//Losing moves are preferred to no move
	int i;
	for (i = 0; i < SIZE_FIELD * SIZE_FIELD; ++i) {//For all moves,
		if (board[i] == 0) {//If legal,
			board[i] = player;//Try the move
			int thisScore = MinMaxAlhoritm(board, player*-1);
			if (thisScore > score) {
				score = thisScore;
				move = i;
			}//Pick the one that's worst for the opponent
			board[i] = 0;//Reset board after try
		}
	}
	if (move == -1) return 0;
	return score;
};
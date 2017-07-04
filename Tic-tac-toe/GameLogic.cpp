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

	//Move user
	if (USER_MOVE) {
		cout << "Please input x and y coordinate: " << endl;
		cin >> x >> y;
		if (x != 0 && y != 0 && !(x > 3) && !(y > 3)&&!(GlobalVaribles::Field[x - 1][y - 1]=='X')&& !(GlobalVaribles::Field[x - 1][y - 1] == 'O')) {
			GlobalVaribles::Field[x-1][y-1] = GlobalVaribles::selectedSideUser;
			USER_MOVE = false;
		}else {
			system("cls");
			cout << "Wrong input"<<endl;
		}
	}

	//Move computer
	if (!USER_MOVE) {
		board = ConvertBoard(board);
		int move = -1;
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
	}
}

int GameLogic::Win(const int board[9]) {
	//determines if a player has won, returns 0 otherwise.
	unsigned wins[8][3] = { { 0,1,2 },{ 3,4,5 },{ 6,7,8 },{ 0,3,6 },{ 1,4,7 },{ 2,5,8 },{ 0,4,8 },{ 2,4,6 } };
	int i;
	for (i = 0; i < 8; ++i) {
		if (board[wins[i][0]] != 0 &&
			board[wins[i][0]] == board[wins[i][1]] &&
			board[wins[i][0]] == board[wins[i][2]])
			return board[wins[i][2]];
	}
	return 0;
};
//Correcting
vector<int> GameLogic::ConvertBoard(vector<int> board){
	for (int i = 0; i < SIZE_FIELD; i++) {
		for (int j = 0; j < SIZE_FIELD; j++) {
			if (GlobalVaribles::Field[i][j] == GlobalVaribles::selectedSideComputer)
				board[i][j] = 1;
			if (GlobalVaribles::Field[i][j] == GlobalVaribles::selectedSideUser)
				board[i][j] = -1;
		}
	}
	return board;
};

int GameLogic::MinMaxAlhoritm(int board[9], int player) {

	//How is the position like for player (their turn) on board?
	int winner = Win(board);
	if (winner != 0) return winner*player;

	move = -1;
	int score = -2;//Losing moves are preferred to no move
	int i;
	for (i = 0; i < 9; ++i) {//For all moves,
		if (board[i] == 0) {//If legal,
			board[i] = player;//Try the move
			int thisScore = -MinMaxAlhoritm(board, player*-1);
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

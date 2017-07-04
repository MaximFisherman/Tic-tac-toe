#pragma once
#ifndef __GAMELOGIC_H__
#define __GAMELOGIC_H__
#include "stdafx.h"

using std::vector;

class GameLogic 
{
protected:
	vector<int> board{ 0,0,0,0,0,0,0,0,0 };
	int move = 0;
public:
	void SelectSide();
	void DrawField();
	void ViewField();
	void Move(); 

	//MinMax alhoritm
	int Win(vector<int> board);
	vector<int> ConvertBoard(vector<int> board);
	void ConvertToField(int);
	int MinMaxAlhoritm(vector<int> board, int player);
};
#endif
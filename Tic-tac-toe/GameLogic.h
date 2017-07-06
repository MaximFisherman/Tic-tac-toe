#pragma once
#ifndef __GAMELOGIC_H__
#define __GAMELOGIC_H__
#include "stdafx.h"

using namespace std;

class GameLogic 
{
protected:
	std::vector<int> board;
	int move = 0;
public:
	GameLogic();
	void SelectSide();
	void DrawField();
	void ViewField();
	void Move(); 
	void ConvertToField();

	//Ñondition Win 
	int Win();
	
	//MinMax alhoritm
	int MinMaxAlhoritm(vector<int> board, int player);
};
#endif
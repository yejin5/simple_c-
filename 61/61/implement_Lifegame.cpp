/****************************************/
/*  국민대학교 전자정보통신대학           */
/*  컴퓨터공학부 20143079 오예진         */
/*  61번. 라이프게임                    */
/***************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "MyLifeGame.h"

using namespace std;

void main()
{
	ifstream instream;
	int cases;

	instream.open("input.txt");
	if (instream.fail())
	{
		cerr << "input file opening is failed.\n";
		exit(1);
	}

	instream >> cases;
	MyLifeGame lifegame;

	for (int i = 0; i < cases; i++)
	{
		int rows, cols;
		int time;
		char initBoard[max_board_size+2][max_board_size+2];

		instream >> rows >> cols;
		instream >> time;

		for (int j = 0; j < rows + 2; j++)
		{
			for (int k = 0; k < cols + 2; k++)
				initBoard[j][k] = -1;
		}

		for (int j = 1; j < rows+1; j++)
		{
			for (int k = 1; k < cols+1; k++)
				instream >> initBoard[j][k];
		}
		lifegame.setBoard(rows, cols, initBoard);
		lifegame.runLifeGame(time);

	}
	instream.close();
}
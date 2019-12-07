/****************************************/
/*  ���δ��б� ����������Ŵ���           */
/*  ��ǻ�Ͱ��к� 20143079 ������         */
/*  61��. ����������                    */
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
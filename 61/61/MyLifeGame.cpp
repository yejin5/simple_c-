
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "MyLifeGame.h"

//constructors
MyLifeGame::MyLifeGame()
{
}

MyLifeGame::MyLifeGame(int rSize, int cSize, char gameCells[][max_board_size + 2])
{
	setBoard(rSize, cSize, gameCells);
}

//mutator function
void MyLifeGame::setBoard(int rSize, int cSize, char gameCells[][max_board_size + 2])
{
	using namespace std;

	rowSize = rSize;
	colSize = cSize;

	for (int i = 0; i < 102; i++)
	{
		for (int j = 0; j < 102; j++)
		{
			board[i][j] = NOTHING;
			copy_board[i][j] = NOTHING;
		}
	}

	for (int i = 1; i < rowSize+1; i++)
	{
		for (int j = 1; j < colSize+1; j++)
		{
			if (gameCells[i][j] == 'X' || gameCells[i][j] == 'x')
			{
				board[i][j] = DEAD;
				copy_board[i][j] = DEAD;
			}
			else if (gameCells[i][j] == 'O' || gameCells[i][j] == 'o')
			{
				board[i][j] = ALIVE;
				copy_board[i][j] = ALIVE;
			}
		}
	}
}

//utility functions
void MyLifeGame::runLifeGame(int time)
{
	int live_cells=0; //살아있는 셀 갯수

	for (int i = 0; i<time; i++)
	{
		for (int a = 1; a<rowSize+1; a++) //라이프 게임 판별하기
		{
			int count;
			int count2;

			for (int b = 1; b<colSize+1; b++)
			{
				count = count2 = 0;

				if (board[a - 1][b - 1] == ALIVE && board[a - 1][b - 1] != NOTHING)
					count += 1;
				if (board[a - 1][b] == ALIVE && board[a - 1][b] != NOTHING)
					count += 1;
				if (board[a - 1][b + 1] == ALIVE && board[a - 1][b + 1] != NOTHING)
					count += 1;
				if (board[a][b - 1] == ALIVE && board[a][b - 1] != NOTHING)
					count += 1;
				if (board[a][b + 1] == ALIVE && board[a][b + 1] != NOTHING)
					count += 1;
				if (board[a + 1][b - 1] == ALIVE && board[a + 1][b - 1] != NOTHING)
					count += 1;
				if (board[a + 1][b] == ALIVE && board[a + 1][b] != NOTHING)
					count += 1;
				if (board[a + 1][b + 1] == ALIVE && board[a + 1][b + 1] != NOTHING)
					count += 1;

				if (board[a][b] == ALIVE)
					count2 += 1;

				if (count == 1 || count == 0)
					copy_board[a][b] = DEAD;
				else if ((count2 == 1 && count == 2) || (count2 == 1 && count == 3))
					copy_board[a][b] = ALIVE;
				else if (count2 == 0 && count == 3)
					copy_board[a][b] = ALIVE;
				else if (count >= 4)
					copy_board[a][b] = DEAD;
			}
		}
		for (int c = 1; c<rowSize+1; c++)
		{
			for (int d = 1; d<colSize+1; d++)
				board[c][d] = copy_board[c][d];
		}
	}

	for (int a = 1; a<rowSize+1; a++)
	{
		for (int b = 1; b<colSize+1; b++)
		{
			if (board[a][b] == ALIVE) 
				live_cells++;
		}
	}
	
	std::cout << live_cells << std::endl;

	for (int a = 1; a<rowSize+1; a++)
	{
		for (int b = 1; b<colSize+1; b++)
		{
			if (board[a][b] == ALIVE)
				std::cout << 'O';
			else if (board[a][b] == DEAD)
				std::cout << 'X';
		}
		std::cout << std::endl;
	}
}
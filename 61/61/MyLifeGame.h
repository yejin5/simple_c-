
#ifndef _MY_LIFE_GAME_H_
#define _MY_LIFE_GAME_H_

const int max_board_size = 100;

class MyLifeGame
{
public:
	typedef enum BoardStatus{ALIVE, DEAD, NOTHING};
	//constructors
	MyLifeGame ();
	MyLifeGame (int rSize, int cSize, char gameCells[][max_board_size+2]);

	//mutator function
	void setBoard (int rSize, int cSize, char gameCells[][max_board_size+2]);

	//utility functions
	void runLifeGame(int time);
private:

	BoardStatus board[max_board_size+2][max_board_size+2];
	BoardStatus copy_board[max_board_size+2][max_board_size+2];
	int rowSize, colSize;
	int numAliveCells;

	void getNextGeneration ();

};

#endif
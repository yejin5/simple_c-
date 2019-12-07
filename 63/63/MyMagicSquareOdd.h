
#ifndef _MY_MAGIC_SQUARE_ODD_H_
#define _MY_MAGIC_SQUARE_ODD_H_

const int max_size = 49;

class MyMagicSquareOdd
{
public:
	//constructors
	MyMagicSquareOdd();
	MyMagicSquareOdd(int n);

	//utility functions
	void printSquare() const;

private:
	int square[max_size][max_size];
	int size;
	void makeSquare(); //홀수 마방진을 만드는 함수
	bool checkSquare(); //만들어진 행렬이 홀수 마방진인지를 검사

};

#endif

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
	void makeSquare(); //Ȧ�� �������� ����� �Լ�
	bool checkSquare(); //������� ����� Ȧ�� ������������ �˻�

};

#endif
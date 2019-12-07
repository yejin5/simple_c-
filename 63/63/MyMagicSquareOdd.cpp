
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "MyMagicSquareOdd.h"

//constructors
MyMagicSquareOdd::MyMagicSquareOdd() :size(0)
{}

MyMagicSquareOdd::MyMagicSquareOdd(int n) : size(n)
{
	if (n % 2 == 0 || n<1 || n>max_size)
		exit(1);

	for (int i = 0; i<size; i++)
	{
		for (int j = 0; j<size; j++)
			square[i][j] = 0;
	}

	makeSquare();
}

//utility functions
void MyMagicSquareOdd::printSquare()const
{
	using namespace std;

	for (int i = 0; i<size; i++)
	{
		for (int j = 0; j<size; j++)
			cout << square[i][j] << " ";
		cout << endl;
	}
}

void MyMagicSquareOdd::makeSquare()
{
	int start_one = 1;
	int start_zero = 0;

	int copy_size = size;

	int num = copy_size / 2;

	square[start_zero][num] = start_one;

	for (int i = 1; i<copy_size*copy_size; i++)
	{
		start_zero -= 1;
		num += 1;

		if (start_zero<0 && num == copy_size)
		{
			start_zero += 2;
			num -= 1;
		}

		else if (start_zero<0)
			start_zero = copy_size - 1;
		
		else if (num == copy_size)
			num = 0;

		else if (square[start_zero][num] != 0)
		{
			start_zero += 2;
			num -= 1;
		}

		start_one += 1;
		square[start_zero][num] = start_one;

	}
}

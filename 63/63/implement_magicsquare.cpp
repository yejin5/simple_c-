
/****************************************/
/*  ���δ��б� ����������Ŵ���           */
/*  ��ǻ�Ͱ��к� 20143079 ������         */
/*  63��. Ȧ�� ������                   */
/***************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "MyMagicSquareOdd.h"

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

	for (int i = 0; i < cases; i++)
	{
		int size;

		instream >> size;

		MyMagicSquareOdd oddSquare(size);
		oddSquare.printSquare();
	}

	instream.close();
}
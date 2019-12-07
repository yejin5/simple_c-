
/****************************************/
/*  ���δ��б� ����������Ŵ���           */
/*  ��ǻ�Ͱ��к� 20143079 ������         */
/*  64��. ¦�� ������                   */
/***************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "MyMagicSquareEven.h"

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

		MyMagicSquareEven evenSquare(instream);
		evenSquare.make_MyMagicSquareEven();
		evenSquare.print_MyMagicSquareEven();
	}
	instream.close();
}

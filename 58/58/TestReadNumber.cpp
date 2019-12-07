
/****************************************/
/*  ���δ��б� ����������Ŵ���           */
/*  ��ǻ�Ͱ��к� 20143079 ������         */
/*  58��. ���� �б�                     */
/***************************************/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "ReadNumber.h"

using namespace std;

void main()
{
	ifstream instream;
	instream.open("input.txt");
	if (instream.fail())
	{
		cerr << "input file opening is failed.\n";
		exit(1);
	}

	int nocase;
	instream >> nocase;

	ReadNumber numReading;

	for (int i = 0; i < nocase; i++)
	{
		unsigned int R_num;

		instream >> R_num;

		numReading.setNumber(R_num);
		numReading.read();
	}

	instream.close();
}
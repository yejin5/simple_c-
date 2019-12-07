
/****************************************/
/*  국민대학교 전자정보통신대학           */
/*  컴퓨터공학부 20143079 오예진         */
/*  58번. 숫자 읽기                     */
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
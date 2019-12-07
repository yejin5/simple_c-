
/****************************************/
/*  ���δ��б� ����������Ŵ���           */
/*  ��ǻ�Ͱ��к� 20143079 ������         */
/*  70��. ������ �ð�                   */
/***************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "MyDigitalClock.h"

using namespace std;

const int max_length = 8;

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
		char clock[max_length];
		int lap;

		instream >> clock >> lap;

		MyDigitalClock digitalClock(clock);

		for (int j = 0; j < abs(lap); j++)

			if (lap > 0)
				digitalClock++;
			else
				--digitalClock;

		cout << digitalClock;

	}
	instream.close();
}
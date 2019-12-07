/****************************************/
/*  국민대학교 전자정보통신대학           */
/*  컴퓨터공학부 20143079 오예진         */
/*  50번. 숫자의 진법 변환               */
/***************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

void main()
{
	ifstream instream;

	int cases;
	int i, j, k, n;

	int original_sys, new_sys; //진법

	char data[100];
	char *stop;
	int cen;
	char compute[100];

	instream.open("input.txt");
	if (instream.fail())
	{
		cerr << "input file opening failed.\n";
		exit(1);
	}

	instream >> cases;
	for (i = 0; i < cases; i++)
	{
		instream >> original_sys >> data >> new_sys;

		cen = strtol(data, &stop, original_sys);
		_itoa_s(cen, compute, new_sys);
		
		cout << compute << endl;
	}
	instream.close();
}
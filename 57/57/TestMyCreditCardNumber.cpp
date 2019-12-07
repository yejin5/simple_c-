
/****************************************/
/*  국민대학교 전자정보통신대학           */
/*  컴퓨터공학부 20143079 오예진         */
/*  57번. 신용카드번호                   */
/***************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "MyCreditCardNumber.h"

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
		char number[max_length + 1];
		instream >> number;

		MyCreditCardNumber cardNumber(number);
		if (cardNumber.isCorrectNumber())
			cout << "1" << endl;
		else
			cout << "0" << endl;
	}

	instream.close();
}

/****************************************/
/*  국민대학교 전자정보통신대학           */
/*  컴퓨터공학부 20143079 오예진         */
/*  82. 유리수                          */
/***************************************/

#include<fstream>
#include<cstdlib>
#include"MyRational.h"

#define MAX_SIZE 100

using namespace std;

void testSimpleCase();
void testDataFromFile();
void sortDatas(myRational rationals[], int n);
void swap(myRational& r1, myRational& r2);

void main()
{
	testSimpleCase();
	testDataFromFile();
}

void testSimpleCase()
{
	myRational frac1(2), frac2(3, 2), frac3(6, 4), frac4(12, 8), frac5, frac6, frac7;

	cout << frac1 << " " << frac2 << " " << frac3 << " " << frac4 << " " << frac5 << endl;
	cout << frac1.getNumerator() << " " << frac1.getDenominator() << endl;

	cout << frac1*frac2 << " " << frac1 + frac3 << " " << frac2 - frac1 << " " << frac3 / frac2 << endl;

	cout << ((frac1<frac2) ? 1 : 0) << " "
		<< ((frac1 <= frac2) ? 1 : 0) << " "
		<< ((frac1>frac2) ? 1 : 0) << " "
		<< ((frac1 >= frac2) ? 1 : 0) << " "
		<< ((frac1 == frac2) ? 1 : 0) << " "
		<< ((frac1 != frac2) ? 1 : 0) << " "
		<< ((frac2<frac3) ? 1 : 0) << " "
		<< ((frac2 <= frac3) ? 1 : 0) << " "
		<< ((frac2>frac3) ? 1 : 0) << " "
		<< ((frac2 >= frac3) ? 1 : 0) << " "
		<< ((frac2 == frac3) ? 1 : 0) << " "
		<< ((frac2 != frac3) ? 1 : 0) << endl;

	cout << (frac6 = frac3) << " ";
	cout << (frac6 += frac3) << " ";
	cout << (frac6 -= frac3) << " ";
	cout << (frac6 *= frac3) << " ";
	cout << (frac6 /= frac3) << endl;

	cout << -frac6 << endl;

	frac6 = (++frac4) + 2;
	frac7 = 2 + (frac4++);
	cout << frac4 << " " << frac6 << " " << frac7 << endl;

	frac6 = (--frac4) - 2;
	frac7 = 2 - (frac4--);
	cout << frac4 << " " << frac6 << " " << frac7 << endl;

	cout << 2 * frac3 << " " << frac3 * 2 << " " << 2 / frac3 << " " << frac3 / 2 << endl;
}

void testDataFromFile()
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
		int j;
		int numData;
		myRational rationals[MAX_SIZE];

		instream >> numData;

		for (j = 0; j < numData; j++)
			instream >> rationals[j];

		sortDatas(rationals, numData);
		for (j = 0; j < numData; j++)
			cout << rationals[j] << " ";
		cout << endl;
	}

	instream.close();
}

void sortDatas(myRational rationals[], int n)
{
	for (int i = n - 2; i >= 0; i--)
		for (int j = 0; j <= i; j++)
			if (rationals[j]>rationals[j + 1])
				swap(rationals[j], rationals[j + 1]);
}

void swap(myRational& num1, myRational& num2)
{
	myRational temp;

	temp = num1;
	num1 = num2;
	num2 = temp;
}
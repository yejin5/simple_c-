
/****************************************/
/*  국민대학교 전자정보통신대학           */
/*  컴퓨터공학부 20143079 오예진         */
/*  74. date class(4)                  */
/***************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "myDate.h"

using namespace std;

const int max_size = 100;

void testSimpleCase();
void testDataFromFile();
const myDate& getMinDate(const myDate dates[], int n);
const myDate& getMaxDate(const myDate dates[], int n);
void sortDates(myDate dates[], int n);
void swap(myDate &d1, myDate &d2);

void main()
{
	testSimpleCase();
	testDataFromFile();
}

void testSimpleCase()
{
	myDate d1, d2(99999, 12, 31), d3(2008, 2, 20);
	myDate d4, d5, d6, d7, d8, d9(d3);

	cout << d1 << endl;
	cout << d2 << endl;
	cout << d3 << endl;
	cout << d9 << endl;
	cout << d3 - d1 << endl;

	d4 = d5 = d6 = d7 = d8 = d9;
	
	cout << ++d7 + 365 << " " << d7 << endl;
	cout << d7++ + 365 << " " << d7 << endl;

	cout << --d7 - 365 << " " << d7 << endl;
	cout << d7-- - 365 << " " << d7 << endl;

	cout << -365 + d7 << " " << d7 << endl;

	d4.setDate(2999, 12, 31);
	d5.setDate(2000, 1, 1);
	d6.setDate(3000, 1, 1);

	d6 -= d5 - d4;
	cout << d6 << endl;

	cout << (d6 == d8) << " " << (d6 != d8) << endl;
	cout << (d7 == d8) << " " << (d7 != d8) << endl;

	cout << (d6 >= d8) << " " << (d6 > d8) << endl;
	cout << (d6 <= d8) << " " << (d6 < d8) << endl;
	cout << (d7 >= d8) << " " << (d7 > d8) << endl;
	cout << (d7 <= d8) << " " << (d7 < d8) << endl;

}

void testDateFromFile()
{
	ifstream instream;
	int cases;

	instream.open("input.txt");
	if (instream.fail())
	{
		cerr << "input file opening faile.\n";
		exit(1);
	}

	instream >> cases;

	for (int i = 0; i < cases; i++)
	{
		int j;
		int num_data;

		myDate dates[max_size], minDate, maxDate;

		instream >> num_data;

		for (j = 0; j < num_data; j++)
			instream >> dates[j];

		minDate = getMinDate(dates, num_data);
		maxDate = getMaxDate(dates, num_data);

		cout << minDate << " " << maxDate << " " << maxDate - minDate << endl;

		sortDates(dates, num_data);

		for (j = 0; j < num_data; j++)
			cout << dates[j] << " ";
		cout << endl;

	}

	instream.close();
}

//날짜 중에서 가장 이른 날짜를 계산한다
const myDate& getMinDate(const myDate dates[], int n)
{
	int min = 0;
	
	for (int i = 0; i < n; i++)
	{
		if (dates[min] > dates[i])
			min = i;
	}
	return dates[min];
}

//날짜 중에서 가장 늦은 날짜를 계산함
const myDate& getMaxDate(const myDate dates[], int n)
{
	int max = 0;

	for (int i = 1; i < n; i++)
	{
		if (dates[max] < dates[i])
			max = i;
	}

	return dates[max];
}

//날짜를 오름차순으로 정리한다
void sortDates(myDate dates[], int n)
{
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			if (dates[j] > dates[j + 1])
				swap(dates[j], dates[j + 1]);
		}
	}
}

//두 날짜를 서로 바꿈
void swap(myDate &d1, myDate &d2)
{
	myDate temp;

	temp = d1;
	d1 = d2;
	d2 = temp;
}
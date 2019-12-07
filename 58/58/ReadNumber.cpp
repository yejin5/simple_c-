
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "ReadNumber.h"

using namespace std;

char ReadNumber::digits[10][MAX_Length] = {
	"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
char ReadNumber::teens[20][MAX_Length] = {
	"", "", "", "", "", "", "", "", "", "",
	"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
char ReadNumber::ties[10][MAX_Length] = {
	"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
char ReadNumber::units[4][MAX_Length] = {
	"Hundred", "Thousand", "Million", "Billion" };


ReadNumber::ReadNumber() :number(1)
{}

ReadNumber::ReadNumber(unsigned int num) : number(num)
{}

void ReadNumber::setNumber(unsigned int num)
{
	number = num;
}

void ReadNumber::read() const
{

	int compute_num[4];

	unsigned int num_2 = number;

	for (int i = 3; i >= 0; i--)
	{
		compute_num[i] = num_2 % 1000;
		num_2 = num_2 / 1000;
	}

	if (compute_num[0] > 0)
	{
		cout << digits[compute_num[0]] << "_" << units[3];

		if (number % 1000000000 != 0) 
			cout << "_";
	}

	if (compute_num[1] > 0)
	{

		if (compute_num[1] >= 100)
		{
			cout << digits[compute_num[1] / 100] << "_" << units[0];

			if (compute_num[1] % 100 != 0) 
				cout << "_";
		}

		if (compute_num[1] % 100 >= 20)
		{
			cout << ties[(compute_num[1] % 100) / 10] << "_";

			if (compute_num[1] % 10 > 0) 
				cout << digits[compute_num[1] % 10] << "_";
		}

		else if (compute_num[1] % 100 >= 10) 
			cout << teens[compute_num[1] % 100] << "_";

		else 
			cout << digits[compute_num[1] % 10] << "_";

		cout << units[2];

		if (number % 1000000 != 0) 
			cout << "_";
	}

	if (compute_num[2] > 0)
	{

		if (compute_num[2] >= 100)
		{

			cout << digits[compute_num[2] / 100] << "_" << units[0];
			if (compute_num[2] % 100 != 0) 
				cout << "_";

		}

		if (compute_num[2] % 100 >= 20)
		{
			cout << ties[(compute_num[2] % 100) / 10] << "_";

			if (compute_num[2] % 10 > 0) 
				cout << digits[compute_num[2] % 10] << "_";

		}
		else if (compute_num[2] % 100 >= 10) 
			cout << teens[compute_num[2] % 100] << "_";

		else 
			cout << digits[compute_num[2] % 10] << "_";

		cout << units[1];

		if (number % 1000 != 0) 
			cout << "_";
	}

	if (compute_num[3] > 0)
	{

		if (compute_num[3] >= 100)
		{

			cout << digits[compute_num[3] / 100] << "_" << units[0];

			if (number % 100 != 0) 
				cout << "_";

		}

		if (compute_num[3] % 100 >= 20)
		{
			cout << ties[(compute_num[3] % 100) / 10];
			if (number % 10 != 0) 
				cout << "_" << digits[compute_num[3] % 10];

		}

		else if (compute_num[3] % 100 >= 10) 
			cout << teens[compute_num[3] % 100];

		else 
			cout << digits[compute_num[3] % 10];

	}
	cout << endl;
}
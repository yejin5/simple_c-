
#include <cstdlib>
#include <iostream>
#include "myDate.h"

using namespace std;

myDate::myDate(int year, int month, int day) :year(year), month(month), day(day)
{

}

int myDate::getDayOfMonth()const
{
	return day;
}

int myDate::getMonth()const
{
	return month;
}

int myDate::getYear() const
{
	return year;
}

void myDate::setDayOfMonth(int day)
{
	this->day = day;
}

void myDate::setMonth(int month)
{
	this->month = month;
}

void myDate::setYear(int year)
{
	this->year = year;
}

void myDate::setDate(int year, int month, int day)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

//윤년계산
bool myDate::isLeapYear() const
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 4 == 0 && year % 400 == 0))
		return 1;

	else
		return 0;
}

//요일을 0~6으로 출력
int myDate::getDayOfWeek() const
{
	int sum = 0;
	int nu1 = 0, nu2 = 0;

	for (int j = 1582; j < year; j++)
	{
		if ((j % 4 == 0 && j % 100 != 0) || (j % 4 == 0 && j % 400 == 0))//윤년
			nu1++;

		else
			nu2++;
		sum = nu1 * 366 + nu2 * 365;
	}


	if ((year % 4 == 0 && year % 100 != 0) || (year % 4 == 0 && year % 400 == 0))//윤년
	{
		if (month == 2)
			sum += 31;
		else if (month == 3)
			sum += 60;
		else if (month == 4)
			sum += 91;
		else if (month == 5)
			sum += 121;
		else if (month == 6)
			sum += 152;
		else if (month == 7)
			sum += 182;
		else if (month == 8)
			sum += 213;
		else if (month == 9)
			sum += 244;
		else if (month == 10)
			sum += 274;
		else if (month == 11)
			sum += 305;
		else if (month == 12)
			sum += 335;
		//else if(month==12)
		//sum+=366;
	}

	else
	{
		if (month == 2)
			sum += 31;
		else if (month == 3)
			sum += 59;
		else if (month == 4)
			sum += 90;
		else if (month == 5)
			sum += 120;
		else if (month == 6)
			sum += 151;
		else if (month == 7)
			sum += 181;
		else if (month == 8)
			sum += 212;
		else if (month == 9)
			sum += 243;
		else if (month == 10)
			sum += 273;
		else if (month == 11)
			sum += 304;
		else if (month == 12)
			sum += 334;
		//else if(month==12)
		//sum+=365;
	}

	sum += day;


	int a = (sum % 7 + 5) - 1;

	if (a > 6)
		return a - 7;
	else
		return a;
}

int myDate::getDayOfYear() const
{
	int sum = 0;

	if ((year % 4 == 0 && year % 100 != 0) || (year % 4 == 0 && year % 400 == 0))//윤년
	{
		if (month == 2)
			sum += 31;
		else if (month == 3)
			sum += 60;
		else if (month == 4)
			sum += 91;
		else if (month == 5)
			sum += 121;
		else if (month == 6)
			sum += 152;
		else if (month == 7)
			sum += 182;
		else if (month == 8)
			sum += 213;
		else if (month == 9)
			sum += 244;
		else if (month == 10)
			sum += 274;
		else if (month == 11)
			sum += 305;
		else if (month == 12)
			sum += 335;
		//else if(month==12)
		//sum+=366;

		return sum + day;
	}

	else
	{
		if (month == 2)
			sum += 31;
		else if (month == 3)
			sum += 59;
		else if (month == 4)
			sum += 90;
		else if (month == 5)
			sum += 120;
		else if (month == 6)
			sum += 151;
		else if (month == 7)
			sum += 181;
		else if (month == 8)
			sum += 212;
		else if (month == 9)
			sum += 243;
		else if (month == 10)
			sum += 273;
		else if (month == 11)
			sum += 304;
		else if (month == 12)
			sum += 334;
		//else if(month==12)
		//sum+=365;

		return sum + day;
	}


}

//휴일 수 계산
int myDate::getNumHolidays() const
{
	int sum = 0;
	int nu1 = 0, nu2 = 0;

	int num_of_holiday = 11; //1월 휴일+신정 휴일 합한 개수로 시작

	if ((year % 4 == 0 && year % 100 != 0) || (year % 4 == 0 && year % 400 == 0))//윤년
	{
		if (month == 2)
			sum += 31;
		else if (month == 3)
			sum += 60;
		else if (month == 4)
			sum += 91;
		else if (month == 5)
			sum += 121;
		else if (month == 6)
			sum += 152;
		else if (month == 7)
			sum += 182;
		else if (month == 8)
			sum += 213;
		else if (month == 9)
			sum += 244;
		else if (month == 10)
			sum += 274;
		else if (month == 11)
			sum += 305;
		else if (month == 12)
			sum += 335;
		else if (month == 12)
			sum += 366;
	}

	else
	{
		if (month == 2)
			sum += 31;
		else if (month == 3)
			sum += 59;
		else if (month == 4)
			sum += 90;
		else if (month == 5)
			sum += 120;
		else if (month == 6)
			sum += 151;
		else if (month == 7)
			sum += 181;
		else if (month == 8)
			sum += 212;
		else if (month == 9)
			sum += 243;
		else if (month == 10)
			sum += 273;
		else if (month == 11)
			sum += 304;
		else if (month == 12)
			sum += 334;
		else if (month == 12)
			sum += 365;
	}

	int a = (sum % 7 + 5) - 1;

	if (a > 6)
		return a - 7;
	else
		return a;

}

int myDate::getNumSummerTimeDays() const
{
	int start_3 = 5, close_10 = 5;
	int num_of_start = 0, num_of_close = 0;
	
	int sum = 0;
	int nu1 = 0, nu2 = 0;

	for (int j = 1582; j < year; j++)
	{
		if ((j % 4 == 0 && j % 100 != 0) || (j % 4 == 0 && j % 400 == 0))//윤년
			nu1++;

		else
			nu2++;
		sum = nu1 * 366 + nu2 * 365;
	}
	sum %= 7;

	if ((year % 4 == 0 && year % 100 != 0) || (year % 4 == 0 && year % 400 == 0)) //윤년
	{
		start_3 += sum + 60;
		close_10 += sum + 274;
	}

	else
	{
		start_3 += sum + 59;
		close_10 += sum + 273;
	}

	for (int i = 0; i < 31; i++)
	{
		if ((start_3 + i) % 7 == 0)
			num_of_start = i;

		if ((close_10 + i) % 7 == 0)
			num_of_close = i;
	}

	num_of_start = 31 - num_of_start + 1;

	return 183 + num_of_start + (num_of_close - 1);
}

void myDate::printCalendarOfMonth() const
{
	int sum = 0;
	int nu1 = 0;
	int nu2 = 0;
	int a = 0;

	int i, j, k, m, n;

	cout << year << " " << month << endl; //달력의 위에 년도와 월 표현

	for (int j = 1582; j < year; j++)
	{
		if ((j % 4 == 0 && j % 100 != 0) || (j % 4 == 0 && j % 400 == 0))//윤년
			nu1++;
		else
			nu2++;

		sum = nu1 * 366 + nu2 * 365;
	}

	if ((year % 4 == 0 && year % 100 != 0) || (year % 4 == 0 && year % 400 == 0))//윤년
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (month == 1)
				sum += 0;
			else if (month == 3)
				sum += 60;
			else if (month == 5)
				sum += 121;
			else if (month == 7)
				sum += 182;
			else if (month == 8)
				sum += 213;
			else if (month == 10)
				sum += 274;
			else if (month == 12)
				sum += 335; //sum계산

			a = sum % 7 + 5;
			if (a > 6)
				a = a - 7;

			if (a != 0)
			{
				for (m = 0; m < a; m++)
					cout << '0' << " ";
			}

			for (k = 1; k < 32; k++)
			{
				cout << k;

				if ((k % 7 + a) % 7 != 0)
					cout << " ";
				else if ((k % 7 + a) % 7 == 0)
					cout << endl;
			}

			if (a == 0)
				cout << "0 0 0 0" << endl;
			else if (a == 1)
				cout << "0 0 0" << endl;
			else if (a == 2)
				cout << "0 0" << endl;
			else if (a == 3)
				cout << "0" << endl;
			else if (a == 5)
				cout << "0 0 0 0 0 0" << endl;
			else if (a == 6)
				cout << "0 0 0 0 0" << endl;


		}

		else if (month == 2)
		{
			sum += 31;

			a = sum % 7 + 5;
			if (a > 6)
				a = a - 7;

			if (a != 0)
			{
				for (m = 0; m < a; m++)
					cout << '0' << " ";
			}

			for (k = 1; k < 30; k++)
			{
				cout << k;

				if ((k % 7 + a) % 7 != 0)
					cout << " ";
				else if ((k % 7 + a) % 7 == 0)
					cout << endl;
			}
			if (a == 2)
				cout << "0 0 0 0" << endl;
			else if (a == 3)
				cout << "0 0 0" << endl;
			else if (a == 4)
				cout << "0 0" << endl;
			else if (a == 5)
				cout << "0" << endl;
			else if (a == 0)
				cout << "0 0 0 0 0 0" << endl;
			else if (a == 1)
				cout << "0 0 0 0 0" << endl;

		}

		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (month == 4)
				sum += 91;
			else if (month == 6)
				sum += 152;
			else if (month == 9)
				sum += 244;
			else if (month == 11)
				sum += 305;

			a = sum % 7 + 5;
			if (a > 6)
				a = a - 7;

			if (a != 0)
			{
				for (m = 0; m < a; m++)
					cout << '0' << " ";
			}

			for (k = 1; k < 31; k++)
			{
				cout << k;

				if ((k % 7 + a) % 7 != 0)
					cout << " ";
				else if ((k % 7 + a) % 7 == 0)
					cout << endl;
			}

			if (a == 1)
				cout << "0 0 0 0" << endl;
			else if (a == 2)
				cout << "0 0 0" << endl;
			else if (a == 3)
				cout << "0 0" << endl;
			else if (a == 4)
				cout << "0" << endl;
			else if (a == 6)
				cout << "0 0 0 0 0 0" << endl;
			else if (a == 0)
				cout << "0 0 0 0 0" << endl;

		}

	}

	else //윤년이 아니면
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (month == 1)
				sum += 0;
			else if (month == 3)
				sum += 59;
			else if (month == 5)
				sum += 120;
			else if (month == 7)
				sum += 181;
			else if (month == 8)
				sum += 212;
			else if (month == 10)
				sum += 273;
			else if (month == 12)
				sum += 334;

			a = sum % 7 + 5;
			if (a > 6)
				a = a - 7;

			if (a != 0)
			{
				for (m = 0; m < a; m++)
					cout << '0' << " ";
			}

			for (k = 1; k < 32; k++)
			{
				cout << k;

				if ((k % 7 + a) % 7 != 0)
					cout << " ";
				else if ((k % 7 + a) % 7 == 0)
					cout << endl;
			}

			if (a == 0)
				cout << "0 0 0 0" << endl;
			else if (a == 1)
				cout << "0 0 0" << endl;
			else if (a == 2)
				cout << "0 0" << endl;
			else if (a == 3)
				cout << "0" << endl;
			else if (a == 5)
				cout << "0 0 0 0 0 0" << endl;
			else if (a == 6)
				cout << "0 0 0 0 0" << endl;

		}

		else if (month == 2) //28일 까지
		{
			sum += 31;

			a = sum % 7 + 5;
			if (a > 6)
				a = a - 7;

			if (a != 0)
			{
				for (m = 0; m < a; m++)
					cout << '0' << " ";
			}

			for (k = 1; k < 29; k++)
			{
				cout << k;

				if ((k % 7 + a) % 7 != 0)
					cout << " ";
				else if ((k % 7 + a) % 7 == 0)
					cout << endl;
			}

			if (a == 3)
				cout << "0 0 0 0" << endl;
			else if (a == 4)
				cout << "0 0 0" << endl;
			else if (a == 5)
				cout << "0 0" << endl;
			else if (a == 6)
				cout << "0" << endl;
			else if (a == 1)
				cout << "0 0 0 0 0 0" << endl;
			else if (a == 2)
				cout << "0 0 0 0 0" << endl;


		}

		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (month == 4)
				sum += 90;
			else if (month == 6)
				sum += 151;
			else if (month == 9)
				sum += 243;
			else if (month == 11)
				sum += 304;

			a = sum % 7 + 5;
			if (a > 6)
				a = a - 7;

			if (a != 0)
			{
				for (m = 0; m < a; m++)
					cout << '0' << " ";
			}

			for (k = 1; k < 31; k++)
			{
				cout << k;

				if ((k % 7 + a) % 7 != 0)
					cout << " ";
				else if ((k % 7 + a) % 7 == 0)
					cout << endl;
			}

			if (a == 1)
				cout << "0 0 0 0" << endl;
			else if (a == 2)
				cout << "0 0 0" << endl;
			else if (a == 3)
				cout << "0 0" << endl;
			else if (a == 4)
				cout << "0" << endl;
			else if (a == 6)
				cout << "0 0 0 0 0 0" << endl;
			else if (a == 0)
				cout << "0 0 0 0 0" << endl;

		}
	}

}



#ifndef _MYDATE_H_
#define _MYDATE_H_

#include <iostream>

using namespace std;

class myDate
{
	//friend �Լ�
	friend ostream &operator <<(ostream &outStream, const myDate& date);
	friend ostream &operator >>(istream &inStream, const myDate& date);
	friend myDate operator +(int num, const myDate& date);

public:
	//constructor
	myDate(int year = 1582, int month = 1, int day = 1);
	//copy constructor ���������
	myDate(const myDate& date);

	//accessor functions ������
	int getDayOfMonth() const;
	int getMonth() const;
	int getYear() const;

	//mutator functions ������
	void setDayOfMonth(int day);
	void setMonth(int month);
	void setYear(int year);
	void setDate(int year, int month, int day);

	//operators
	int operator-(const myDate& date) const; //difference bitween two days
	myDate operator +(int num) const;
	myDate operator -(int num) const;

	myDate& operator ++();
	myDate& operator --();
	myDate operator ++(int);
	myDate operator --(int);

	myDate& operator =(const myDate& date);
	myDate& operator +=(int num);
	myDate& operator -=(int num);

	bool operator >(const myDate& date) const;
	bool operator >=(const myDate& date) const;
	bool operator <(const myDate& date) const;
	bool operator <=(const myDate& date) const;
	bool operator ==(const myDate& date) const;
	bool operator !=(const myDate& date) const;

	//utility functions
	bool isLeapYear() const; //����
	int getDayOfWeek() const; //0=sunday, 6=saturday
	int getDayOfYear() const; //1=1.1 2=1.2 366=12.31(���⿡��)
	int getNumHolidays() const; //���ϼ� ���
	int getNumSummerTimeDays() const; //���Ÿ�� ��¥��
	void printCalendarOfMonth() const; // �޷� ����ϱ�

private:
	int day, month, year;

};

#endif

#ifndef _MYRATIONAL_H_
#define _MYRATIONAL_H_

#include<iostream>
using namespace std;

class myRational
{
	friend myRational operator *(int value, const myRational& r);
	friend ostream &operator <<(ostream &outStream, const myRational& r);
	friend istream &operator >>(istream &inStream, myRational& r);

	friend myRational operator +(int value, const myRational& r);
	friend myRational operator -(int value, const myRational& r);
	friend myRational operator *(int value, const myRational& r);
	friend myRational operator /(int value, const myRational& r);

private:
	long _num;
	long _den;
	long gcd(long m, long n);
	void reduce();

public:

	myRational();

	myRational(int num);
	myRational(int num, int den);
	myRational(const myRational& rat);

	int getNumerator() const;
	int getDenominator() const;

	myRational operator +(const myRational& r) const;
	myRational operator +(int value) const;
	myRational operator -(const myRational& r) const;
	myRational operator -(int value) const;
	myRational operator *(const myRational& r) const;
	myRational operator *(int value) const;
	myRational operator /(const myRational& r) const;
	myRational operator /(int value) const;

	myRational operator ++();
	myRational operator ++(int);
	myRational operator --();
	myRational operator --(int);

	myRational operator -() const;

	bool operator ==(const myRational& r) const;
	bool operator !=(const myRational& r) const;
	bool operator >(const myRational& r) const;
	bool operator >=(const myRational& r) const;
	bool operator <(const myRational& r) const;
	bool operator <=(const myRational& r) const;

	myRational& operator =(const myRational& r);
	myRational& operator +=(const myRational& r);
	myRational& operator -=(const myRational& r);
	myRational& operator *=(const myRational& r);
	myRational& operator /=(const myRational& r);

};
#endif
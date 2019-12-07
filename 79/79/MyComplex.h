
#ifndef _MYCOMPLEX_H_
#define _MYCOMPLEX_H_

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class myComplex
{
public:

	friend ostream &operator << (ostream &outStream, const myComplex& number);
	friend istream &operator >>(istream &instream, myComplex& number);

	//constructor
	myComplex(int real = 0, int imag = 0);
	//copy constructor
	myComplex(const myComplex& number);

	//accessor functions Á¢±ÙÀÚ
	int getRealPart() const;
	int getImaginaryPart() const;

	//mutator functions
	void setRealPart(int real);
	void setImaginaryPart(int imag);
	void set(int real, int imag);

	//overloaded binary operators
	myComplex operator +(const myComplex& number) const;
	myComplex operator +(int value) const;
	myComplex operator -(const myComplex& number) const;
	myComplex operator -(int value) const;
	myComplex operator *(const myComplex& number) const;
	myComplex operator *(int value) const;
	//int operator*(myComplex& number);

	//overloaded assignment operators
	myComplex& operator =(const myComplex& number);
	myComplex& operator =(int value);
	myComplex& operator +=(const myComplex& number);
	myComplex& operator +=(int value);
	myComplex& operator -=(const myComplex& number);
	myComplex& operator -=(int value);
	myComplex& operator *=(const myComplex& number);
	myComplex& operator *=(int value);

	//overloading relational operators
	bool operator ==(const myComplex& number) const;
	bool operator !=(const myComplex& number) const;
	bool operator >(const myComplex& number) const;
	bool operator >=(const myComplex& number) const;
	bool operator <(const myComplex& number) const;
	bool operator <=(const myComplex& number) const;

	//overloaded unary operators
	myComplex operator -();
	myComplex operator ~();
	myComplex operator ++();
	myComplex operator --();
	myComplex operator ++(int);
	myComplex operator --(int);

	friend myComplex operator* (int value, myComplex& number);
	friend myComplex operator- (int value, myComplex& number);
	friend myComplex operator+ (int value, myComplex& number);
	
private:
	int realPart;
	int imaginaryPart;
	double norm() const;
};

#endif
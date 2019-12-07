
#include "MyComplex.h"

//constructor
myComplex::myComplex(int real, int imag)
{
	realPart = real;
	imaginaryPart = imag;
}

//copy constructor
myComplex::myComplex(const myComplex& number)
{
	realPart = number.realPart;
	imaginaryPart = number.imaginaryPart;
}

//accessor functions
int myComplex::getRealPart() const
{
	return realPart;
}

int myComplex::getImaginaryPart() const
{
	return imaginaryPart;
}

//mutator functions
void myComplex::setRealPart(int real)
{
	realPart = real;
}

void myComplex::setImaginaryPart(int imag)
{
	imaginaryPart = imag;
}

void myComplex::set(int real, int imag)
{
	realPart = real;
	imaginaryPart = imag;
}

//overloaded binary operators
myComplex myComplex::operator+(const myComplex& number) const
{
	int newReal = realPart + number.realPart;
	int newImag = imaginaryPart + number.imaginaryPart;
	return myComplex(newReal, newImag);
}

myComplex myComplex::operator +(int value) const
{
	return myComplex(realPart+value, imaginaryPart);
}

myComplex operator+ (int value, myComplex& number)
{
	return myComplex(number.realPart+value, number.imaginaryPart);
}

myComplex myComplex::operator-(const myComplex& number) const
{
	int newReal = realPart - number.realPart;
	int newImag = imaginaryPart - number.imaginaryPart;
	return myComplex(newReal, newImag);
}

myComplex myComplex::operator -(int value) const
{
	return myComplex(realPart-value, imaginaryPart);
}

myComplex operator- (int value, myComplex& number)
{
	return myComplex(value-number.realPart, -number.imaginaryPart);
}

myComplex myComplex::operator*(const myComplex& number) const
{
	int newReal = (realPart * number.realPart)-(imaginaryPart*number.imaginaryPart);
	int newImag = (realPart * number.imaginaryPart)+(imaginaryPart*number.realPart);
	return myComplex(newReal, newImag);
}

myComplex myComplex::operator *(int value) const
{
	return myComplex(value*realPart, value*imaginaryPart);
}

myComplex operator *(int value, myComplex& number)
{
	return myComplex(number.realPart*value, number.imaginaryPart*value);
}

//assignment operators
myComplex& myComplex::operator =(const myComplex& number)
{
	this->realPart = number.realPart;
	this->imaginaryPart = number.imaginaryPart;
	return *this;
}

myComplex& myComplex::operator=(int value)
{
	realPart = value;
	imaginaryPart = 0;
	return *this;
}

myComplex& myComplex::operator +=(const myComplex& number)
{
	this->realPart += number.realPart;
	this->imaginaryPart += number.imaginaryPart;
	return *this;
}

myComplex& myComplex::operator+=(int value)
{
	realPart += value;
	imaginaryPart += 0;
	return *this;
}

myComplex& myComplex::operator -=(const myComplex& number)
{
	this->realPart -= number.realPart;
	this->imaginaryPart -= number.imaginaryPart;
	return *this;
}

myComplex& myComplex::operator-=(int value)
{
	realPart -= value;
	imaginaryPart -= 0;
	return *this;
}

myComplex& myComplex::operator *=(const myComplex& number)
{
	int newReal = (realPart * number.realPart) - (imaginaryPart*number.imaginaryPart);
	int newImag = (realPart * number.imaginaryPart) + (imaginaryPart*number.realPart);
	
	realPart = newReal;
	imaginaryPart = newImag;

	return *this;
}

myComplex& myComplex::operator*=(int value)
{
	realPart *= value;
	imaginaryPart *= value;
	return *this;
}


//overloading comparison operators
bool myComplex::operator==(const myComplex& number) const
{
	return (realPart == number.realPart) && (imaginaryPart == number.imaginaryPart);
}

bool myComplex::operator!=(const myComplex& number) const
{
	return (realPart != number.realPart) || (imaginaryPart != number.imaginaryPart);
}

bool myComplex::operator>(const myComplex& number) const
{
	return norm() > number.norm();
}

bool myComplex::operator>=(const myComplex& number) const
{
	return norm() >= number.norm();
}

bool myComplex::operator<(const myComplex& number) const
{
	return norm() < number.norm();
}

bool myComplex::operator<=(const myComplex& number) const
{
	return norm() <= number.norm();
}

//overloaded unary operators
myComplex myComplex::operator -()
{
	return myComplex((-realPart), (-imaginaryPart));
}

myComplex myComplex::operator ~()
{
	return myComplex(realPart, -imaginaryPart);
}

myComplex myComplex::operator ++()
{
	return myComplex(++realPart, imaginaryPart);
}

myComplex myComplex::operator ++(int)
{
	return myComplex(realPart++, imaginaryPart);
}

myComplex myComplex::operator --()
{
	return myComplex(--realPart, imaginaryPart);
}

myComplex myComplex::operator --(int)
{
	return myComplex(realPart--, imaginaryPart);
}

//private function
double myComplex::norm() const
{
	return realPart*realPart + imaginaryPart*imaginaryPart;
}

ostream &operator << (ostream &outStream, const myComplex& number)
{
	outStream << "(" << number.realPart << "," << number.imaginaryPart << ")";
	return outStream;
}

istream &operator >>(istream &instream, myComplex& number)
{
	instream >> number.realPart >> number.imaginaryPart;
	return instream;
}

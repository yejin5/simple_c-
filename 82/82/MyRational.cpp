
#include"MyRational.h"

myRational::myRational()
{
	_num = 0;
	_den = 1;
}

myRational::myRational(int num)
{
	_num = num;
	_den = 1;
}

myRational::myRational(int num, int den)
{
	_num = num;
	_den = den;
	reduce();
}

myRational::myRational(const myRational& rat)
{
	_num = rat.getNumerator();
	_den = rat.getDenominator();

	reduce();
}

int myRational::getNumerator() const
{
	return _num;
}

int myRational::getDenominator() const
{
	return _den;
}

myRational myRational::operator +(const myRational& r) const
{
	myRational R1(*this), R2(r);

	R1._num *= R2._den;
	R2._num *= R1._den;
	R1._den = R1._den*R2._den;

	R1._num += R2._num;

	R1.reduce();
	return R1;
}

myRational myRational::operator +(int value) const
{
	myRational R(value);

	return *this + R;
}

myRational myRational::operator -(const myRational& r) const
{
	myRational R1(*this), R2(r);

	R1._num *= R2._den;
	R2._num *= R1._den;
	R1._den = R1._den*R2._den;

	R1._num -= R2._num;

	R1.reduce();
	return R1;
}

myRational myRational::operator -(int value) const
{
	myRational R(value);

	return *this - R;
}

myRational myRational::operator *(const myRational& r) const
{
	myRational R1(*this), R2(r);

	R1._num *= R2._num;
	R1._den *= R2._den;

	R1.reduce();
	return R1;
}

myRational myRational::operator *(int value) const
{
	myRational R(value);

	return *this * R;
}

myRational myRational::operator /(const myRational& r) const
{
	myRational R1(*this), R2(r);
	int swap;

	swap = R2._num;
	R2._num = R2._den;
	R2._den = swap;
	R2.reduce();

	R1._num *= R2._num;
	R1._den *= R2._den;

	R1.reduce();
	return R1;
}

myRational myRational::operator /(int value) const
{
	myRational R(value);

	return *this / R;
}

myRational operator +(int value, const myRational& r)
{
	return r + value;
}

myRational operator -(int value, const myRational& r)
{
	myRational R(value);

	return R - r;
}

myRational operator *(int value, const myRational& r)
{
	return r * value;
}

myRational operator /(int value, const myRational& r)
{
	myRational R(value);

	return R / r;
}

myRational& myRational::operator =(const myRational& r)
{
	_num = r._num;
	_den = r._den;

	return *this;
}

myRational& myRational::operator +=(const myRational& r)
{
	*this = *this + r;
	return *this;
}

myRational& myRational::operator -=(const myRational& r)
{
	*this = *this - r;
	return *this;
}

myRational& myRational::operator *=(const myRational& r)
{
	*this = *this * r;
	return *this;
}

myRational& myRational::operator /=(const myRational& r)
{
	*this = *this / r;
	return *this;
}

myRational myRational::operator ++()
{
	_num += _den;
	return *this;
}

myRational myRational::operator ++(int)
{
	myRational R(_num, _den);

	_num += _den;
	return R;
}

myRational myRational::operator --()
{
	_num -= _den;
	return *this;
}

myRational myRational::operator --(int)
{
	myRational R(_num, _den);

	_num -= _den;
	return R;
}

bool myRational::operator ==(const myRational& r) const
{
	return (_num / _den) == (r._num / r._den);
}

bool myRational::operator !=(const myRational& r) const
{
	return !(*this == r);
}

bool myRational::operator >(const myRational& r) const
{
	return (_num / _den) > (r._num / r._den);
}

bool myRational::operator >=(const myRational& r) const
{
	return (_num / _den) >= (r._num / r._den);
}

bool myRational::operator <(const myRational& r) const
{
	return (_num / _den) < (r._num / r._den);
}

bool myRational::operator <=(const myRational& r) const
{
	return (_num / _den) <= (r._num / r._den);
}

myRational myRational::operator -() const
{
	myRational R(-_num, _den);

	return R;
}

ostream &operator <<(ostream &outStream, const myRational& r)
{
	if (r._num == 0)
		outStream << 0;
	else if (r._den == 1)
		outStream << r._num;
	else
		outStream << r._num << "/" << r._den;

	return outStream;
}

istream &operator >>(istream &inStream, myRational& r)
{
	inStream >> r._num >> r._den;

	if (r._den == 0)
	{
		r._num = 0;
		r._den = 1;
	}
	r.reduce();

	return inStream;
}

long myRational::gcd(long m, long n)
{
	if (m == n)
		return n;
	else if (m < n)
		return gcd(m, n - m);
	else
		return gcd(m - n, n);
}

void myRational::reduce()
{
	if (_num == 0 || _den == 0)
	{
		_num = 0;
		_den = 1;
		return;
	}

	if (_den < 0)
	{
		_den *= -1;
		_num *= -1;
	}

	if (_num == 1)
		return;

	int sgn = (_num < 0 ? -1 : 1);
	long g = gcd(sgn*_num, _den);
	_num /= g;
	_den /= g;
}

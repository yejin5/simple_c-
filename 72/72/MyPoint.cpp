
#include <cstdlib>
#include <iostream>
#include "MyPoint.h"

using namespace std;

//constructors
MyPoint::MyPoint() :x(0), y(0)
{}

MyPoint::MyPoint(int coordX, int coordY) : x(coordX), y(coordY)
{}

MyPoint::MyPoint(const MyPoint& p)
{}

//accessor functions
int MyPoint::getX() const
{
	return x;
}

int MyPoint::getY() const
{
	return y;
}

//mutator functions
void MyPoint::setX(int coordX)
{
	x = coordX;
}

void MyPoint::setY(int coordY)
{
	y = coordY;
}

/*bool MyPoint::operator==(const MyPoint& p)const
{
}

bool MyPoint::operator!=(const MyPoint& p)const
{
return !operator==(p);
}*/

//직선거리의 제곱을 계산
int MyPoint::dist2sqr(const MyPoint& p1, const MyPoint& p2)const
{
	int x1, y1, x2, y2;
	x1 = p1.x; y1 = p1.y;
	x2 = p2.x; y2 = p2.y;

	return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}

//직각거리를 계산
int MyPoint::dist1(const MyPoint& p1, const MyPoint& p2) const
{
	int x1, y1, x2, y2;
	x1 = p1.x; y1 = p1.y;
	x2 = p2.x; y2 = p2.y;

	return abs(x1 - x2) + abs(y1 - y2);
}
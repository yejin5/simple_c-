
#ifndef _MY_POINT_H_
#define _MY_POINT_H_

#include <cmath>

class MyPoint
{
public:
	MyPoint();
	MyPoint(int coordX, int coordY);
	MyPoint(const MyPoint& p);

	//accessor functions
	int getX() const;
	int getY() const;

	//mytator function
	void setX(int x);
	void setY(int y);

	//comparison operator
	//bool operator==(const MyPoint& p) const;
	//bool operator!=(const MyPoint& p) const;

	//utility functions
	int dist2sqr(const MyPoint& p1, const MyPoint& p2)const;	//�����Ÿ��� �������
	int dist1(const MyPoint& p1, const MyPoint& p2)const;	//�����Ÿ��� ���

private:
	int x, y;
};

#endif
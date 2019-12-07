#ifndef _MY_LINE_SEGMENT_H_
#define _MY_LINE_SEGMENT_H_

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "MyPoint.h"

class MyLineSegment
{
public:
	//constructors
	MyLineSegment();
	MyLineSegment(const MyPoint& p, const MyPoint& q);
	MyLineSegment(const MyLineSegment& seg);

	//intersection test functions
	bool isEndOfSegment(const MyPoint & p)const;
	bool isOnSegment(const MyPoint& p)const;
	bool properIntersection(const MyPoint& a, const MyPoint& b, const MyPoint& c, const MyPoint& d) const;
	bool improperIntersection(const MyPoint& a, const MyPoint& b, const MyPoint& c, const MyPoint& d)const;
	bool isLeftSide(const MyPoint &p)const;
	bool isCollinear(const MyPoint &p)const;

	//utility functions
	int lenfth2sqr() const;

private:
	MyPoint p1, p2;
	int getArea2(const MyPoint &p)const;
};

#endif
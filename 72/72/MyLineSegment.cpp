
#include "MyLineSegment.h"
using namespace std;

MyLineSegment::MyLineSegment() :p1(0, 0), p2(0, 0)
{
}

MyLineSegment::MyLineSegment(const MyPoint& p, const MyPoint& q) :p1(p), p2(q)
{
}

MyLineSegment::MyLineSegment(const MyLineSegment& s) : p1(s.p1), p2(s.p2)
{
}

/*
bool MyLineSegment::isEndOfSegment(const MyPoint & p) const
{
	if (p == p1 || p == p2)
		return true;
	else
		return false;
}
*/

/*
bool MyLineSegment::isOnSegment(const MyPoint& p)const
{
	return true;
}
*/

bool MyLineSegment::properIntersection(const MyPoint& a, const MyPoint& b, const MyPoint& c, const MyPoint& d) const
{
	int ax, ay, bx, by, cx, cy, dx, dy;
	ax = a.getX(); ay = a.getY();
	bx = b.getX(); by = b.getY();
	cx = c.getX(); cy = c.getY();
	dx = d.getX(); dy = d.getY();

	//음수, 양수, 0먼저 판단
	int sum = ((bx - ax)*(cy - ay)) - ((cx - ax)*(by - ay));
	int triangle1, compute_triangle1, compute_triangle2; //-1 1 0 판단

	if (sum < 0)
		triangle1 = -1;
	else if (sum > 0)
		triangle1 = 1;
	else
		triangle1 = 0;
	compute_triangle1 = triangle1;

	sum = ((bx - ax)*(dy - ay)) - ((dx - ax)*(by - ay));
	if (sum < 0)
		triangle1 = -1;
	else if (sum > 0)
		triangle1 = 1;
	else
		triangle1 = 0;
	compute_triangle2 = triangle1;

	//////////////////////////////////////////////////////////////////////
	
	sum = ((dx - cx)*(ay - cy)) - ((ax - cx)*(dy - cy));
	int compute_triangle3, compute_triangle4; //-1 1 0 판단

	if (sum < 0)
		triangle1 = -1;
	else if (sum > 0)
		triangle1 = 1;
	else
		triangle1 = 0;
	compute_triangle3 = triangle1;

	sum = ((dx - cx)*(by - cy)) - ((bx - cx)*(dy - cy));
	if (sum < 0)
		triangle1 = -1;
	else if (sum > 0)
		triangle1 = 1;
	else
		triangle1 = 0;
	compute_triangle4 = triangle1;

	if (compute_triangle1 == 0 || compute_triangle2 == 0 || compute_triangle3==0 || compute_triangle4==0)
		cout << "2" << endl;
	else if (compute_triangle1 == compute_triangle2 || compute_triangle3==compute_triangle4)
		cout << "0" << endl;
	else if ((compute_triangle1 == 1 && compute_triangle2 == -1) || (compute_triangle1 == -1 && compute_triangle2 == 1))
		cout << "1" << endl;

	return true;
}

bool MyLineSegment::improperIntersection(const MyPoint& a, const MyPoint& b, const MyPoint& c, const MyPoint& d)const
{
	return true;
}

/*
int MyLineSegment::lenfth2sqr() const
{
	return p1.dist2sqr(p2);
}*/

/*
int MyLineSegment::getArea2(const MyPoint &p)const
{
	int p1x, p2x, px, p1y, p2y, py;

	p1x = p1.getX();
	p1y = p1.getY();
	p2x = p2.getX();
	p2y = p2.getY();
	px = p.getX();
	py = p.getY();

	return p1x*p2y - p1y*p2x + p1y*px - p1x*py + p2x*py - px*p2y;
}
*/

/*
bool MyLineSegment::isLeftSide(const MyPoint &p) const
{
	return getArea2(p) > 0;
}

bool MyLineSegment::isCollinear(const MyPoint &p) const
{
	return getArea2(p) == 0;
}
*/
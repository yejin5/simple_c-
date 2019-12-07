
/****************************************/
/*  ���δ��б� ����������Ŵ���           */
/*  ��ǻ�Ͱ��к� 20143079 ������         */
/*  72��. ������ ����                   */
/***************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "MyLineSegment.h"

using namespace std;

void main()
{
	ifstream instream;
	int cases;

	instream.open("input.txt");
	if (instream.fail())
	{
		cerr << "input file opening is failed.\n";
		exit(1);
	}

	instream >> cases;

	for (int i = 0; i < cases; i++)
	{
		int ax, ay, bx, by, cx, cy, dx, dy;
		instream >> ax >> ay;
		instream >> bx >> by;
		instream >> cx >> cy;
		instream >> dx >> dy;

		MyPoint a(ax, ay); MyPoint b(bx, by); 
		MyLineSegment line1(a, b); 

		MyPoint c(cx, cy); MyPoint d(dx, dy);
		MyLineSegment line2(c, d);

		line1.properIntersection(a, b, c, d);
	}

	instream.close();
}
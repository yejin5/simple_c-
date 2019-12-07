
/****************************************/
/*  국민대학교 전자정보통신대학           */
/*  컴퓨터공학부 20143079 오예진         */
/*  71번. 2차원 점                      */
/***************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "MyPoint.h"

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
		int coordx, coordy;
		int x1, y1, x2, y2;

		instream >> coordx >> coordy;
		MyPoint dot1(coordx, coordy);
		x1 = coordx; y1 = coordy;

		instream >> coordx >> coordy;
		MyPoint dot2(coordx, coordy);
		x2 = coordx; y2 = coordy;
		
		if (x1 == x2)
		{
			if (y1 == y2)
				cout << "1" << " ";
			else
				cout << "0" << " ";
		}
		else if (x1 != x2 || y1 != y2)
			cout << "0" << " ";

		cout << dot1.dist2sqr(dot1, dot2) << " " << dot1.dist1(dot1, dot2) << " ";

		coordx = dot1.getX();
		coordy = dot1.getY();

		MyPoint dot3(dot1);

		dot3.setX(coordy);
		dot3.setY(coordx);

		cout << dot1.dist2sqr(dot1, dot3) << " " << dot1.dist1(dot1, dot3) << endl;
	}
	instream.close();
}
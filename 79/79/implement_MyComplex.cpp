
/****************************************/
/*  국민대학교 전자정보통신대학           */
/*  컴퓨터공학부 20143079 오예진         */
/*  79. 복소수                          */
/***************************************/

#include <fstream>
#include <cstdlib>
#include "MyComplex.h"

void testSimpleCase();
void testDataFromFile();

void main()
{
	testSimpleCase();
	testDataFromFile();
}

void testSimpleCase()
{
	myComplex c0, c1(1), c2(2, 2);
	myComplex c3(c2);
	myComplex c4, c5, c6, c7, c8, c9;

	//test constructor
	cout << c0 << endl << c1 << endl << c2 << endl;
	//1 2 3//

	//test copy constructor
	cout << c3 << endl;
	//4//

	//test accessor function
	cout << c3 << endl;
	//5//

	//test mutator function
	c3.set(3, 3);
	cout << c3 << endl;
	//6//

	c3.setRealPart(4);
	cout << c3 << endl;
	//7//

	c3.setImaginaryPart(4);
	cout << c3 << endl;
	//8//

	//test binary operators
	c4 = c1 + c3;
	c5 = c1 - c3;
	c6 = c4*c5;
	cout << c4 << endl << c5 << endl << c6 << endl;
	//9 10 11//

	c7 = c6 + 2;
	c8 = c6 - 2;
	c9 = c6 * 2;
	cout << c7 << endl << c8 << endl << c9 << endl;
	//12 13 14//

	c7 += c4;
	c8 -= c5;
	c9 *= c6;
	cout << c7 << endl << c8 << endl << c9 << endl;
	//15 16 17//

	c7 += 2;
	c8 -= 2;
	c9 *= 2;
	cout << c7 << endl << c8 << endl << c9 << endl;
	//18 19 20//

	//test comparison operators
	cout << (c8 != c9) << " " << (c8 == c9) << endl;
	cout << (c8 > c9) << " " << (c8 >= c9) << " " << (c8 < c9) << " " << (c8 <= c9) << endl;
	//21 22//

	c7 = c8 = c9;
	cout << (c8 != c9) << " " << (c8 == c9) << endl;
	cout << (c8 > c9) << " " << (c8 >= c9) << " " << (c8 < c9) << " " << (c8 <= c9) << endl;
	//23 24//

	//test prefix operators
	c7 = -myComplex(2, 3);
	c8 = (++c7) * 2;
	c9 = 2 * (c7++);
	cout << c7 << " " << c8 << " " << c9 << endl;
	//25//

	c7 = ~myComplex(2, 3);
	c8 = (--c7) * 2;
	c9 = 2 * (c7--);
	cout << c7 << " " << c8 << " " << c9 << endl;
	//26//

	//test expressions with myComplex number
	c1 = myComplex(1, 2);
	c2 = myComplex(2, 3);
	c3 = myComplex(4, 5);
	c4 = myComplex(5, 6);
	c5 = myComplex(6, 7);
	
	c6 = 3;
	//myComplex c6(3);

	cout << -(c1*c2) - (2 * c3) + (~c4*c5 * 3) + (2 - c6) << endl;
	//27//
}

void testDataFromFile()
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
		myComplex c1, c2, c3, c4;
		myComplex c5, c6, c7, c8, c9;

		instream >> c1 >> c2 >> c3 >> c4;

		cout << c1 << " " << c2 << " " << c3 << " " << c4 << endl;
		cout << (2 + c1 + 3) + (2 - c2 - 3) * (2 * c3 * 3) - (2 * c4 - 3) << endl;
		//28 29//

		c5 = c6 = c7 = c8 = c1;
		cout << (c5 == c2) << " " << (c5 != c2) << endl;
		cout << (c5>c2) << " " << (c5 >= c2) << " " << (c5 < c2) << " " << (c5 <= c2) << endl;
		cout << (c5 == c6) << " " << (c5 != c6) << endl;
		cout << (c5>c6) << " " << (c5 >= c6) << " " << (c5 < c6) << " " << (c5 <= c6) << endl;

		c5 += c2;
		c6 -= c3;
		c7 *= c4;
		c8 = c2.getRealPart();
		c9 = c3.getImaginaryPart();
		cout << c5 << " " << c6 << " " << c7 << " " << c8 << " " << c9 << endl;

		c7 = -c6;
		c8 = (++c7) * 2;
		c9 = 2 * (c7++);
		cout << c7 << " " << c8 << " " << c9 << endl;

		c7 = ~c6;
		c8 = (++c7) * 2;
		c9 = 2 * (c7++);
		cout << c7 << " " << c8 << " " << c9 << endl;

	}
	instream.close();
}
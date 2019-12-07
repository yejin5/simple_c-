
#ifndef _MY_MAGIC_SQUARE_EVEN_H_
#define _MY_MAGIC_SQUARE_EVEN_H_

const int max_size = 50;
using namespace std;

class MyMagicSquareEven
{
public:

	MyMagicSquareEven(ifstream &instream)
	{
		instream >> compute_num;
	}

	void L_square(int i, int j);
	void U_square(int i, int j);
	void X_square(int i, int j);

	void make_MyMagicSquareEven();

	void make_MyMagicSquareEven4();
	void make_MyMagicSquareEven2();

	void make_MyMagicSquareEven_odd();

	void print_MyMagicSquareEven();

private:
	int compute_num;
	int square[max_size + 10][max_size + 10];

};

#endif
/****************************************/
/*  ���δ��б� ����������Ŵ���           */
/*  ��ǻ�Ͱ��к� 20143079 ������         */
/*  50��. ������ ���� ��ȯ               */
/***************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

void main()
{
	ifstream instream;

	int cases;
	int i, j, k, n;

	int original_sys, new_sys; //����

	char data[100];
	char *stop;
	int cen;
	char compute[100];

	instream.open("input.txt");
	if (instream.fail())
	{
		cerr << "input file opening failed.\n";
		exit(1);
	}

	instream >> cases;
	for (i = 0; i < cases; i++)
	{
		instream >> original_sys >> data >> new_sys;

		cen = strtol(data, &stop, original_sys);
		_itoa_s(cen, compute, new_sys);
		
		cout << compute << endl;
	}
	instream.close();
}
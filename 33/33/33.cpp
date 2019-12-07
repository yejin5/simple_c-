/****************************************/
/*  ���δ��б� ����������Ŵ���           */
/*  ��ǻ�Ͱ��к� 20143079 ������         */
/*  33��. ��ĵ���                      */
/***************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void main()
{
	ifstream instream;

	int cases;
	int i, j, k, n;

	int row, col;
	int arr_1[101][101], arr_2[101][101];
	int print[101][101]; //������ ���

	instream.open("input.txt");
	if (instream.fail())
	{
		cerr << "input file opening failed.\n";
		exit(1);
	}
	instream >> cases;

	for (i = 0; i < cases; i++)
	{
		for (j = 0; j < 101; j++)
		{
			for (k = 0; k < 101; k++)
			{
				arr_1[j][k] = 0;
				arr_2[j][k] = 0;
				print[j][k] = 0;
			}
		}

		instream >> row >> col;

		for (j = 0; j < row; j++)
		{
			for (k = 0; k < col; k++)
				instream >> arr_1[j][k];
		}
		for (j = 0; j < row; j++)
		{
			for (k = 0; k < col; k++)
				instream >> arr_2[j][k];
		} //��Ĺޱ�

		for (j = 0; j < row; j++)
		{
			for (k = 0; k < col; k++)
				print[j][k] = arr_1[j][k] + arr_2[j][k];
		}

		for (j = 0; j < row; j++)
		{
			cout << print[j][0];

			for (k = 1; k < col; k++)
			{
				cout <<" "<<print[j][k];
			}
			cout << endl;
		}
	}
	instream.close();
}
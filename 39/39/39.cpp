/****************************************/
/*  ���δ��б� ����������Ŵ���           */
/*  ��ǻ�Ͱ��к� 20143079 ������         */
/*  29��. ���� �밢��                   */
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

	int arr[101][101]; //���� ���
	int size; //���� ��� ũ��

	int sum_dia[101]; //������ �밢�� ��
	int sum_dia2[101]; //������ �밢�� ��

	int sum_max; //���� ū ��

	instream.open("input.txt");
	if (instream.fail())
	{
		cerr << "input file opening failed.\n";
		exit(1);
	}

	instream >> cases;

	for (i = 0; i < cases; i++)
	{
		sum_max = 0;
		for (j = 0; j < 101; j++)
		{
			sum_dia[j] = 0;
			sum_dia2[j] = 0;
		}
		for (j = 0; j < 101; j++)
		{
			for (k = 0; k < 101; k++)
				arr[j][k] = 0;
		}

		instream >> size;

		for (j = 0; j < size; j++) //��� �ޱ�
		{
			for (k = 0; k < size; k++)
				instream >> arr[j][k];
		}

		//������ �밢���� �� -> �迭�� �ֱ�
		for (j = 0; j < size; j++)
		{
			for (k = 0; k < size; k++)
			{
				if (j <= k)
					sum_dia[k - j + 1] += arr[j][k];
				else
					sum_dia[size - (j - k) + 1] += arr[j][k];
			}
		}

		sum_max = sum_dia[1];

		for (j = 1; j < size + 1; j++)
		{
			if (sum_max < sum_dia[j])
				sum_max = sum_dia[j];
		}

		//������ �밢���� ��->�迭�� �ֱ�
		for (j = 0; j < size; j++)
		{
			for (k = 0; k < size; k++)
			{
				if (j + k == size - 1)
					sum_dia2[1] += arr[j][k];
				else if (j + k < size - 1)
					sum_dia2[j + k + 2] += arr[j][k];
				else
					sum_dia2[j + k - size + 2] += arr[j][k];
			}
		}


		for (j = 1; j < size + 1; j++)
		{
			if (sum_max < sum_dia2[j])
				sum_max = sum_dia2[j];
		}
		cout << sum_max << endl;

	}
	instream.close();
}
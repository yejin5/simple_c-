
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include "MyMagicSquareEven.h"
void MyMagicSquareEven::make_MyMagicSquareEven4()
{
	for (int i = 0; i < compute_num; i++)
	{
		for (int j = 0; j < compute_num; j++)
		{


			square[i][j] = i*compute_num + j + 1;

			for (int k = 0; k < 13; k++)
			{
				if ((abs(i - j) == k * 4))
				{
					square[i][j] = (compute_num*compute_num) - (i*compute_num + j);
					break;
				}
			}

			for (int k = 1; k < 25; k++)
			{
				if (i + j == k * 4 - 1)
				{
					square[i][j] = (compute_num*compute_num) - (i*compute_num + j);
					break;
				}
			}


		}
	}
}
void MyMagicSquareEven::make_MyMagicSquareEven2()
{
	make_MyMagicSquareEven_odd();

	for (int i = 0; i < compute_num; i += 2)
	{
		if (i < compute_num / 2 - 1)
		{
			for (int j = 0; j < compute_num; j += 2)///////////////////////l
			{
				L_square(i, j);
			}
		}
		else if (i == (compute_num / 2 - 1))
		{
			for (int j = 0; j < compute_num; j += 2)/////////////////////u
			{
				if (j == (compute_num / 2 - 1))
				{
					U_square(i, j);
				}
				else
				{
					L_square(i, j);
				}
			}
		}
		else if (i == (compute_num / 2 + 1))
		{
			for (int j = 0; j < compute_num; j += 2)/////////////////////u
			{
				if (j != (compute_num / 2 - 1))
				{
					U_square(i, j);
				}
				else
				{
					L_square(i, j);
				}
			}


		}
		else
		{
			for (int j = 0; j < compute_num; j += 2)//////////////////////x
			{
				X_square(i, j);
			}
		}
	}
}
void MyMagicSquareEven::make_MyMagicSquareEven()
{
	if (compute_num % 4 == 0)
	{
		make_MyMagicSquareEven4();
	}
	else
	{
		make_MyMagicSquareEven2();
	}
}
void MyMagicSquareEven::print_MyMagicSquareEven()
{
	for (int i = 0; i < compute_num; i++)
	{
		for (int j = 0; j < compute_num; j++)
		{
			std::cout << square[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
void MyMagicSquareEven::make_MyMagicSquareEven_odd()
{
	int i, j, k;
	//////////////////////ù��°���� �߾ӿ� 1�� �־�� �ϹǷ�////////////////////
	i = 0;
	j = compute_num / 2;
	///////////////////////////////////////////////////////////////////////////


	for (int k = 0; k < compute_num; k++)
	{
		for (int l = 0; l < compute_num; l++)
		{
			square[k][l] = -1;
		}
	}




	for (k = 0; k<compute_num*compute_num;)//�� volume*volume �� 25ĭ�� ä���� �ϱ⿡ k<volume*volume��� �Ͽ���.
	{
		if (i<0 && j >= 0)//i�������� �ǰ� j�� ����ΰ��
		{
			i = compute_num - 2;
		}
		else if (j<0 && i >= 0)//j�������� �ǰ� i�� ����ΰ��
		{
			j = compute_num - 1;
		}
		else if (i<0 && j<0)//j�� i�Ѵ� �����ΰ��
		{
			i += 4;
			j -= 2;
		}
		else if (square[i][j] < 0)//arr[i][j]�ȿ� �ƹ� ���ڵ� ���� ���(�����ϰ� arr�ȿ� ���ڸ� �־��ִ� if���̴�.)
		{
			square[i][j] = k + 1;//k�� 0���� 24���� �� if���� ���ö����� 1�� �����Ѵ�.
			i -= 2;
			j += 2;
			k += 4;
		}
		else if (square[i][j] >0)//arr[i][j]�ȿ� �̹� ���ڵ� �ִ� ���
		{
			i += 4;
			j -= 2;
		}

		///////////////////arr[0][2] =1 �� ���� ��� ������ �ٸ� ��� i�� j�� 5�� �Ѿ�� ��찡 ����� ������ �ٿ��־���.//////////////////
		i %= compute_num;
		j %= compute_num;
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	}

}

void MyMagicSquareEven::L_square(int i, int j)
{
	square[i][j] = square[i][j + 1] + 3;
	square[i + 1][j] = square[i][j + 1] + 1;
	square[i + 1][j + 1] = square[i][j + 1] + 2;
}
void MyMagicSquareEven::U_square(int i, int j)
{
	square[i][j + 1] += 3;
	square[i][j] = square[i][j + 1] - 3;
	square[i + 1][j] = square[i][j + 1] - 2;
	square[i + 1][j + 1] = square[i][j + 1] - 1;
}
void MyMagicSquareEven::X_square(int i, int j)
{
	square[i][j + 1] += 3;
	square[i][j] = square[i][j + 1] - 3;
	square[i + 1][j] = square[i][j + 1] - 1;
	square[i + 1][j + 1] = square[i][j + 1] - 2;
}
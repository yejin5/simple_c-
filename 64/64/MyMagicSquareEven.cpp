
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
	//////////////////////첫번째행의 중앙에 1을 넣어야 하므로////////////////////
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




	for (k = 0; k<compute_num*compute_num;)//총 volume*volume 즉 25칸을 채워야 하기에 k<volume*volume라고 하였다.
	{
		if (i<0 && j >= 0)//i는음수가 되고 j만 양수인경우
		{
			i = compute_num - 2;
		}
		else if (j<0 && i >= 0)//j는음수가 되고 i만 양수인경우
		{
			j = compute_num - 1;
		}
		else if (i<0 && j<0)//j와 i둘다 음수인경우
		{
			i += 4;
			j -= 2;
		}
		else if (square[i][j] < 0)//arr[i][j]안에 아무 숫자도 없는 경우(유일하게 arr안에 숫자를 넣어주는 if문이다.)
		{
			square[i][j] = k + 1;//k는 0부터 24까지 이 if문에 들어올때마다 1씩 증가한다.
			i -= 2;
			j += 2;
			k += 4;
		}
		else if (square[i][j] >0)//arr[i][j]안에 이미 숫자도 있는 경우
		{
			i += 4;
			j -= 2;
		}

		///////////////////arr[0][2] =1 인 경우는 상관 없지만 다른 경우 i나 j가 5를 넘어가는 경우가 생기기 때문에 붙여주었다.//////////////////
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


#include <iostream>
#include <fstream>
#include <cstdlib>
#include "cstring"
#include "MyCreditCardNumber.h"

//constructors
MyCreditCardNumber::MyCreditCardNumber()
{
	cardNumber[0] = '\0';
}

MyCreditCardNumber::MyCreditCardNumber(char number[])
{
	strcpy_s(cardNumber, number);
}

//utility functions
bool MyCreditCardNumber::isCorrectNumber() const
{
	if (isCorrectLength() && isCheckSumValid())
		return true;
	else
		return false;
}

//private functions
bool MyCreditCardNumber::isCorrectLength() const
{
	int num = strlen(cardNumber);

	if (cardNumber[0] == '3' && num == 15)
		return true;
	else if (cardNumber[0] == '3' && num == 14)
		return true;
	else if (cardNumber[0] == '6' && num == 16)
		return true;
	else if (cardNumber[0] == '5' && num == 16)
		return true;
	else if (cardNumber[0] == '4' && num == 13)
		return true;
	else if (cardNumber[0] == '4' && num == 16)
		return true;
	else
		return false;
}

bool MyCreditCardNumber::isCheckSumValid() const
{
	int num = strlen(cardNumber);

	int number = num-1;
	int total=0;
	int check_num;
	char c_arr[31];

	for (int i = 0; i < 31; i++)
		c_arr[i] = 0;

	for (int i = 0; i < num; i++)
		c_arr[i] = cardNumber[i];
		
	if (cardNumber[0] == '3' && num == 15 || cardNumber[0] == '3' && num == 14 || cardNumber[0] == '6' && num == 16 || cardNumber[0] == '5' && num == 16 || cardNumber[0] == '4' && num == 13 || cardNumber[0] == '4' && num == 16)
	{
		for (int i = num-1; i >= 0; i--)
		{
			if (i==number && number>=0)
			{
				if (c_arr[number] * 2 < 10)
				{
					c_arr[number] = c_arr[number] * 2;
					number -= 2;
				}
				else if (c_arr[number] * 2 >= 10)
				{
					c_arr[number] = c_arr[number] * 2 - 9;
					number -= 2;
				}
			}
		}

		for(int i=0; i<num; i++)
			total += c_arr[i];

		check_num = 10 - (total % 10);

		if (check_num == c_arr[num])
			return true;
		else
			return false;
	}

	else
		return false;

}
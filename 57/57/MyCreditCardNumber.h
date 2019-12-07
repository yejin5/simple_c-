
#ifndef _MY_CREDIT_CARD_NUMBER_H_
#define _MY_CREDIT_CARD_NUMBER_H_

const int max_length = 20;

class MyCreditCardNumber
{
public:
	//constructors
	MyCreditCardNumber();
	MyCreditCardNumber(char number[]);

	//utility functions
	bool isCorrectNumber() const;

private:
	char cardNumber[max_length+11];
	bool isCorrectLength() const;
	bool isCheckSumValid() const;

};

#endif

#ifndef _READ_NUMBER_H_
#define _READ_NUMBER_H_

const int MAX_Length = 20;

class ReadNumber{
public:
	ReadNumber();
	ReadNumber(unsigned int num);

	void setNumber(unsigned int num);
	void read() const;

private:
	unsigned int number;

	static char digits[10][MAX_Length];
	static char teens[20][MAX_Length];
	static char ties[10][MAX_Length];
	static char units[4][MAX_Length];
};

#endif
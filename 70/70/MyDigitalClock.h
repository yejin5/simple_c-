
#ifndef _MY_DIGITAL_CLOCK_H_
#define _MY_DIGITAL_CLOCK_H_

#include <iostream>
using namespace std;

class MyDigitalClock
{
public:
	friend ostream& operator<< (ostream&, const MyDigitalClock&);

	//constructors
	MyDigitalClock(int h = 12, int m = 0, bool ap = false);
	MyDigitalClock(string clock);

	MyDigitalClock tick();
	MyDigitalClock untick();
	MyDigitalClock operator++();
	MyDigitalClock operator++(int);
	MyDigitalClock operator--();
	MyDigitalClock operator--(int);

private:
	int hour;
	int min;
	bool am_pm;

	int hour_arr[2];
	int min_arr[2];
	char a_p; //am인지 pm인지 판별

};

#endif
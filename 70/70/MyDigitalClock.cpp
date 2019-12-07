
#include <iomanip>
#include <string>
#include <iostream>
#include  "MyDigitalClock.h"


MyDigitalClock::MyDigitalClock(int h, int m, bool ap) :hour(h), min(m), am_pm(ap)
{
}

MyDigitalClock::MyDigitalClock(string clock)
{
	hour = atoi(clock.substr(0, 2).c_str());
	min = atoi(clock.substr(3, 2).c_str());
	
	if (clock.substr(5, 1) == "A") //am
		am_pm = true;
	else
		am_pm = false;
}

MyDigitalClock MyDigitalClock::tick()
{
	++min;

	if (min == 60)
	{
		hour++;
		min = 0;
	}
	if (hour == 13)
		hour = 1;
	if (hour == 12 && min == 0)
		am_pm = !am_pm;

	return *this;
}

MyDigitalClock MyDigitalClock::untick()
{
	--min;

	if (min < 0)
	{
		hour--;
		min = 59;
	}
	if (hour == 0)
	{
		hour = 12;
		// am_pm = !am_pm;
	}
	if (hour == 11 && min == 59)
		am_pm = !am_pm;
	
	return *this;
}

MyDigitalClock MyDigitalClock::operator++()
{
	return tick();
}

MyDigitalClock MyDigitalClock::operator++(int)
{
	MyDigitalClock c = *this;
	tick();

	return c;
}

MyDigitalClock MyDigitalClock::operator--()
{
	return untick();
}

MyDigitalClock MyDigitalClock::operator--(int)
{
	MyDigitalClock c = *this;
	untick();

	return c;
}

ostream& operator<<(ostream& oStream, const MyDigitalClock& c)
{
	oStream << setfill('0') << setw(2) << c.hour << ':' << setw(2) << c.min;
	if (!c.am_pm)
		oStream << "PM";
	else
		oStream << "AM";
	oStream << endl;

	return oStream;
}
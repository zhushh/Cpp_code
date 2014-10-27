#include <iostream>

using std::cout;

#include "time2.h"

Time::Time(int hr, int min, int sec)
{
	setTime(hr, min, sec);
}

void Time::setTime(int h, int m, int s)
{
	hour = (h >= 0 && h < 24) ? h : 0;
	minute = (m >= 0 && m < 60) ? m : 0;
	second = (s >= 0 && s < 60) ? s : 0;
}

void Time::printMilitary()
{
	cout << (hour < 10 ? "0" : "") << hour << ":"
	     << (minute < 10 ? "0" : "") << minute;
}

void Time::printStandard()
{
	cout << ((hour == 0 || hour == 12) ? 12 : hour % 12)
	     << ":" << (minute < 10 ? "0" : "") << minute
	     << ":" << (second < 10 ? "0" : "") << second
	     << (hour < 12 ? " AM" : " PM");
}

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include "time2.h"

int main()
{
	Time t1,
	     t2(2),
	     t3(21, 34),
	     t4(12, 25, 42),
	     t5(27, 74, 99);
	
	cout << "Constructed with:\n"
	     << "all argumennts defaulted:\n  ";
	t1.printMilitary();
	cout << "\n  ";
	t1.printStandard();
	
	cout << "\nhour specified; minute and second defaulted:"
	     << "\n  ";
	t2.printMilitary();
	cout << "\n  ";
	t2.printStandard();
	
	cout << "\nhour and minute specified; second defaulted:"
	     << "\n  ";
	t3.printMilitary();
	cout << "\n  ";
	t3.printStandard();
	
	cout << "\nhour, minute, and second sepecified:"
	     << "\n  ";
	t4.printMilitary();
	cout << "\n  ";
	t4.printStandard();
	
	cout << "\nall invalid values specified:"
	     << "\n  ";
	t5.printMilitary();
	cout << "\n  ";
	t5.printStandard();
	cout << endl;
	
	return 0;
}



#include "time4.h"

Time::Time(int hr, int min, int sec) {
	setTime(hr, min, sec);
}

void Time::setTime(int h, int m, int s) {
	hour = (h >= 0 && h < 24) ? h : 0;
	minute = (m >= 0 && m < 60) ? m : 0;
	second = (s >= 0 && s < 60) ? s : 0;
}

int Time::getHour() {
	return hour;
}

int &Time::badSetHour(int hh) {
	hour = (hh >= 0 && hh < 24) ? hh : 0;
	return hour;
}

#include <iostream>

using std::cin;
using std::endl;
using std::cout;

#include "time4.h"

int main()
{
	Time t;
	int &hourRef = t.badSetHour(20);
	
	cout << "Hour before modification: " << hourRef;
	hourRef = 30;
	cout << "\nHour after modification: " << t.getHour();
	
	t.badSetHour(12) = 74;
	cout << "\n\n*********************************\n"
	     << "POOR PROGRAMMING PRACTICE!!!!!!!!\n"
	     << "badSetHour as an lvalue, Hour: "
	     << t.getHour()
	     << "\n*********************************" << endl;
	return 0;
}



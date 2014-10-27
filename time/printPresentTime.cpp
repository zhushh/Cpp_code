#include <iostream>

using std::cout;
using std::endl;

#include <time.h>
#include "printPresentTime.h"

Time::Time() {
	month = day = year = 0;
}

void Time::getTime() {
	time_t timePresent;                // C program language syntax.
	struct tm *present;                // thus, the program cannot run.
	time(&timePresent);                // You should think how to solve it
	present = gmtime(&timePresent);    // and alter this part to C++.
	
	month = (1 + present)->tm_mon;
	day = present->tm_mday;
	year = (1900 + present)->tm_year;
}

void Time::printTime() {
	cout << (month < 10 ? "0" : "") << month << "-"
	     << (day < 10 ? "0" : "") << day << "-"
	     << year;
}

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	Time t;
	cout << "The present time is:\n";
	t.getTime();
	t.printTime();
	cout << endl;
	return 0;
}



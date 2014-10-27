#include <iostream>

using std::cout;

#include "time3.h"

Time::Time(int hr, int min, int sec)
{
	setTime(hr, min, sec);
}

void Time::setTime(int h, int m, int s)
{
	setHour(h);
	setMinute(m);
	setSecond(s);
}

void Time::setHour(int h)
{
	hour = (h >= 0 && h < 24) ? h : 0;
}

void Time::setMinute(int m)
{
	minute = (m >= 0 && m < 60) ? m : 0;
}

void Time::setSecond(int s)
{
	second = (s >= 0 && s < 60) ? s : 0;
}

int Time::getHour() { return hour; }

int Time::getMinute() { return minute; }

int Time::getSecond() { return second; }

void Time::printMilitary()
{
	cout << (hour < 10 ? "0" : "") << hour << ":"
	     << (minute < 10 ? "0" : "") << minute;
}

void Time::printStandard()
{
	cout << ((hour == 0 || hour == 12) ? 12 : hour%12)
	     << ":" << (minute < 10 ? "0" : "") << minute
	     << ":" << (second < 10 ? "0" : "") << second
	     << (hour < 12 ? " AM" : " PM");
}

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#include "time3.h"

void incrementMinutes(Time &, const int);

int main()
{
	Time t;
	t.setHour(17);
	t.setMinute(34);
	t.setSecond(25);
	
	cout << "Result of setting all valid values:\n"
	     << "  Hour: " << t.getHour()
	     << "  Minute: " << t.getMinute()
	     << "  Second: " << t.getSecond();
	
	t.setHour(234);
	t.setMinute(43);
	t.setSecond(6373);
	
	cout << "\n\nResult of attempting to set invalid hour and"
	     << " second:\n  Hour: " << t.getHour()
	     << "  Minute: " << t.getMinute()
	     << "  Second: " << t.getSecond() << "\n\n";m
	
	t.setTime(11, 58, 0);
	incrementMinutes(t, 3);
	
	return 0;
}

void incrementMinutes(Time &tt, const int count)
{
	cout << "Incrementing minute " << count
	     << " times:\nStart time: ";
    tt.printStandard();
    
    for (int i = 0; i < count; i++) {
		tt.setMinute((tt.getMinute() + 1) % 60);
		
		if (tt.getMinute() == 0)
		    tt.setHour((tt.getHour() + 1) % 24);
		
		cout << "\nminute + 1: ";
		tt.printStandard();
    }
    
    cout << endl;
}



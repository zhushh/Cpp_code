#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// time class
class Time {
	public:
		Time();   // constructor
		void setTime(int , int , int );  // time set
		void printMilitary();  // print with military
		void printStandard();  // print with standard
	private:  // class member
		int hour;
		int minute;
		int second;
};

Time::Time()
{
	hour = minute = second = 0;
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

int main()
{
	Time t;
	
	cout << "The initial military time is ";
	t.printMilitary();
	cout << "\nThe initial standard time is ";
	t.printStandard();
	
	t.setTime(13, 27, 6);
	cout << "\n\nMilitary time after setTime is ";
	t.printMilitary();
	cout << "\nStandard time after setTime is ";
	t.printStandard();
	
	t.setTime(99, 99, 99);
	cout << "\n\nAfter attempting invalid settings:"
	     << "\nMilitary time ";
	t.printMilitary();
	cout << "\nStandard time ";
	t.printStandard();
	cout << endl;
	return 0;
}


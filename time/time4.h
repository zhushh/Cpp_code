#ifndef TIME4_H
#define TIME4_H

class Time {
public:
	Time(int = 0, int = 0, int = 0);
	void setTime(int , int , int);
	int getHour();
	int &badSetHour(int);
private:
	int hour;
	int minute;
	int second;
};
#endif


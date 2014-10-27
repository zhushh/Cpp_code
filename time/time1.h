#ifndef TIME1_H
#define TIME1_H

class Time {
public:
	Time();
	void setTime(int , int , int);
	void printMilitary();
	void printStandard();
private:
	int hour;
	int minute;
	int second;
};

#endif



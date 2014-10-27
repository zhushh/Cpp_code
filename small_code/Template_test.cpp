#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include <iomanip>
using std::setiosflags;
using std::setprecision;
using std::setw;

template <typename T>
double average(T a, T b, T c)
{
	double sum;
	sum = a + b + c;
	return sum/3.0;
}

int main()
{
	int integer1, integer2, integer3;
	cout << "Enter three integer: ";
	cin >> integer1 >> integer2 >> integer3;
	double ave;
	ave = average(integer1, integer2, integer3);
	cout << setw(20) << std::left << setprecision(3)
	     << setiosflags(ios::fixed | ios::showpoint)
	     << ave << endl;
	
	
	double numa, numb, numc;
	cout << "Enter three float number: ";
	cin >> numa >> numb >> numc;
	ave = average(numa, numb, numc);
	cout << setw(20) << std::left << setprecision(3)
	     << setiosflags(ios::fixed | ios::showpoint)
	     << ave << endl;
	
	return 0;
}



#include <iostream>
using std::cin;
using std::cout;
using std::endl;

template <class T>
T max(T a, T b, T c)
{
	T max = a;
	if (max < b) {
		max = b;
	}
	if (max < c) {
		max = c;
	}
	return max;
}

int main()
{
	int integer1, integer2, integer3;
	cout << "Enter three integers: ";
	cin >> integer1 >> integer2 >> integer3;
	cout << "The largest is " << max(integer1, integer2, integer3) << endl;
	
	char ch1, ch2, ch3;
	cout << "Enter three characters: ";
	cin >> ch1 >> ch2 >> ch3;
	cout << "The largest is " << max(ch1, ch2, ch3) << endl;
	
	double f1, f2, f3;
	cout << "Enter three float numbers: ";
	cin >> f1 >> f2 >> f3;
	cout << "The largest is " << max(f1, f2, f3) << endl;
	
	return 0;
}


#include <iostream>
using std::cin;
using std::cout;
using std::endl;

template <class T>
T min(T a, T b)
{
	T min = a;
	if (min > b) {
		min = b;
	}
	return min;
}

int main()
{
	int a, b;
	cout << "Enter two integers: ";
	cin >> a >> b;
	cout << "The smaller one is: " << min(a, b) << endl;
	
	double c, d;
	cout << "Enter two float number: ";
	cin >> c >> d;
	cout << "The smaller one is: " << min(c, d) << endl;
	
	char e, f;
	cout << "Enter two charachter: ";
	cin >> e >> f;
	cout << "The smaller one is: " << min(e, f) << endl;
	
	return 0;
}


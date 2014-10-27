#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// call by value
double tripleCallByValue(double x) {
	return 3*x;
}
// call by refrence
void tripleCallByReference(double &y) {
	y *= 3;
}

int main()
{
	double count;

	cout << "Enter the number should be triple: ";
	cin >> count;
	
	cout << "Triple call by value is: " << tripleCallByValue(count) << endl;
	cout << "Triple call by reference is: ";
	tripleCallByReference(count);
	cout << count << endl;
	     
	return 0;
}


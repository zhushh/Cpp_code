#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// calculate circle area
inline double circleArea(const double r) {
	return 3.1415926*r*r;
}

int main() {
	double radius;
	cout << "Enter the radius of circle: ";
	cin >> radius;
	cout << "The area of circle with raidus " << radius << " is "
	     << circleArea(radius) << endl;
    return 0;
}


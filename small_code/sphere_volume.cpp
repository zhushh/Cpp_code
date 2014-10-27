#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cmath>
inline double sphereVolume(const double r) {
	return (4.0/3)*3.14159*pow(r, 3);
}

int main() {
	int i, n;
	double radius;
	cout << "Please enter the numbers of sphere: ";
	cin >> n;
	cout << endl;
	for (i = 1; i <= n; i++) {
		cout << "\nEnter the radius of " << i << " sphere: ";
		cin >> radius;
		cout << "Volume of sphere with radius " << radius << " is "
		     << sphereVolume(radius) << endl;
	}
	return 0;
}


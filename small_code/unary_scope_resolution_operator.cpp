#include <iostream>
using std::cout;
using std::ios;
using std::endl;
#include <iomanip>
using std::setprecision;
using std::setiosflags;
using std::setw;

const double PI = 3.14159265358979;

int main() {
	const float PI = static_cast<float>(::PI);
	cout << setprecision(20)
	     << "  Local float value of PI = " << PI
	     << "\nGlobal double value of PI = " << ::PI << endl;
    cout << setw(28) << "Local float value of PI = "
         << setiosflags(ios::fixed | ios::showpoint)
         << setprecision(10) << PI << endl;
    return 0;
}


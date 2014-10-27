#include <iostream>
#include <string>
#include <sstream>
using std::string;
using std::stringstream;
using std::cout;
using std::endl;
using std::cin;

int main() {
    string temp, pattern = "";
    stringstream ss;
    getline(cin, temp);
    ss << temp;
	// test for getline function
    while (getline(ss, temp, ' ')) {
        if (temp != pattern) cout << temp << endl;
    }
    return 0;
}


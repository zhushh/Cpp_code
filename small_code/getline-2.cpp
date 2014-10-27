#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    stringstream ss;
    string inp, w;

	// test for getline and stringstream
    getline(cin, inp);
    ss << inp;
    while (ss >> w)
        cout << w << endl;
    return 0;
}


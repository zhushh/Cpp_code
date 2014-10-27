// This program is the third edition and 
// cope with some problem in the first 
// two edition.

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
    string str, A, B;
    getline(cin, str);
    cin >> A >> B;
    string::size_type pos;
    pos = str.find(A);
    while (pos != string::npos && A != B) {
        str.replace(pos, A.size(), B);
        pos = str.find(A, ++pos);
    }
    cout << str << endl;
    return 0;
}


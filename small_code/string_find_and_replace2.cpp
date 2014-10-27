// This program is the update code for 
// the first string_find_and_replace 
// code. It deals with the special case
// that when string A and string B is 
// same which makes the program will not
// end. But this program has another 
// problem. This program will not end if
// string A is contained in string B and 
// string A is not equal to string B.

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
        pos = str.find(A);
    }
    cout << str << endl;
    return 0;
}


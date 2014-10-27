// This program have many bugs. When you input
// the string s1 is the same as string s2,
// then program process will not end. You can 
// try to modify this program to be correct.

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
    string::size_type startPosition;
    string str;
    string s1, s2;
    getline(cin, str);
    cin >> s1 >> s2;
    while ((startPosition = str.find(s1)) != string::npos)
        str.replace(startPosition, s1.size(), s2);
    cout << str << endl;
    return 0;
}



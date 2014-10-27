#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main() {
    int n, pos;
    string word;
    cin >> n;
    while (n-- > 0) {
        cin >> pos >> word;
        word.erase(word.begin() + pos - 1);
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        cout << word << endl;
    }
    return 0;
}


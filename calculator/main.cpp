#include <iostream>
#include "calculator.h"
using std::endl;

int main() {
    Calculator c;
    char str[100];
    cout << "Input a computation:" << endl;
    cin >> str;
    cout << "The result is: ";
    cout << c.getResult(str) << endl;
    return 0;
}

// wrong answer for sicily_1009
#include <iostream>
using namespace std;

long long int arr[9] = {11, 23, 29, 37, 41, 43, 47, 53, 59};

// determine primer number
bool isPrimer(long long int num) {
    for (long long int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}
// quick power
long long int power(long long int num) {
    long long int sum = 1;
    while (num > 0) {
        sum <<= 1;
        num--;
    }
    return sum - 1;
}
// output number format
void output(long long int num, long long int pow) {
    long long int n = num;
    for (long long int i = 2; i*i < num && i < n; ++i) {
        if (num % i == 0) {
            cout << i << " * ";
            if (n/i > i)
                n /= i;
        }
    }
    cout << n << " = " << num << " = ( 2 ^ ";
    cout << pow << " ) " << "- 1" << endl;
}
int main() {
    long long int n, num;
    cin >> n;
    for (int i = 0; arr[i] <= n && i < 8; ++i) {
        num = power(arr[i]);
        output(num, arr[i]);
    }
    if (n >= arr[8]) {    // especial case
        cout << "179951" << " * " << "3203431780337 = ";
        cout << "576460752303423487 = " << "( 2 ^ 59 ) - 1" << endl;
    }
    return 0;
}

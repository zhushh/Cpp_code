#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int num = 1, n, count, sum;
    int arr[10];
    while (cin >> num && num) {
        memset(arr, 0, 10*sizeof(int));
        n = num;
        count = 0;
        for (int i = 0; n != 0; ++i) {
            arr[i] = n % 10;
            n /= 10;
            count++;
        }
        sum = 0;
        for (int i = count - 1; i >= 0; --i) {
            if (arr[i] > 4)
                sum = sum * 9 + arr[i] - 1;
            else
                sum = sum * 9 + arr[i];
        }
        cout << num << ": " << sum << endl;
    }
    return 0;
}

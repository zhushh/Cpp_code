#include <iostream>
#include <valarray>
#include <algorithm>
#include <cmath>
#include <iomanip>
using std::setw;
using std::setprecision;
using std::fixed;
using std::valarray;
using std::sort;
using std::cin;
using std::cout;
using std::endl;

double result_cal(double x) {
    return x + 2 * sqrt(x);
}

int main() {
    double a[12];
    int arr[12];
    for (int i = 0; i < 12; ++i) {
        cin >> a[i];
    }
    sort(a, a+12);
    cout << "Original   Result" << endl;
    for (int i = 0; i < 12; ++i) {
        cout << fixed << setw(8) << setprecision(4) << std::right << a[i];
        cout << ": ";
        cout << fixed << setw(8) << setprecision(4) << std::right
        << result_cal(a[i]) << endl;
        arr[i] = static_cast<int>(result_cal(a[i]));
    }
    valarray<int> result(arr, 12);
    cout << "Result array:" << endl;
    for (int i = 0; i < 12;) {
        cout << setw(3) << std::right << result[i++];
        cout << setw(4) << std::right << result[i++];
        cout << setw(4) << std::right << result[i++];
        cout << endl;
    }
    cout << "Second column:" << endl;
    for (int i = 1; i < 12; i += 3) {
        cout << setw(3) << std::right << result[i];
        cout << endl;
    }
    cout << "Second row:" << endl;
    cout << setw(3) << std::right << result[3];
    cout << setw(4) << std::right << result[4];
    cout << setw(4) << std::right << result[5];
    cout << endl;
    cout << "Set last column to 10:" << endl;
    for (int i = 0; i < 12; ++i) {
        cout << setw(3) << std::right << result[i++];
        cout << setw(4) << std::right << result[i++];
        result[i] = 10;
        cout << setw(4) << std::right << result[i] << endl;
    }
    cout << "Set first column to sum of next two:" << endl;
    for (int i = 0; i < 12; ++i) {
        result[i] = result[i + 1] + result[i + 2];
        cout << setw(3) << std::right << result[i++];
        cout << setw(4) << std::right << result[i++];
        cout << setw(4) << std::right << result[i] << endl;
    }
    return 0;
}

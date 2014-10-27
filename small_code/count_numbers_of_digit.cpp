#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
    int n, i, j, k, number_count[10] = {0};
    char number_string[100];
    cin >> n;
    while (n > 0) {
        cin >> number_string;
        for (i = 0; number_string[i] >= '0' && number_string[i] <= '9'; i++) {
            k = number_string[i] - '0';
            number_count[k]++;
            for (j = i + 1; number_string[j] == number_string[j - 1]; j++) {
                number_count[k]++;
            }
            i = j - 1;
            cout << number_count[k] << k;
            number_count[k] = 0;
        }
        cout << endl;
        n--;
    }
    return 0;
}


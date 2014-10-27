#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
    int n, num, count;
    vector<int> con;
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            cin >> num;
            con.push_back(num);
        }
        count = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            for (j = 0;  j < i; ++j) {
                if (con[j] > con[i])
                    break;
            }
            if (j == i) {
                for (; j < con.size(); ++j) {
                    if (con[j] < con[i])
                        break;
                }
                if (j == con.size())
                    count++;
            }
        }
        cout << count << endl;
        con.clear();
    }
    return 0;
}
/*
#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
uisng std::endl;

int n;

bool searchable(int a[], int k) {
    for (int i = 0; i < k; ++i)
        if (a[i] > a[k])
            return false;
    for (int i = k + 1; i < n; ++i)
        if (a[i] < a[k])
            return false;
    return true;
}
int main() {
    int a[100];
    while (cin >> n) {
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (searchable(a, i))
                ans++;
        cout << ans << endl;
    }
    return 0;
}

*/

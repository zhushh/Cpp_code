// 输入n 个整数，每个整数小于1000 
// 输出由这n个整数构成称的最大数字 
// 输入行有两行，第一行为整数个数n，第二行为n个整数(空格隔开) 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

// compare function for sort
bool compare(string a, string b) {
    return a + b > b + a;    // decreasing sequence
}
int main() {
    int n;
    string num;
    vector<string> arr;
    vector<string>::iterator it;
    cin >> n;
    while (n-- > 0) {
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end(), compare);
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i];
    }
    cout << endl;
    return 0;
}


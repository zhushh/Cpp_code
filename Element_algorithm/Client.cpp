#include <iostream>
#include <cstdio>
#include <string>
#include "MidToLast.h"
using std::cin;
using std::cout;
using std::endl;
int main() {
    char c;
    string nifix, postfix;
    int answer, T;
    cin >> T;
    getchar();
    for (int cas = 1; cas <= T; cas++) {
        cin >> nifix;
        MidToLast mtl;
        postfix = mtl.transfer(nifix);
        answer = mtl.calculate(postfix);
        cout << "Case " << cas << ":" << endl;
        cout << "Postfix Expression : " << postfix << ' ' << endl;
        cout << "XueZha finally calculated : " << answer << endl;
    }
    return 0;
}


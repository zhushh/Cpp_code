#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "Matrix.h"

using std::cout;
using std::cin;
int main() {
    Matrix m(0, 13);
    cout << m;

    char c;
    while (c = getch()) {
        bool flag = false;
        if (c == '0') break;
        switch (c) {  // a, d, w, s stand for left, right, up and down
            case 'A':
            case 'a': flag = m.moveLeft(); break;
            case 'D':
            case 'd': flag = m.moveRight(); break;
            case 'W':
            case 'w': flag = m.moveUp(); break;
            case 'S':
            case 's': flag = m.moveDown(); break;
            default: break;
        }
        if (flag) {  // if the matrix changes, add a 2 to the matrix
            m.update2();
        }
        // system("cls")
        system("cls");
        cout << m;
    }
    return 0;
}


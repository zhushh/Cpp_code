#include "Matrix.h"
#include <iostream>
#include <deque>

using std::ostream;
using std::deque;
using std::endl;

// constructor and initialize
Matrix::Matrix(int p1, int p2) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            num[i][j] = 0;
        }
    }
    num[p1/4][p1%4] = 2;
    num[p2/4][p2%4] = 2;
}
// move left
bool Matrix::moveLeft() {  // return true if the matrix changes
    bool flag = false;
    deque<int> mydeque;
    for (int i = 0; i < rows; ++i) {
        // copy the row to a deque to cope
        for (int j = 0; j < cols; ++j) {
            if (num[i][j] != 0) mydeque.push_back(num[i][j]);
        }
        // cope the deque
        for (int k = 0; k < mydeque.size(); ++k) {
            if (k + 1 < mydeque.size() && mydeque[k] == mydeque[k+1]) {
                mydeque[k+1] += mydeque[k];
                mydeque.erase(mydeque.begin() + k);
                flag = true;
            }
        }
        // array reassignment
        for (int j = 0; j < cols; ++j) {
            if (!mydeque.empty()) {
                if (num[i][j] != mydeque.front()) flag = true;
                num[i][j] = mydeque.front();
                mydeque.pop_front();
            } else {
                num[i][j] = 0;
            }
        }
    }
    return flag;
}
// move right
bool Matrix::moveRight() {  // return true if the matrix changes
    bool flag = false;
    deque<int> mydeque;
    for (int i = 0; i < rows; ++i) {
        // cope each row to deque to cope
        for (int j = cols - 1; j >= 0; --j) {
            if (num[i][j] != 0) mydeque.push_back(num[i][j]);
        }
        // cope the deque
        for (int k = 0; k < mydeque.size(); ++k) {
            if (k + 1 < mydeque.size() && mydeque[k] == mydeque[k+1]) {
                mydeque[k+1] += mydeque[k];
                mydeque.erase(mydeque.begin() + k);
                flag = true;
            }
        }
        // array reassignment
        for (int j = cols - 1; j >= 0; --j) {
            if (!mydeque.empty()) {
                if (num[i][j] != mydeque.front()) flag = true;
                num[i][j] = mydeque.front();
                mydeque.pop_front();
            } else {
                num[i][j] = 0;
            }
        }
    }
    return flag;
}
// move up
bool Matrix::moveUp() {  // return true if the matrix changes
    bool flag = false;
    deque<int> mydeque;
    for (int i = 0; i < cols; ++i) {
        // copy each column to deque to cope
        for (int j = 0; j < rows; ++j) {
            if (num[j][i] != 0) mydeque.push_back(num[j][i]);
        }
        // cope the deque
        for (int k = 0; k < mydeque.size(); ++k) {
            if (k + 1 < mydeque.size() && mydeque[k] == mydeque[k+1]) {
                mydeque[k+1] += mydeque[k];
                mydeque.erase(mydeque.begin() + k);
                flag = true;
            }
        }
        // array reassignment
        for (int j = 0; j < rows; ++j) {
            if (!mydeque.empty()) {
                if (num[j][i] != mydeque.front()) flag = true;
                num[j][i] = mydeque.front();
                mydeque.pop_front();
            } else {
                num[j][i] = 0;
            }
        }
    }
    return flag;
}
// move down
bool Matrix::moveDown() {  // return true if the matrix changes
    bool flag = false;
    deque<int> mydeque;
    for (int i = 0; i < cols; ++i) {
        // copy each column to deque to cope
        for (int j = rows - 1; j >= 0; --j) {
            if (num[j][i] != 0) mydeque.push_back(num[j][i]);
        }
        // cope the deque
        for (int k = 0; k < mydeque.size(); ++k) {
            if (k + 1 < mydeque.size() && mydeque[k] == mydeque[k+1]) {
                mydeque[k+1] += mydeque[k];
                mydeque.erase(mydeque.begin() + k);
                flag = true;
            }
        }
        // array reassignment
        for (int j = rows - 1; j >= 0; --j) {
            if (!mydeque.empty()) {
                if (num[j][i] != mydeque.front()) flag = true;
                num[j][i] = mydeque.front();
                mydeque.pop_front();
            } else {
                num[j][i] = 0;
            }
        }
    }
    return flag;
}
// add a new element
bool Matrix::add(int p) {  // return true if the matrix changes
    if (num[p/4][p%4] > 0) return false;
    else num[p/4][p%4] = 2;
    return true;
}
// output the matrix
ostream& operator<<(ostream& out, const Matrix& matrix) {
    out << "-----------------------------" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            out << '|';
            if (matrix.num[i][j] == 0) {
                out << "      ";
            } else if (matrix.num[i][j] > 0 && matrix.num[i][j] <= 9) {
                out << "     " << matrix.num[i][j];
            } else if (matrix.num[i][j] >= 10 && matrix.num[i][j] <= 99) {
                out << "    " << matrix.num[i][j];
            } else if (matrix.num[i][j] >= 100 && matrix.num[i][j] <= 999) {
                out << "   " << matrix.num[i][j];
            } else if (matrix.num[i][j] >= 1000 && matrix.num[i][j] <= 9999) {
                out << "  " << matrix.num[i][j];
            } else if (matrix.num[i][j] >= 10000 && matrix.num[i][j] <= 99999) {
                out << " " << matrix.num[i][j];
            } else {
                out << matrix.num[i][j];
            }
        }
        out << '|' << endl;
        out << "-----------------------------" << endl;
    }
    return out;
}


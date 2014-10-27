#include "MidToLast.h"
#include "stack.h"
#include <iostream>
#include <string>
using namespace std;
bool is_number(char c) {
    if (c >= '0' && c <= '9') return true;
    return false;
}
bool is_add_sub(char c) {
    if (c == '+' || c == '-') return true;
    return false;
}
bool is_mul_dvd(char c) {
    if (c == '/' || c == '*') return true;
    return false;
}
string MidToLast::transfer(string str) {
    Stack temp, q;
    string ss = "";
    for (int i = str.length() - 1; i >= 0; --i) {
        q.push(str[i]);
    }
    while (!q.empty()) {
        if (is_number(q.top())) {
            ss += q.top();
            q.pop();
        } else {
            if (temp.empty()) {
                temp.push(q.top());
                q.pop();
            } else if (q.top() == '(') {
                temp.push(q.top());
                q.pop();
            } else if (is_add_sub(q.top())) {
                while (!temp.empty() && temp.top() != '(') {
                    ss += temp.top();
                    temp.pop();
                }
                temp.push(q.top());
                q.pop();
            } else if (is_mul_dvd(q.top())) {
                while (is_mul_dvd(temp.top()) && !temp.empty()) {
                    ss += temp.top();
                    temp.pop();
                }
                temp.push(q.top());
                q.pop();
            } else if (q.top() == ')') {
                while (temp.top() != '(') {
                    ss += temp.top();
                    temp.pop();
                }
                temp.pop();
                q.pop();
            }
        }
    }
    while (!temp.empty()) {
        ss += temp.top();
        temp.pop();
    }
    return ss;
}


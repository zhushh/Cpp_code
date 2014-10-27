#include "MidToLast.h"
#include <string>
#include <stack>
using namespace std;

int append(string& midExp, string& exp, int pos) {
    stack<char> m;
    int i;
    for (i = pos; i < exp.size(); ++i) {
        if (exp[i] == ')') {
            while (!m.empty()) {
                midExp += m.top();
                m.pop();
            }
            return i;
        }
        if (exp[i] != '(') {
            if (exp[i] >= '0' && exp[i] <= '9') {
                midExp += exp[i];
            } else if (m.empty()) {
                m.push(exp[i]);
            } else {
                if (exp[i] == '+' || exp[i] == '-') {
                    while (!m.empty()) {
                        midExp += m.top();
                        m.pop();
                    }
                }
                if (exp[i] == '*' || exp[i] == '/' || exp[i] == '%') {
                    if (m.top() == '*' || m.top() == '/' || m.top() == '%') {
                        midExp += m.top();
                        m.pop();
                    }
                }
                m.push(exp[i]);
            }
        } else {
            i = append(midExp, exp, ++i);
        }
    }
    while (!m.empty()) {
        midExp += m.top();
        m.pop();
    }
    return i;
}
string MidToLast::transfer(string exp) {
    string midExp = "";
    int temp = append(midExp, exp, 0);
    return midExp;
}
int MidToLast::calculate(string postfix) {
    int num1, num2;
    stack<int> m;
    for (int i = 0; i < postfix.size(); ++i) {
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            m.push(postfix[i] - '0');
        } else {
            num1 = m.top();
            m.pop();
            num2 = m.top();
            m.pop();
            if (postfix[i] == '+')
                m.push(num1 + num2);
            if (postfix[i] == '*')
                m.push(num1 * num2);
            if (postfix[i] == '-')
                m.push(num2 - num1);
            if (postfix[i] == '/')
                m.push(num2 / num1);
            if (postfix[i] == '%')
                m.push(num2 % num1);
        }
    }
    return m.top();
}

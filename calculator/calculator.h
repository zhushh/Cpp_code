#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <stack>
#include <cstring>
#include <cctype>
using std::stack;
using std::cin;
using std::cout;

int select_op_cal(int num1, int num2, char op) {
    if (op == '+')
        return num1 + num2;
    if (op == '*')
        return num1 * num2;
    if (op == '-')
        return num1 - num2;
    if (op == '/')
        return num1 / num2;
    if (op == '%')
        return num1 % num2;
    return 0;    // return if unmatch
}

class Calculator {
    public:
        void cal_operator() {    // calculate top operator
            int num1, num2;
            num2 = num_.top();
            num_.pop();
            num1 = num_.top();
            num_.pop();
            num_.push(select_op_cal(num1, num2, op_.top()));
            op_.pop();
        }
        int calculate(char *exp) {
            int number, num1;
            unsigned int len = strlen(exp);
            for (unsigned int i = 0; i < len; ++i) {
                if (isdigit(exp[i])) {
                    number = exp[i] - '0';
                    while (++i < len && isdigit(exp[i])) {
                        number = number * 10 + exp[i] - '0';
                    }
                    --i;    // avoid operator is omited
                    if (!op_.empty() &&  // must determine if op_ is empty
                        (op_.top() == '*' || op_.top() == '/')) {
                        num1 = num_.top();
                        num_.pop();
                        num_.push(select_op_cal(num1, number, op_.top()));
                        op_.pop();
                    } else {
                        num_.push(number);
                    }
                } else if (exp[i] == ')') {  // special case about brace
                    while (op_.top() != '(') {
                        cal_operator();
                    }
                    op_.pop();
                } else {
                    if ((exp[i] == '+' || exp[i] == '-') && !op_.empty()
                        && (op_.top() == '+' || op_.top() == '-')) {
                        cal_operator();
                    }
                    op_.push(exp[i]);
                }
            }
            while (!op_.empty()) {
                cal_operator();
            }
            return num_.top();
        }
        int getResult(char *exp) {
            return calculate(exp);
        }
    private:
        stack<int> num_;
        stack<char> op_;
};

#endif

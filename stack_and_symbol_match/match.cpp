#include "stack.h"
#include "match.h"
#include <iostream>
#include <cstring>
using namespace std;
bool Match::isMatch(char *s) {
    Stack temp;
    int len = strlen(s);
    char c;
    bool big = false, mid = false, small = false;
    // push and pop from stack.
    for (int i = 0; i < len; ++i) {
        if (*(s + i) == '{' && big == false) {
            temp.push(*(s + i));
            big = true;
        } else if (*(s + i) == '[' && mid == false) {
            temp.push(*(s + i));
            mid = true;
        } else if (*(s + i) == '(' && small == false) {
            temp.push(*(s + i));
            small = true;
        } else if (*(s + i) == '{' || *(s + i) == '[' || *(s + i) == '(') {
            temp.push(*(s + i));
        } else if (temp.getSize()) {
            if (temp.top() == '{' && *(s + i) == '}') {
                c = temp.pop();
            } else if (temp.top() == '[' && *(s + i) == ']') {
                c = temp.pop();
            } else if (temp.top() == '(' && *(s + i) == ')') {
                c = temp.pop();
            } else {
                return false;
            }
        } else if (*(s + i) == '}' || *(s + i) == ']' || *(s + i) == ')') {
            return false;
        }
    }
    if (temp.getSize() != 0) {
		return false;
    } else {
		return true;
    }
}


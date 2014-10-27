#include "stack.h"
#include <iostream>
using namespace std;
Stack::Stack() {
    size = 0;
    for (int i = 0; i < 200; ++i) {
        base[i] = '\0';
    }
}
void Stack::push(char c) {
    if (size + 1 <= 200) {
        base[size] = c;
        ++size;
    }
}
char Stack::pop() {
    if (!isEmpty()) {
        char c;
        c = top();
        base[getSize()] = '\0';
        --size;
        return c;
    }
}
char Stack::top() const {
    return base[getSize() - 1];
}
bool Stack::isEmpty() const {
    if (size == 0) return true;
    else return false;
}
void Stack::clear() {
    while (size > 0) {
        base[size - 1] = '\0';
        --size;
    }
}
int Stack::getSize() const {
    return size;
}


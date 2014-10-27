#ifndef MYSTACK_H
#define MYSTACK_H

#include "myList.h"

template<class T>
class Stack {
   public:
       Stack() {}
       ~Stack() {}
       void push(const T& c) {
           li.push_back(c);
       }
       void pop() {
           li.pop_back();
       }
       T& top() {
           return li.back();
       }
       bool empty() {
           return li.empty();
       }
       size_t size() {
           return li.size();
       }
    private:
        list<T> li;
};

#endif


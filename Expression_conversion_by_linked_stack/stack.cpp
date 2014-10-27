#include "stack.h"
#include <iostream>
using namespace std;
Stack::Stack() {
    top_node = NULL;
    count = 0;
}
bool Stack::empty() const {
    if (count == 0) {
        return true;
    } else {
        return false;
    }
}
void Stack::push(const char item) {
    if (top_node == NULL) {
        top_node = new Node;
        top_node->entry = item;
        count++;
    } else {
        Node *temp;
        temp = new Node;
        temp->entry = item;
        temp->next = top_node;
        top_node = temp;
        count++;
    }
}
void Stack::pop() {
    if (!empty()) {
        Node *temp;
        temp = top_node;
        top_node = top_node->next;
        delete temp;
        count--;
    }
}
char Stack::top() const {
    if (!empty())
        return top_node->entry;
}
int Stack::size() const {
    return count;
}


#include "queue.h"
#include <iostream>
using namespace std;
Queue::Queue() {
    count = 0;
    front = NULL;
    rear = NULL;
}
bool Queue::empty() const {
    if (count == 0) {
        return true;
    } else {
        return false;
    }
}
void Queue::push(const int item) {
    if (front == NULL) {
        front = new Node;
        front->data = item;
    } else if (rear == NULL) {
        rear = new Node;
        front->next = rear;
        rear->data = item;
    } else {
        Node *p;
        p = new Node;
        rear->next = p;
        p->data = item;
        rear = p;
    }
    count++;
}
int Queue::getFront() {
    return front->data;
}
void Queue::pop() {
    Node *p;
    p = front;
    front = front->next;
    delete p;
    count--;
}
int Queue::getSize() {
    return count;
}


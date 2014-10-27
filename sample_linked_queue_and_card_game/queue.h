#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;
struct Node {
	int data;
	Node *next;
	Node() {
		next = NULL;
	}
};
class Queue {
	public:
		Queue();
		bool empty() const;
		void push(const int item);
		int getFront();
		void pop();
		int getSize();
	protected:
		Node *front, *rear;
		int count;
};

#endif


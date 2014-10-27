#include "card.h"
#include "queue.h"
#include <iostream>
using namespace std;
void Card::printCard(int x) {
    Queue q;
    for (int i = 1; i <= x; ++i) {
        q.push(i);
    }
    while (q.getSize() > 2) {
        cout << q.getFront() << " ";
        q.pop();
        if (!q.empty()) {
            q.push(q.getFront());
            q.pop();
        }
    }
    while (!q.empty()) {
        cout << q.getFront();
        q.pop();
        if (q.empty()) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
}


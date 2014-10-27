#ifndef OBSERVER_H
#define OBSERVER_H

#include <algorithm>
#include <vector>
using std::vector;
using std::remove;
using std::cout;
using std::cin;
using std::endl;

class Observer {
    public:
        virtual ~Observer() {}
        virtual void notify() = 0;
        char name;
};

class ObserverA : public Observer {
    public:
        ObserverA() { name = 'A' + count1++; }
        void notify() {
            cout << "ObserverA is notified that Subject change." << endl;
        }
    private:
        static int count1;
};
int ObserverA::count1 = 0;

class ObserverB : public Observer {
    public:
        ObserverB() { name = 'a' + count2++; }
        void notify() {
            cout << "ObserverB is notified that Subject change." << endl;
        }
    private:
        static int count2;
};
int ObserverB::count2 = 0;

class Subject : public ObserverA, public ObserverB {
    public:
        Subject() : ObserverA(), ObserverB() {}
        void registerObserver(Observer *t) {
            mem.push_back(t->name);
        }
        void unregisterObserver(Observer *t) {
            vector<char>::iterator it;
            it = mem.begin();
            for (; it != mem.end(); ++it) {
                if (*it == t->name) break;
            }
            mem.erase(it);
        }
        void notifyObserver() {
            vector<char>::iterator it;
            it = mem.begin();
            for (; it != mem.end(); ++it) {
                if ((*it) >= 'a' && (*it) <= 'z') ObserverB::notify();
                else ObserverA::notify();
            }
        }
    private:
        vector<char> mem;
};
#endif


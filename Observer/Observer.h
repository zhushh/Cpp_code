#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;

class Observer {
    public:
        virtual ~Observer() {}
        virtual void notify() = 0;
};

class ObserverA : public Observer {
    public:
        ObserverA() {}
        void notify() {
            cout << "ObserverA is notified that Subject change." << endl;
        }
};

class ObserverB : public Observer {
    public:
        ObserverB() {}
        void notify() {
            cout << "ObserverB is notified that Subject change." << endl;
        }
};

class Subject {
    public:
        Subject() {}
        void registerObserver(Observer *t) {
            object.push_back(t);
        }
        void unregisterObserver(Observer *t) {
            vector<Observer *>::iterator it = object.begin();
            for (; it != object.end(); ++it) {
                if (*it == t) break;
            }
            object.erase(it);
        }
        void notifyObserver() {
            for (int i = 0; i < object.size(); ++i) {
                object[i]->notify();
            }
        }
    private:
        vector<Observer *> object;
};

#endif




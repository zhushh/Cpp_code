#include "DouList.h"
#include <iostream>
#include <cstdio>
#include <string>

using std::string;
using std::endl;
using std::cout;
using std::ostream;

DouList::DouList() {
    _head = NULL;
    _tail = NULL;
}
DouList::DouList(const DouList &src) {
    _head = _tail = NULL;
    *this = src;
}
DouList::~DouList() {
    clear();
}
void DouList::clear() {
    DouListNode *temp;
    while (_head != NULL) {
        temp = _head;
        _head = _head->next;
        if (temp->sublist != NULL) {
            delete temp->sublist;   // 调用clear()有内存问题~~ 
            temp->sublist = NULL;
        }
        if (temp != NULL) delete temp;
    }
    _tail = NULL;
}
bool DouList::empty() const {
    if (_head != NULL) return false;
    else return true;
}
string DouList::to_str() const {
    char s[20];
    string str = "[";
    DouListNode *temp = _head;
    while (temp != NULL) {
        // sublist 和 elem 指输出一个  
        if (temp->sublist != NULL) str += temp->sublist->to_str();
        else if (snprintf(s, sizeof(s), "%d", temp->elem) != 0) str += s;
        if (temp != _tail) str += ", ";
        temp = temp->next;
    }
    str += "]";
    return str;
}
DouList DouList::front() const {
    DouList temp;  // attention！如果声明指针，会导致无法删除掉那部分的内存问题 
    if (_head != NULL) {
        if (_head->sublist) temp = *(_head->sublist);
        else temp.push_front(_head->elem);
    }
    return temp;
}
DouList DouList::back() const {
    DouList temp;  // attention！如果声明指针，会导致无法删除掉那部分的内存问题 
    if (_tail != NULL && _tail->sublist != NULL) {
        temp = *(_tail->sublist);
        return temp;
    } else if (_tail != NULL) {
        temp.push_back(_tail->elem);
    }
    return temp;
}
void DouList::push_front(const DouListNode &e) {
    if (_head == NULL && _tail == NULL) {
        _head = _tail = new DouListNode;
    } else {
        _head->prev = new DouListNode;
        _head->prev->next = _head;
        _head = _head->prev;
    }
    _head->elem = e.elem;
    if (e.sublist != NULL) {
        _head->sublist = new DouList;   // 指针使用时必须要有内存空间 
        *(_head->sublist) = *(e.sublist);
    }
}
void DouList::push_back(const DouListNode &e) {
    if (_tail == NULL && _head == NULL) {
        _tail = _head = new DouListNode;
    } else {
        _tail->next = new DouListNode;
        _tail->next->prev = _tail;
        _tail = _tail->next;
    }
    _tail->elem = e.elem;
    if (e.sublist != NULL) {
        _tail->sublist = new DouList;   // 指针使用时必须要有内存空间 
        *(_tail->sublist) = *(e.sublist);
    }
}
void DouList::pop_front() {
    if (_head != NULL) {
        DouListNode *temp = _head;
        _head = _head->next;
        if (_head == NULL) _tail = NULL;
        else _head->prev = NULL;
        if (temp->sublist != NULL) {
            delete temp->sublist;   // 调用clear()函数会有内存问题 
            temp->sublist = NULL;
        }
        if (temp != NULL) delete temp;
    }
}
void DouList::pop_back() {
    if (_tail != NULL) {
        DouListNode *temp = _tail;
        _tail = _tail->prev;
        if (_tail == NULL) _head = NULL;
        else _tail->next = NULL;
        if (temp->sublist != NULL) {
            delete temp->sublist;   // 调用clear()函数会有内存问题 
            temp->sublist = NULL;
        }
        if (temp != NULL) delete temp;
    }
}
void DouList::operator=(const DouList &other) {
    if (_head != NULL) clear();
    if (other.empty()) return;
    DouListNode *temp = other._head;
    while (temp != NULL) {
        push_back(*temp);
        temp = temp->next;
    }
}
DouList::operator int() {
    if (_head !=  NULL) return _head->elem;
    else return 0;
}
ostream& operator<<(ostream &out, const DouList &list) {
    string s = list.to_str();
    out << s;
    return out;
}


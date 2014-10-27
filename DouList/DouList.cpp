#include "DouList.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;

DouList::DouList() {
    m_head = NULL;
    m_tail = NULL;
}
DouList::DouList(const DouList &src) {
    m_head = m_tail = NULL;
    if (m_head != NULL) {
        clear();
    }
    DouListNode *temp = src.m_head;
    while (temp != NULL) {
        push_back(temp->elem);
        temp = temp->next;
    }
}
DouList::~DouList() {
    clear();
}
void DouList::clear() {
    DouListNode *temp;
    while (m_head != NULL) {
        temp = m_head;
        m_head = m_head->next;
        delete temp;
    }
    m_tail = NULL;
}
bool DouList::empty() const {
    if (m_head == NULL && m_tail == NULL) return true;
    else return false;
}
string DouList::to_str() const {
    char num[10];
    string s = "[";
    DouListNode *temp = m_head;
    while (temp != NULL) {
        snprintf(num, sizeof(num), "%d", temp->elem);
        s += num;
        if (temp != m_tail) s += ", ";
        temp = temp->next;
    }
    s += "]";
    return s;
}
int DouList::front() const {
    if (m_head != NULL) return m_head->elem;
}
int DouList::back() const {
    if (m_tail != NULL) return m_tail->elem;
}
void DouList::push_front(const int &e) {
    if (m_head == NULL) {
        m_tail = new DouListNode;
        m_head = m_tail;
        m_head->elem = e;
    } else {
        DouListNode *temp = new DouListNode;
        temp->elem = e;
        temp->next = m_head;
        m_head->prev = temp;
        m_head = temp;
    }
}
void DouList::push_back(const int &e) {
    if (m_tail == NULL) {
        m_head = new DouListNode;
        m_tail = m_head;
        m_tail->elem = e;
    } else {
        DouListNode *temp = new DouListNode;
        temp->elem = e;
        temp->prev = m_tail;
        m_tail->next = temp;
        m_tail = temp;
    }
}
void DouList::pop_front() {
    if (m_head == m_tail && m_head != NULL) {
        delete m_head;
        m_tail = m_head = NULL;
    } else if (m_head != NULL) {
        DouListNode *temp = m_head;
        m_head->next->prev = NULL;
        m_head = m_head->next;
        delete temp;
    }
}
void DouList::pop_back() {
    if (m_tail == m_head && m_tail != NULL) {
        delete m_tail;
        m_head = m_tail = NULL;
    } else if (m_tail != NULL) {
        DouListNode *temp = m_tail;
        m_tail->prev->next = NULL;
        m_tail = m_tail->prev;
        delete temp;
    }
}
void DouList::operator=(const DouList &other) {
    if (m_head != NULL) {
        clear();
    }
    DouListNode *temp = other.m_head;
    while (temp != NULL) {
        push_back(temp->elem);
        temp = temp->next;
    }
}
ostream& operator<<(ostream &out, const DouList &list) {
    DouListNode *temp = list.m_head;
    out << "[";
    while (temp != NULL) {
        out << temp->elem;
        if (temp != list.m_tail) out << ", ";
        temp = temp->next;
    }
    out << "]";
    return out;
}
// non-meaning static value
int DouList::_error_sign = 0;


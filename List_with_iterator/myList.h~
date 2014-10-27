#ifndef LIST_H
#define LIST_H
#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

template <class T>
class list {
    public:
        struct listelem;  // forward declarations
        class iterator;
        list() { t.ptr = h.ptr = new listelem(0); }
        list(size_t n_elements, const T& c) {
            h.ptr = t.ptr = new listelem(0);
            while (n_elements-- > 0) {
                push_back(c);
            }
        }

        list(const list& x) {
            h.ptr = t.ptr = new listelem(0);
            iterator tp(x.h);
            while (tp != x.end()) {
                push_back(*tp);
                ++tp;
            }
        }

        list(iterator b, iterator e) {
            h.ptr = t.ptr = new listelem(0);
            iterator tp(b);
            while (tp != e) {
                push_back(*tp);
                ++tp;
            }
        }

        ~list() {
            this->clear();
            delete h.ptr;
            h.ptr = t.ptr = 0;
        }

        iterator begin() const {
            if ((h.ptr)->prev == 0) return h;
            iterator tp(h);
            return tp;
        }

        iterator end() const {
            if ((h.ptr)->prev == 0) return t;
            iterator tp = t;
            return ++tp;
        }

        size_t size() {
            if ((h.ptr)->prev == 0) return 0;
            size_t count = 1;
            iterator tp(h);
            while (tp.ptr != t.ptr) {
                ++count;
                ++tp;
            }
            return count;
        }

        void push_front(const T& c) {
            iterator tp(new listelem(c));
            if (size() == 0) {
                h->prev = t->next = tp;
                tp->prev = tp->next = h;
                h.ptr = t.ptr = tp.ptr;
            } else {
                tp->prev = h->prev;
                tp->next = h;
                h->prev->next = tp;
                h->prev = tp;
                h = tp;
            }
        }

        void push_back(const T& c) {
            iterator tp(new listelem(c));
            if (size() == 0) {
                h->prev = t->next = tp;
                tp->prev = tp->next = h;
                h.ptr = t.ptr = tp.ptr;
            } else {
                tp->prev = t;
                tp->next = t->next;
                t->next->prev = tp;
                t->next = tp;
                t = tp;
            }
        }

        void pop_front() {
            erase(h);
        }

        void pop_back() {
            erase(t);
        }

        iterator insert(iterator position, const T& val) {
            iterator tp(new listelem(val));
            if (size() == 0) {  // deal special case if size is 0
                h->prev = t->next = tp;
                tp->prev = tp->next = h;
                h.ptr = t.ptr = tp.ptr;
                return h;
            }
            if (position == end()) {  // if insert in the end
                tp->prev = t;
                tp->next = t->next;
                t->next->prev = tp;
                t->next = tp;
                t = tp;
                return t;
            }
            if (size() == 1) {
                if (position == h) h = tp;
                else if (position == t) t = tp;
            } else {
                if (position == h) h = tp;
                if (position == t) t = tp;
            }
            position->prev->next = tp;
            tp->prev = position->prev;
            tp->next = position;
            position->prev = tp;
            position.ptr = tp.ptr;
            return position;
        }

        iterator erase(iterator position) {
            bool flag = false;
            if (size() == 0) return position;
            if (size() == 1) flag = true;
            if (position == h) h.ptr = h->next;
            if (position == t) t.ptr = t->prev;
            list<T>::iterator tp(position);
            position->prev->next = position->next;
            position->next->prev = position->prev;
            position.ptr = position->next;
            delete tp;
            if (flag) h->next = t->prev = 0;
            return position;
        }

        bool empty() const {
            if ((h.ptr)->prev == 0) return true;
            else return false;
        }
        T& front() {
            return *h;
        }

        T& back() {
            return *t;
        }

        void clear() {
            while (!empty()) {
                erase(h);
            }
        }

        friend ostream& operator<<(ostream& out, const list<T>& x) {
            list<T>::iterator tp(x.h);
            out << "[ ";
            for (; tp != x.end() && tp != 0; ++tp) {
                out << *tp << ' ';
            }
            out << "]";
            return out;
        }

        struct listelem {
            T data;
            listelem *next, *prev;
            listelem(const T& s, listelem *n = 0, listelem *p = 0)
                : next(n), prev(p) {  // using initialization lists
                data = s;
            }
        };

        class iterator {
            public:
                friend class list;  // friend
                explicit iterator(listelem *p = 0) : ptr(p) {}

                iterator(const iterator& other) : ptr(other.ptr) {}
                iterator& operator++() {  // prefix
                    if (ptr != 0 && ptr->next != 0)
                        ptr = ptr->next;
                    return *this;
                }
                iterator& operator--() {  // prefix
                    if (ptr != 0 && ptr->prev != 0)
                        ptr = ptr->prev;
                    return *this;
                }
                iterator operator++(int) {  // postfix
                    iterator temp(*this);
                    ++(*this);
                    return temp;
                }
                iterator operator--(int) {  // postfix
                    iterator temp(*this);
                    --(*this);
                    return temp;
                }
                listelem* operator->() {  // pointer operation
                    return ptr;
                }
                T& operator * () {   // get type_value
                    if (ptr != 0) return ptr->data;
                }

                // u can use iterator as listelem * sometimes
                operator listelem * () { return ptr; }  // conversion;

            private:
                listelem* ptr;  // current listelem or 0;
        };
    private:
        iterator h, t;  // head and tail
};

#endif


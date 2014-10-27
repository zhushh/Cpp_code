#include "vector.h"
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

template <typename T>
Vector < T >::Vector(int s) {
    maxSize = s;
    _size = 0;
    data = NULL;
}
template <typename T>
Vector < T >::~Vector() {
    if (_size) delete []data;
    _size = 0;
    maxSize = 0;
    data = NULL;
}
template <typename T>
Vector < T >::Vector(const Vector<T>& v) {
    maxSize = v.maxSize;
    _size = v._size;
    if (maxSize > 0) data = new T[v.maxSize];   // error
    for (int i = 0; i < _size; ++i) {
        data[i] = v.data[i];
    }
}
template <typename T>
int Vector < T >::size() const {
    return _size;
}
template <typename T>
bool Vector < T >::empty() const {
    if (_size > 0) return false;
    else return true;
}
template <typename T>
void Vector < T >::clear() {
    if (_size > 0) delete []data;
    _size = 0;
}
template <typename T>
void Vector < T >::push_back(T ele) {
    if (_size == 0) {
        if (maxSize > 0 && data == NULL) data = new T[maxSize];
    } else if (_size == maxSize) {
        T *temp = new T[maxSize];
        for (int i = 0; i < _size; ++i) {
            *(temp + i) = *(data + i);
        }
        delete []data;
        maxSize = 2*maxSize;
        data = new T[maxSize];
        for (int i = 0; i < _size; ++i) {
            *(data + i) = *(temp + i);
        }
        delete []temp;
    }
    if (data != NULL) data[_size++] = ele;
}
template <typename T>
void Vector < T >::pop_back() {
    if (_size <= 0) return;
    _size -= 1;
    *(data + _size) = 0;
}
template <typename T>
T& Vector < T >::operator[](int index) {
    return *(data + index);
}
template <typename T>
Vector<T>& Vector < T >::operator =(const Vector<T>& v) {
    Vector < T > *temp;
    temp = new Vector < T >;
    temp->maxSize = v.maxSize;
    for (int i = 0; i < v._size; ++i) temp->push_back(v.data[i]);
    return *temp;
}
template <typename sT>
ostream& operator << (ostream &out, const Vector<sT> &v) {
    if (v._size) {
        for (int i = 0; i < v._size; ++i) {
            out << v.data[i];
            (i < v._size - 1) ? out << " " : out << endl;
        }
    } else {
        out << "\n";
    }
    return out;
}


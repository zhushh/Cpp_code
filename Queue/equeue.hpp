#include <iostream>
#include "equeue.h"

template <class T>
Queue<T>::Queue() : count_(0), size_(0), ptrf_(0), ptrb_(0) {
    frontBlock_ = backBlock_ = NULL;
}
template <class T>
Queue<T>::~Queue() {
    this->clear();
}
template <class T>
void Queue<T>::clear() {
    while (frontBlock_ != backBlock_)
        reduceBlock();
    delete frontBlock_;  // delete when fronBlock_ is not empty
    frontBlock_ = backBlock_ = NULL;
    size_ = 0;
    ptrf_ = ptrb_ = 0;
}
template <class T>
bool Queue<T>::empty() const {
    if (size_ <= 0)
        return true;
    return false;
}
template <class T>
int Queue<T>::size() const {
    return size_;
}
template <class T>
T Queue<T>::front() const {
    return frontBlock_->dat[ptrf_];
}
template <class T>
void Queue<T>::push(const T& num) {
    if (frontBlock_ == NULL) {  // determine if the object is empty
        frontBlock_ = new MemBlock<T>;
        backBlock_ = frontBlock_;
    }
    if (ptrb_ == 1024)    // add a MemBlock if memory isn't enough
        appendBlock();
    backBlock_->dat[ptrb_++] = num;
    size_++;
}
template <class T>
T Queue<T>::pop() {
    if (!empty()) {
        size_--;
        if (ptrf_ == 1023) {  // determine if ptr point to end
            T temp = frontBlock_->dat[ptrf_];
            reduceBlock();
            return temp;
        }
        return frontBlock_->dat[ptrf_++];  // normally return
    }
    return 0;
}
template <class T>
void Queue<T>::appendBlock() {
    backBlock_->next = new MemBlock<T>;
    backBlock_->next->prev = backBlock_;
    backBlock_ = backBlock_->next;
    ptrb_ = 0;
}
template <class T>
void Queue<T>::reduceBlock() {
    MemBlock<T> *ptr = frontBlock_;
    frontBlock_ = frontBlock_->next;
    delete ptr;
    ptrf_ = 0;
}
template <class T>
void Queue<T>::reset() {
    this->clear();
}

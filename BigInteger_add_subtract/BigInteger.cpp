#include "BigInteger.h"
#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::istream;

class BigInteger;

BigInteger::BigInteger() {
    size_ = 0;
    flag_ = true;
    data_ = NULL;
    MAX_ = 300;
}
BigInteger::BigInteger(const string& number) {
    int i, j;
    MAX_ = 300;
    size_ = number.length();
    data_ = new int[MAX_];
    for (i = 0; i < size_; ++i) data_[i] = 0;   // initialize data_
    for (i = number.length() - 1, j = 0; i > 0; --i, ++j) {
        data_[j] = number[i] - '0';
    }
    if (number[0] == '-') {
        flag_ = false;
        --size_;
    } else {
        data_[j] = number[0] - '0';
    }
}
BigInteger::BigInteger(const BigInteger& other) {
    int i;
    MAX_ = 300;
    size_ = other.size_;
    flag_ = other.flag_;
    data_ = new int[MAX_];
    for (i = 0; i < size_; ++i) data_[i] = 0;   // initialize data_
    for (i = 0; i < other.size_; ++i) {
        data_[i] = other.data_[i];
    }
}
BigInteger::~BigInteger() {
    if (data_ != NULL) {
        delete []data_;
        data_ = NULL;
    }
}
// clear function
void BigInteger::clear() {
    if (data_ != NULL)
    {
        delete []data_;
        data_ = NULL;
    }
}
// operators overloading
BigInteger operator+(const BigInteger& left, const BigInteger& right) {
    int i;
    BigInteger temp;
    temp.size_ = (left.size_ >= right.size_ ? left.size_ : right.size_) + 1;
    temp.data_ = new int[temp.MAX_];
    for (i = 0; i < temp.MAX_; ++i) temp.data_[i] = 0;   // initialize
    for (i = 0; i < left.size_ && i < right.size_; ++i) {
        temp.data_[i] += left.data_[i] + right.data_[i];
        temp.data_[i + 1] += temp.data_[i]/10;   // calculate carray
        temp.data_[i] %= 10;
    }
    if (left.size_ >= right.size_) {
        // copy other elements of left to temp
        while (i < left.size_) {
            temp.data_[i] += left.data_[i];
            temp.data_[i + 1] += temp.data_[i]/10;   // calculate carray
            temp.data_[i] %= 10;
            ++i;
        }
    } else {
        // copy other elements of right to temp
        while (i < right.size_) {
            temp.data_[i] += right.data_[i];
            temp.data_[i + 1] += temp.data_[i]/10;   // calculate carray
            temp.data_[i] %= 10;
            ++i;
        }
    }
    return temp;
}
BigInteger operator-(const BigInteger& left, const BigInteger& right) {
    int i, count;
    BigInteger temp;
    temp.size_ = (left.size_ >= right.size_ ? left.size_ : right.size_) + 1;
    temp.data_ = new int[temp.MAX_];
    for (i = 0; i < temp.MAX_; ++i) temp.data_[i] = 0;   // initialize
    for (i = 0; i < right.size_ && i < left.size_; ++i) {
        if (left.data_[i] >= right.data_[i]) {
            temp.data_[i] = left.data_[i] - right.data_[i];
        } else {
            temp.data_[i] = left.data_[i] - right.data_[i] + 10;
            --left.data_[i + 1];
        }
    }
    // cope with special case that left.data_[i] is nagetive
    count = i;
    while (count < left.size_) {
        if (left.data_[count] < 0) {
            left.data_[count] += 10;
            --left.data_[count + 1];
            ++count;
        } else {
            break;
        }
    }
    // copy the other elements of left to temp
    while (i < left.size_) {
        temp.data_[i] = left.data_[i];
        ++i;
    }
    return temp;
}
BigInteger BigInteger::operator=(const BigInteger& other) {
	if (data_ != NULL) {
		delete []data_;	  // delete the initialize value
	}
	size_ = other.size_;
	flag_ = other.flag_;
	data_ = new int[MAX_];
	for (int i = 0; i < other.size_; ++i) {
		data_[i] = other.data_[i];
	}
	return *this;
}
ostream& operator<<(ostream& out, const BigInteger& Bint) {
    if (Bint.data_ != NULL) {
        int k;
        for (k = Bint.MAX_ - 1; k > 0; --k) {
            if (Bint.data_[k] != 0) break;
        }
        if (!Bint.flag_) out << "-";
        while (k >= 0) {
            out << Bint.data_[k];
            --k;
        }
    }
    return out;
}
istream& operator>>(istream& in, BigInteger& Bint) {
	int i, j;
	string number;
	in >> number;
    Bint.clear();
	Bint.size_ = number.length();
	Bint.data_ = new int[Bint.MAX_];
	for (i = 0; i < Bint.MAX_; ++i) Bint.data_[i] = 0;
	for (i = number.length() - 1, j = 0; i > 0; --i, ++j) {
		Bint.data_[j] = number[i] - '0';
	}
	if (number[0] == '-') {
        --Bint.size_;
        Bint.flag_ = false;
    } else {
        Bint.data_[j] = number[0] - '0';
    }
	return in;
}


#include "String.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

// constructors
String::String() {
    _buff = NULL;
    _length = 0;
    _size = 0;
}
String::String(const char *src) {
    _length = strlen(src);
    _buff = new char[_length + 1];
    _
    for (int i = 0; i < _length; ++i) {
        _buff[i] = src[i];
    }
    _buff[_length] = '\0';   // attention!
}
String::String(const String &src) {
    _length = src._length;
    _size = src._size;
    _buff = new char[_length + 1];
    for (int i = 0; i < _length; ++i) {
        _buff[i] = *(src._buff + i);
    }
    _buff[_length] = '\0';   // attention!
}
// destructor
String::~String() {
    clear();
}
// member methods
void String::assign(const char *src) {
    clear();
    _length = strlen(src);
    _buff = new char[_length + 1];
    for (int i = 0; i < _length; ++i) {
        _buff[i] = src[i];
    }
    _buff[_length] = '\0';   // attention!
}
void String::append(const char &other) {
    char *temp = new char[_length + 2];
    for (int i = 0; i < _length; ++i) {
        temp[i] = _buff[i];
    }
    temp[_length] = other;
    temp[_length + 1] = '\0';   // attention!
    if (_buff != NULL) delete []_buff;
    _length = _length + 1;
    _buff = new char[_length + 1];
    for (int i = 0; i < _length; ++i) {
        _buff[i] = temp[i];
    }
    _buff[_length] = '\0';   // attention!
    delete []temp;
}
void String::clear() {
    _length = 0;
    _size = 0;
    if (_buff != NULL) {
        if (_length == 1) {
            delete _buff;
            return;
        }
        delete []_buff;
        _buff = NULL;
    }
}
int String::compare(const String &other) const {
    if (_buff == NULL && other._buff != NULL) {
        return -1;
    } else if (_buff != NULL && other._buff == NULL) {
        return 1;
    } else if (_buff != NULL && other._buff != NULL) {
        for (int i = 0; i < _length && i < other._length; ++i) {
            if (*(_buff + i) - *(other._buff + i) > 0) {
                return 1;
            } else if (*(_buff + i) - *(other._buff + i) < 0) {
                return -1;
            }
        }
        if (_length > other._length) return 1;
        else if (_length == other._length) return 0;
        else return -1;
    } else {
        return 0;
    }
}
const char* String::c_str() const {
    char *temp = new char[_length + 1];
    for (int i = 0; i < _length; ++i) {
        temp[i] = _buff[i];
    }
    temp[_length] = '\0';   // attention!
    return temp;
}
bool String::empty() const {
    if (_buff == NULL) return true;
    else return false;
}
int String::find(const String &other, int pos) const {
    if (other._length > _length) return _length;
    for (int i = 0; i < _length - other._length + 1; ++i) {
        if (*(_buff + i) == *(other._buff + pos)) {
            for (++i, ++pos; pos < other._length; ++pos, ++i) {
                if (*(_buff + i) != *(other._buff + pos)) break;
            }
            if (pos == other._length) return (i - pos);
            else i -= pos;
            pos = 0;   // attention!
        }
    }
    return _length;
}
int String::length() const {
    return _length;
}
String String::substr(const int &pos, const int &count) const {
    int i, j;
    String temp;
    temp._length = count;
    temp._buff = new char[temp._length + 1];
    for (j = 0, i = pos; i < pos + count && i < _length; ++i, ++j) {
        *(temp._buff + j) = _buff[i];   // attention!
    }
    *(temp._buff + j) = '\0';   // attention!
    return temp;
}
// overload operators
char& String::operator[](const int &index) {
    if (index < _length && index >= 0) return *(_buff + index);
}
void String::operator=(const String &other) {
    clear();
    _length = other._length;
    _size = other._size;
    _buff = new char[_length + 1];
    for (int i = 0; i < _length; ++i) {
        *(_buff + i) = *(other._buff + i);
    }
    _buff[_length] = '\0';   // attention!
}
void String::operator=(const char *src) {
    clear();    // attention!
    _length = strlen(src);
    _buff = new char[_length + 1];
    for (int i = 0; i < _length; ++i) {
        *(_buff + i) = *(src + i);
    }
    _buff[_length] = '\0';   // attention!
}
String String::operator+(const String &other) const {
    int i, j;
    String temp;
    temp._length = _length + other._length;
    temp._buff = new char[temp._length + 1];
    for (i = 0; i < _length; ++i) {
        *(temp._buff + i) = *(_buff + i);
    }
    for (j = 0; j < other._length; ++i, ++j) {
        *(temp._buff + i) = *(other._buff + j);
    }
    temp._buff[temp._length] = '\0';   // attention!
    return temp;
}
bool String::operator<(const String &other) const {
    if (compare(other) == -1) return true;
    else return false;
}
bool String::operator<=(const String &other) const {
    if (compare(other) != 1) return true;
    else return false;
}
bool String::operator>(const String &other) const {
    if (compare(other) == 1) return true;
    else return false;
}
bool String::operator>=(const String &other) const {
    if (compare(other) != -1) return true;
    else return false;
}
bool String::operator==(const String &other) const {
    if (compare(other) == 0) return true;
    else return false;
}
bool String::operator!=(const String &other) const {
    if (compare(other) != 0) return true;
    else return false;
}
// friend methods
ostream& operator<<(ostream& out, const String &str) {
    if (str._buff != NULL) {
        out << str._buff;
    }
    return out;
}
// non-meaning static property
char String::_error_sign = 0;


#include "dma.h"
#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

baseDMA::baseDMA(const char * l, int r) {
    label = new char[strlen(l)];
    rating = r;
    for (int i = 0; i < strlen(l); ++i) {
        label[i] = l[i];
    }
}
baseDMA::baseDMA(const baseDMA & rs) {
    *this = rs;
}
baseDMA::~baseDMA() {
    delete []label;
    label = 0;
}
baseDMA & baseDMA::operator=(const baseDMA & rs) {
    label = new char[strlen(rs.label)];
    rating = rs.rating;
    for (int i = 0; i < strlen(rs.label); ++i) {
        label[i] = rs.label[i];
    }
    return *this;
}
lacksDMA::lacksDMA(const char * c, const char * l, int r) : baseDMA(l, r) {
    for (int i = 0; i < strlen(c); ++i) {
        color[i] = c[i];
    }
}
lacksDMA::lacksDMA(const char * c, const baseDMA & rs) : baseDMA(rs) {
    for (int i = 0; i < strlen(c); ++i) {
        color[i] = c[i];
    }
}
hasDMA::hasDMA(const char * s, const char * l, int r) : baseDMA(l, r) {
    style = new char[strlen(s)];
    for (int i = 0; i < strlen(s); ++i) {
        style[i] = s[i];
    }
}
hasDMA::hasDMA(const char * s, const baseDMA & rs) : baseDMA(rs) {
    style = new char[strlen(s)];
    for (int i = 0; i < strlen(s); ++i) {
        style[i] = s[i];
    }
}
hasDMA::hasDMA(const hasDMA & hs) : baseDMA(hs) {
    style = new char[strlen(hs.style)];
    for (int i = 0; i < strlen(hs.style); ++i) {
        style[i] = hs.style[i];
    }
}
hasDMA::~hasDMA() {
    delete []style;
}
hasDMA & hasDMA::operator=(const hasDMA & rs) {
    if (this == &rs) return *this;
    baseDMA::operator=(rs);  // this is always used when the members
                             // of the base class is private.
    delete []style;
    style = new char[strlen(rs.style)];
    for (int i = 0; i < strlen(rs.style); ++i) {
        style[i] = rs.style[i];
    }
    return *this;
}


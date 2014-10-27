#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using std::ostream;

template <class T>
class Complex {
    private:
        T rel, img;
    public:
        Complex() : rel(0), img(0) {}
        Complex(T a, T b) : rel(a), img(b) {}
        Complex<T> operator+(const Complex<T>& right) {
            Complex<T> temp;
            temp.rel = rel + right.rel;
            temp.img = img + right.img;
            return temp;
        }
        Complex<T> operator-(const Complex<T>& right) {
            Complex<T> temp;
            temp.rel = rel - right.rel;
            temp.img = img - right.img;
            return temp;
        }
        Complex<T> operator*(const Complex<T>& right) {
            Complex<T> temp;
            temp.rel = rel*right.rel - img*right.img;
            temp.img = rel*right.img + img*right.rel;
            return temp;
        }
        Complex<T> operator/(const Complex<T>& r) {
            Complex<T> temp;
            if (r.rel == 0 && r.img == 0) return temp;
            temp.rel = (rel*r.rel + img*r.img)/(r.rel*r.rel + r.img*r.img);
            temp.img = (img*r.rel - rel*r.img)/(r.rel*r.rel + r.img*r.img);
            return temp;
        }
        friend ostream& operator<<(ostream& out, const Complex<T>& a) {
            out << a.rel;
            a.img < 0 ? out << a.img : out << "+" << a.img;
            out << "i";
            return out;
        }
};

#endif

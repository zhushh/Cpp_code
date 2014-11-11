#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using std::ostream;

template <typename T1 = int, typename T2 = int>
class Complex {
    private:
        T1 rel;
        T2 img;
    public:
        Complex() : rel(0), img(0) {}
        Complex(T1 a, T2 b) : rel(a), img(b) {}
        Complex<T1, T2> operator+(const Complex& right) {
            Complex temp;
            temp.rel = rel + right.rel;
            temp.img = img + right.img;
            return temp;
        }
        Complex<T1, T2> operator-(const Complex& right) {
            Complex temp;
            temp.rel = rel - right.rel;
            temp.img = img - right.img;
            return temp;
        }
        Complex<T1, T2> operator*(const Complex& right) {
            Complex temp;
            temp.rel = rel*right.rel - img*right.img;
            temp.img = rel*right.img + img*right.rel;
            return temp;
        }
        Complex<T1, T2> operator/(const Complex& r) {
            Complex temp;
            if (r.rel == 0 && r.img == 0) return temp;
            temp.rel = (rel*r.rel + img*r.img)/(r.rel*r.rel + r.img*r.img);
            temp.img = (img*r.rel - rel*r.img)/(r.rel*r.rel + r.img*r.img);
            return temp;
        }
        friend ostream& operator<<(ostream& out, const Complex<T1, T2>& a) {
            out << a.rel;
            a.img < 0 ? out << a.img : out << "+" << a.img;
            out << "i";
            return out;
        }
};

#endif

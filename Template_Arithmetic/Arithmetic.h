#ifndef ARITHMETIC_H
#define ARITHMETIC_H

template < class T >
class Arithmetic {
    public:
        Arithmetic(T a, T b);
        T addition();
        T subtraction();
        T multiplication();
        T division();
    private:
        T ans;
        T t1;
        T t2;
};

#endif


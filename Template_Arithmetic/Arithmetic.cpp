#include "Arithmetic.h"
#include <iostream>
using namespace std;

template < class T >
Arithmetic < T >::Arithmetic(T a, T b) {
    t1 = a;
    t2 = b;
}
template < class T >
T Arithmetic < T >::addition() {
    ans = t1 + t2;
    return ans;
}
template < class T >
T Arithmetic < T >::subtraction() {
    ans = t1 - t2;
    return ans;
}
template < class T >
T Arithmetic < T >::multiplication() {
    ans = t1 * t2;
    return ans;
}
template < class T >
T Arithmetic < T >::division() {
    ans = t1 / t2;
    return ans;
}


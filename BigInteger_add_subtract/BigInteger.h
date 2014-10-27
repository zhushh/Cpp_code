#ifndef _BIG_INTEGER_
#define _BIG_INTEGER_
#include <iostream>
#include <string>
using std::string;
using std::ostream;
using std::istream;

// forward declaration
class BigInteger;
     
// operators overloading
// overload addition operator
BigInteger operator+(const BigInteger& left, const BigInteger& right);
// overload subtraction operator
BigInteger operator-(const BigInteger& left, const BigInteger& right);
// overload output operator
ostream& operator<<(ostream& out, const BigInteger& Bint);
// overload input operator
istream& operator>>(istream& in, const string& number);

class BigInteger {
  public:
	// constructor
    BigInteger();
    explicit BigInteger(const string& number);
    BigInteger(const BigInteger& other);
    ~BigInteger();
    void clear();
    
    friend BigInteger operator+(const BigInteger& left,
    const BigInteger& right);
     
    // promise left >= right
    friend BigInteger operator-(const BigInteger& left,
    const BigInteger& right);
    
    // overload assigment operator
    BigInteger operator=(const BigInteger& other);
    friend ostream& operator<<(ostream& out, const BigInteger& Bint);
    friend istream& operator>>(istream& in, BigInteger& Bint);
     
    private:
    int *data_;
    int size_;
    bool flag_;
    int MAX_;
};

#endif // _BIG_INTEGER_


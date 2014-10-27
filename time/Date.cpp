#include "Date.h"
#include <string>
#include <iostream>

std::string convert(int num);

void Date::reset() {
    year = 2012;
    month = 12;
    day = 5;
}

void Date::set(int y, int m, int d) {
    year = y;
    month = m;
    day = d;
}

void Date::fromStr(std::string str) {
    int i;
    year = 0;
    for (i = 0; str[i] != '-'; i++) {
        year = year*10 + str[i] - '0';
    }
    month = 0;
    for (i = i + 1; str[i] != '-'; i++) {
        month = month*10 + str[i] - '0';
    }
    day = 0;
    for (i = i + 1; i < str.size(); i++) {
        day = day*10 + str[i] - '0';
    }
}

std::string Date::toStr() const {
    std::string ss;
    ss = convert(year);
    month < 10 ? ss += "-0" : ss += "-";
    ss += convert(month);
    day < 10 ? ss +="-0" : ss += "-";
    ss += convert(day);
    return ss;
}

std::string convert(int num) {
    int i;
    std::string c;
    std::string numString;
    c = '0' + num%10;
    numString = c + numString;
    num /= 10;
    while (num != 0) {
        c = '0' + num%10;
        numString = c + numString;
        num /= 10;
    }
    return numString;
}


#include <iostream>
#include <string>
#include "Date.h"
     
int main() {
    Date d;
    int iy, im, id;
    std::string is;
    d.reset();
    std::cout << d.toStr() << std::endl;
    std::cin >> iy >> im >> id;
    d.set(iy, im, id);
    std::cout << d.toStr() << std::endl;
    std::cin >> is;
    d.fromStr(is);
    std::cout << d.toStr() << std::endl;
    return 0;
}



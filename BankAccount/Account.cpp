#include "Account.h"
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int Account::_total_account = 0;
Account::Account() {
    _id = 0;
    _balance = 0;
    _valid = false;
    Account::_total_account++;
}
Account::~Account() {
    Account::_total_account--;
}
int Account::id() const {
    return _id;
}
double Account::balance() const {
    return _balance;
}
bool Account::valid() const {
    return _valid;
}
string Account::profile() const {
    char r1[20], r2[20];
    string s = "ID:";
    string::size_type pos;
    snprintf(r1, sizeof(r1), "%d", _id);
    snprintf(r2, sizeof(r2), "%.6lf", _balance);
    s += r1;
    s += "\nBALANCE:";
    s += r2;
    s += "\nVALID:";
    if (_valid) s += "Y\n";
    else s += "N\n";
    return s;
}
void Account::reset() {
    _balance = 0;
    _valid = false;
}
bool Account::deposit(const double &num) {
    if (num >= 0) {
        _balance += num;
        _valid = true;
        return true;
    } else {
        return false;
    }
}
bool Account::draw(const double &num) {
    if (num >= 0 && _balance - num >= 0.01) {
        _balance -= num;
        _valid = true;
        return true;
    } else {
        return false;
    }
}
int Account::get_total_account() {
    return Account::_total_account;
}


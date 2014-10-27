#include "VIPAccount.h"
#include "Account.h"
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int VIPAccount::_total_vip_account = 0;
int VIPAccount::_acc_id_ptr = 12049999;

VIPAccount::VIPAccount() {
    _balance = 10;
    _valid = true;
    _loan = 0;
    _loan_limit = 1000;
    VIPAccount::_total_vip_account++;
    VIPAccount::_acc_id_ptr++;
}
VIPAccount::~VIPAccount() {
    VIPAccount::_total_vip_account--;
    VIPAccount::_acc_id_ptr--;
}
bool VIPAccount::loan(const double &num) {
    if (num >= 0 && (_loan + num) <= _loan_limit) {
        _balance += num;
        _loan += num;
        return true;
    } else {
        return false;
    }
}
bool VIPAccount::repay(const double &num) {
    if (num >= 0 && _loan >= num && _balance >= num) {
        _balance -= num;
        _loan -= num;
        return true;
    } else if (num > _loan && num <= _balance) {
        _balance -= _loan;
        _loan = 0;
        _valid = true;
        return true;
    } else {
        return false;
    }
}
string VIPAccount::profile() const {
    char r1[20], r2[20], r3[20], r4[20];
    string s = "ID:";
    string::size_type pos;
    snprintf(r1, sizeof(r1), "%d", VIPAccount::_acc_id_ptr);
    s += r1;
    s += "\nBALANCE:";
    snprintf(r2, sizeof(r2), "%.6lf", _balance);
    s += r2;
    s += "\nVALID:";
    if (_valid) s += "Y\n";
    else s += "N\n";
    snprintf(r3, sizeof(r3), "%.6lf", _loan);
    s += "TYPE:VIP\nLOAN:";
    s += r3;
    snprintf(r4, sizeof(r4), "%.6lf", _loan_limit);
    s += ",LIMIT:";
    s += r4;
    s += "\n";
    return s;
}
void VIPAccount::settlement() {
    if (_balance > 0) _balance *= 1.02;
    _balance -= 10;
    if (_balance < 0.01) {
        _valid = false;
    } else {
        _valid = true;
    }
    if (_loan > 0) _loan *= 1.1;
    if (_loan < _loan_limit && _valid) {
        _loan_limit *= 1.01;
    } else {
        _valid = false;
        _loan_limit *= 0.95;
    }
}
void VIPAccount::reset() {
    _balance = 0;
    _loan = 0;
    _loan_limit = 1000;
}
int VIPAccount::get_total_vip_account() {
    return VIPAccount::_total_vip_account;
}


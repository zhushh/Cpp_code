#include "PersonalAccount.h"
#include "Account.h"
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int PersonalAccount::_total_per_account = 0;
int PersonalAccount::_acc_id_ptr = 12010001;
PersonalAccount::PersonalAccount() {
    _balance = 10;
    _valid = true;
    PersonalAccount::_total_per_account++;
    PersonalAccount::_acc_id_ptr++;
}
PersonalAccount::~PersonalAccount() {
    PersonalAccount::_total_per_account--;
    PersonalAccount::_acc_id_ptr--;
}
string PersonalAccount::profile() const {
    string s = "ID:";
    char r1[20], r2[20];
    string::size_type pos;
    snprintf(r1, sizeof(r1), "%d", PersonalAccount::_acc_id_ptr);
    snprintf(r2, sizeof(r2), "%.6lf", _balance);
    s += r1;
    s += "\nBALANCE:";
    s += r2;
    s += "\nVALID:";
    if (_valid) s += "Y\n";
    else s += "N\n";
    s += "TYPE:PERSONAL\n";
    return s;
}
void PersonalAccount::reset() {
    _balance = 10;
    _valid = true;
}

int PersonalAccount::get_total_per_account() {
    return PersonalAccount::_total_per_account;
}


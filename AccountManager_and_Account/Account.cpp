#include <iostream>
#include <string>
#include "Account.h"
using namespace std;
int Account::count_ = 0;
int Account::getCount() {
    return count_;
}
Account::Account(const string& name) {
    name_ = name;
    balance_ = 0;
    log_ += "Create an account " + name + "\n";
    ++count_;
}
Account::Account(const string& name, int balance) {
    name_ = name;
    balance_ = balance;
    log_ += "Create an account " + name +"\n";
    ++count_;
}
Account::~Account() {
    --count_;
}
void Account::deposit(int amount) {
    if (amount < 0) {
        cout << "Error operation!" << endl;
        log_ += "Error operation!\n";
    } else {
        balance_ += amount;
        log_ += "Deposit "+intToStr(amount)+" yuan\n";
    }
}
bool Account::withdraw(int amount) {
    if (amount < 0) {
        cout << "Error operation!" << endl;
        log_ += "Error operation!\n";
        return false;
    } else if (amount > balance_) {
        cout << "You don't have enough money!" << endl;
        log_ += "Error operation!\n";
        return false;
    } else {
        balance_ -= amount;
        log_ += "Withdraw " + intToStr(amount) + " yuan\n";
        return true;
    }
}
string Account::intToStr(int target) {
    string s, ss;
    if (target == 0) return s = "0";
    int count = 0, i;
    while (target > 0) {
        count++;
        s.push_back('0' + target%10);
        target /= 10;
    }
    for (i = 0; count > i; i++) {
        ss.push_back(s[count - i - 1]);
    }
    return ss;
}


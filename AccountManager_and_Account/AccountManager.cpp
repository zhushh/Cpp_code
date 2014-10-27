#include "AccountManager.h"
#include "Account.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
double AccountManager::interest_rate_ = 0.05;
void AccountManager::createAccount(const string& name) {
    int count = Account::getCount();
    if (count < 10) {
        accounts_[count] = new Account(name);
    }
}
void AccountManager::createAccount(const string& name, int balance) {
    int count = Account::getCount();
    if (count < 10) {
        accounts_[count] = new Account(name, balance);
    }
}
void AccountManager::caculateInterest() {
    int count = Account::getCount();
    if (count == 0) {
        cout << "Not any account!" << endl;
    } else {
        for (int i = 0; i < count; i++) {
            accounts_[i]->deposit(accounts_[i]->getBalance() * interest_rate_);
        }
    }
}
Account* AccountManager::getAccount(int position) {
    int count = Account::getCount();
    if (position >= 0 && position < count) {
        return accounts_[position];
    } else {
        cout << "Error operation!" << endl;
        return NULL;
    }
}
AccountManager::~AccountManager() {
    int count = Account::getCount();
    for (int i = 0; count > i; ++i) {
        delete accounts_[i];
    }
}


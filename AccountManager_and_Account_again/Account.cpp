#include "Account.h"
#include <iostream>
using std::string;
using std::cout;
using std::endl;
// constructor && initialize
Account::Account() {
	balance_ = 0;
	next_ = NULL;
}
Account::Account(const string& name, double balance) {
	name_ = name;
	balance_ = balance;
}
// get name
string Account::getName() const {
	return name_;
}
// get balance
double Account::getBalance() const {
	return balance_;
}
// get next
Account* Account::getNext() const {
	return next_;
}
// set name
void Account::setName(const string& name) {
	name_ = name;
}
// set balance
void Account::setBalance(double balance) {
	balance_ = balance;
}
// set next
void Account::setNext(Account* next) {
	next_ = next;
}


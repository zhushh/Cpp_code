#include "GuanErDai.h"
#include "Account.h"
#include <iostream>
using std::string;

GuanErDai::GuanErDai() {}
// 参数分别为官二代名、他爹名字、他爹财产
GuanErDai::GuanErDai(const string& name, const string& dadName, double balance)
:Account(dadName, balance) {
	GuanErDai::name_ = name;
}
// 获取官二代名字
string GuanErDai::getName() const {
	return GuanErDai::name_;
}
// 获取官二代财产
double GuanErDai::getBalance() const {
	return Account::getBalance();
}
// 修改官二代名字
void GuanErDai::setName(string name) {
	GuanErDai::name_ = name;
}
// 修改官二代财产
void GuanErDai::setBalance(double balance) {
	Account::setBalance(balance);
}


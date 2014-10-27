#include "FuErDai.h"
#include "Account.h"
#include <iostream>
using std::string;

// 参数名分别为富二代名、他爹名字、他爹财产
FuErDai::FuErDai(const string& name, const string& dadName, double balance)
:Account(dadName, balance) {
	name_ = name;   // 初始化富二代名字 
}
//  获取富二代名字
string FuErDai::getName() const {
	return name_;   // 返回富二代名字 
}
// 获取富二代财产
double FuErDai::getBalance() const {
	return Account::getBalance();   // 返回富二代的财产 
}
// 修改富二代名字
void FuErDai::setName(string name) {
	name_ = name;
}
// 修改富二代财产
void FuErDai::setBalance(double balance) {
	Account::setBalance(balance);
}


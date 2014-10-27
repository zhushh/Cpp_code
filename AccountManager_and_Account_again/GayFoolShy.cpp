#include "GayFoolShy.h"
#include "FuErDai.h"
#include "GuanErDai.h"
#include <iostream>
using std::string;

// 参数名分别为高富帅名字、他亲爹名字、他亲爹财产、他干爹名字、他干爹财产
GayFoolShy::GayFoolShy(const string& name, const string& fName, double fBalance,
		            const string& gName, double gBalance)
:FuErDai(name, fName, fBalance), GuanErDai(name, gName, gBalance) {
	GayFoolShy::name_ = name;
}
// 获取高富帅名字
string GayFoolShy::getName() const {
	return GayFoolShy::name_;
}
// 获取高富帅财产
double GayFoolShy::getBalance() const {
	return FuErDai::getBalance() + GuanErDai::getBalance();
}


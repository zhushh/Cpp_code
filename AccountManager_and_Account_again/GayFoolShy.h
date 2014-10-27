#ifndef GAYFOOLSHY_H
#define GAYFOOLSHY_H

#include "FuErDai.h"
#include "GuanErDai.h"
#include <iostream>
using std::string;

class GayFoolShy:public FuErDai, private GuanErDai {
	public:
		// 参数名分别为高富帅名字、他亲爹名字、他亲爹财产、他干爹名字、他干爹财产
		GayFoolShy(const string& name, const string& fName, double fBalance,
		           const string& gName, double gBalance);
		string getName() const;   // 获取高富帅名字
		double getBalance() const;   // 获取高富帅财产
	private:
		string name_;
};

#endif


#ifndef FUERDAI_H
#define FUERDAI_H

#include "Account.h"
#include <iostream>
using std::string;

class FuErDai:public Account {
	public:
		// 参数名分别为富二代名、他爹名字、他爹财产
		FuErDai(const string& name, const string& dadName, double balance);
		string getName() const;   //  获取富二代名字
		double getBalance() const;   // 获取富二代财产
		void setName(string name);   // 修改富二代名字
		void setBalance(double balance);   // 修改富二代财产
	private:
		string name_; 
};

#endif


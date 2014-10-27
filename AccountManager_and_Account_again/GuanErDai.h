#ifndef GUANERDAI_H
#define GUANERDAI_H

#include "Account.h"
#include <iostream>
using std::string;

class GuanErDai:private Account {
	public:
		GuanErDai();
		// 参数分别为官二代名、他爹名字、他爹财产
		GuanErDai(const string& name, const string& dadName, double balance);
		string getName() const;   // 获取官二代名字
		double getBalance() const;   // 获取官二代财产
		void setName(string name);   // 修改官二代名字
		void setBalance(double balance);   // 修改官二代财产
	private:
		string name_; 
};

#endif


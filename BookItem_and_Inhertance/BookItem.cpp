#include "BookItem.h"
#include <iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;
BookItem::BookItem(const string& bookName, double salesPrice) {
	name_ = bookName;
	price_ = salesPrice;
}
string BookItem::getName() const {
	return name_;
}
double BookItem::netPrice(int cnt) const {
	return cnt*price_;
}


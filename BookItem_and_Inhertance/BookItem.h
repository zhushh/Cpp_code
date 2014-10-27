#ifndef BOOKITEM_H
#define BOOKITEM_H

#include <iostream>
using std::string;

class BookItem {
	public:
		BookItem(const string& bookName, double salesPrice);
		
		/* Return the name of the book */
		string getName() const;
		
		/*
		 * Return the total price of these books
		 * total price: cnt*price
		 */
		 double netPrice(int cnt) const;
		 
	protected:
		double price_;
		
	private:
		string name_;
};

#endif


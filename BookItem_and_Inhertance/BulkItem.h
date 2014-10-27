#ifndef BULKITEM_H
#define BULKITEM_H

#include "BookItem.h"
#include <iostream>
using std::string;

class BulkItem:public BookItem {
	public:
		BulkItem(const string& bookName, double salesPrice,
		        int qty = 0, double salesDisc = 1.0);

/*
 * Return the total price of these books
 * If cnt is greater than minQty, total price: cnt*price*discount
 * else, total price: cnt*price 
 */
        double netPrice(int cnt) const;
        
    private:
		int minQty_;
		double discount_;
};

#endif


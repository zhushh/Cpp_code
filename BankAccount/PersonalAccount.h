#ifndef PERSONALACCOUNT_H
#define PERSONALACCOUNT_H

#include "Account.h"

class PersonalAccount : public Account {
	private:
		static int _total_per_account;
		static int _acc_id_ptr;
	public:
		PersonalAccount();
		~PersonalAccount();
		
		std::string profile() const;
		void reset();
		
		static int get_total_per_account();
};

#endif


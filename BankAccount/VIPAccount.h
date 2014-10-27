#ifndef VIPACCOUNT_H
#define VIPACCOUNT_H

#include "Account.h"

class VIPAccount : public Account {
	private:
		static int _total_vip_account;
		static int _acc_id_ptr;
	protected:
		double _loan;
		double _loan_limit;
	public:
		VIPAccount();
		~VIPAccount();
		bool loan(const double &num);
		bool repay(const double &num);
		
		std::string profile() const;
		void reset();
		
		static int get_total_vip_account();
};

#endif


#include "Bank.h"
#include "PersonalAccount.h"
#include "VIPAccount.h"
#include <iostream>
#include <vector>

using namespace std;

void Bank::do_settlement() {
    for (int i = 0; i < _list.size(); ++i) {
        _list[i]->settlement();
    }
}
void Bank::insert(Account* g) {
    _list.push_back(g);
}


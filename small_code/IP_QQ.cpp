#include <iostream>
#include <map>
#include <set>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::multimap;
using std::set;
using std::string;

int main() {
    multimap<string, string> qqip, ipqq;
    multimap<string, string>::iterator itr;
    set<string> q_i, i_q;
    set<string>::iterator it;
    string qq, ip;
    int test;
    cin >> test;
    while (test-- > 0) {
        cin >> qq >> ip;
        qqip.insert(make_pair(ip, qq));
        ipqq.insert(make_pair(qq, ip));
    }
    cin >> ip >> qq;
    itr = qqip.find(ip);
    if (itr == qqip.end()) {
        cout << "no qq" << endl;
    } else {
        while (itr != qqip.end()) {
             i_q.insert(itr->second);
             qqip.erase(itr);
             itr = qqip.find(ip);
        }
        it = i_q.begin();
        cout << ip << " ==> [ ";
        for (; it != i_q.end(); ++it)
            cout << *it << " ";
        cout << "]" << endl;
    }
    itr = ipqq.find(qq);
    if (itr == ipqq.end()) {
        cout << "no ip" << endl;
    } else {
        while (itr != ipqq.end()) {
            q_i.insert(itr->second);
            ipqq.erase(itr);
            itr = ipqq.find(qq);
        }
        it = q_i.begin();
        cout << qq << " ==> [ ";
        for (; it != q_i.end(); ++it)
            cout << *it << " ";
        cout << "]" << endl;
    }
    return 0;
}


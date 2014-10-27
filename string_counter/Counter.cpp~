#include "Counter.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;

void Counter::extract(string a) {
    vector<string>vec;
    vector<string>::iterator iter;
    vector<int>v_i;
    vector<int>::iterator i_iter;
    int count = 0;
    string temp = "";
    // extract the string and stored in a string vector
    for (string::size_type pos = 0; pos < string::npos; count = ++pos) {
        pos = a.find(';', pos);
        if (count != pos - 1)
            temp.assign(a, count, pos - count);
        vec.push_back(temp);
        temp = "";
    }
    sort(vec.begin(), vec.end());   // sort these string
    // count each string number
    for (iter = vec.begin() + 1, count = 1; iter < vec.end(); ++iter) {
        if (*iter == *(iter - 1)) {
            count++;
        } else {
            v_i.push_back(count);
            count = 1;
        }
        if (iter == vec.end() - 1) v_i.push_back(count);
    }
    iter = unique(vec.begin(), vec.end());
    vec.erase(iter, vec.end());    // delete repeat string
    // start insert pair to map
    i_iter = v_i.begin();
    for (iter = vec.begin(); iter < vec.end(); ++iter, ++i_iter) {
        m.insert(make_pair(*iter, *i_iter));
    }
}
int Counter::query(string a) {
    int count = 0;
    map<string, int>::iterator iter;
    iter = m.find(a);
    if (iter == m.end()) return 0;
    count = (*iter).second;
    return count;
}


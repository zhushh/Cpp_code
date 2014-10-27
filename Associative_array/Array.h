#ifndef ARRAY_H
#define ARRAY_H

#include <cstdio>
#include <vector>
#include <map>
#include <string>
using std::string;
using std::vector;
using std::map;

class Array {
    public:
        Array() : count(0) {}
        ~Array() {}
        int& operator[](int index) {
            map<string, int>::iterator it;
            char in_[10];
            string in;
            snprintf(in_, sizeof(in_), "%d", index);
            in = in_;
            it = ind.find(in);
            if (it != ind.end()) {
                return arr[it->second];
            } else {
                ind.insert(make_pair(in, count++));
                arr.resize(arr.size() + 1);
                arr[arr.size() - 1] = 0;
                return arr[arr.size() - 1];
            }
        }
        int& operator[](string index) {
            map<string, int>::iterator it;
            it = ind.find(index);
            if (it != ind.end()) {
                return arr[it->second];
            } else {
                ind.insert(make_pair(index, count++));
                arr.resize(arr.size() + 1);
                arr[arr.size() - 1] = 0;
                return arr[arr.size() - 1];
            }
        }
    private:
        int count;
        vector<int> arr;
        map<string, int> ind;
};

#endif

#ifndef DICT_H
#define DICT_H

#include <iostream>
#include <string>
#include <map>
using std::map;
using std::string;

class Dict {
    public:
        Dict() {}
        ~Dict() {}
        string to_lower(const string& word) {   // convert upper to lower
            string tmp;
            for (int i = 0; i < word.size(); ++i) {
                tmp += word[i] - 'A' + 'a';
            }
            return tmp;
        }
        void remove(const string& word) {
            string tmp = to_lower(word);    // record its lower case
            map<string, string>::iterator it;
            it = dictionary.find(word);
            if (it != dictionary.end()) {
                dictionary.erase(it);
            }
            it = dictionary.find(tmp);
            if (it != dictionary.end()) {
                dictionary.erase(it);
            }
        }
        const int size() {
            int count = 0;
            map<string, string>::iterator it;
            it = dictionary.begin();
            for (; it != dictionary.end(); ++it)
                if ("*** not in dictionary" != it->second)
                    ++count;
            return count;
        }
        string& operator[](const string& word) {
            string tmp = to_lower(word);    // record its lower case
            map<string, string>::iterator it, it2;
            it = dictionary.find(word);
            it2 = dictionary.find(tmp);
            if (it == dictionary.end() && it2 == dictionary.end()) {
                dictionary.insert(make_pair(word, "*** not in dictionary"));
                it = dictionary.find(word);
            }
            if (it2 != dictionary.end()) {
                return it2->second;
            }
            return it->second;
        }
        friend std::ostream& operator<<(std::ostream& out, Dict& d) {
            map<string, string>::iterator it;
            it = (d.dictionary).begin();
            for (; it != (d.dictionary).end(); ++it) {
                if (it->second != "*** not in dictionary")
                    out << it->first << "->" << it->second << std::endl;
            }
            return out;
        }
    private:
        map<string, string> dictionary;
};

#endif


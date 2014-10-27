#ifndef WORDSCOUNTER_H
#define WORDSCOUNTER_H

#include <iostream>
#include <sstream>
#include <string>
#include <set>

using std::ostream;
using std::set;
using std::string;
using std::stringstream;

class WordsCounter {
    public:
        WordsCounter() : bound(0), sum_words(0) {}
        explicit WordsCounter(int b) : bound(b), sum_words(0) {}
        int operator()(string text) {
            sum_words = 0;
            string temp;
            stringstream ss;
            set<string> words;
            set<string>::iterator it;
            ss.clear();
            ss.str("");
            ss << text;
            while (ss >> temp) {
                words.insert(temp);
            }
            it = words.begin();
            for (; it != words.end(); ++it) {
                if ((*it).size() >= bound) ++(sum_words);
            }
            return sum_words;
        }
        void setBound(int b) { bound = b; }
        friend ostream& operator<<(ostream& out, const WordsCounter& tp) {
            out << tp.sum_words;
            return out;
        }
    private:
        int bound;
        int sum_words;
};

#endif


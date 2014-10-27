#ifndef PAIR_H
#define PAIR_H

template <class T1, class T2>
class Pair {
    public:
        Pair() {}
        Pair(const T1& f) : first(f) {}
        Pair(const T2& s) : second(s) {}
        ~Pair() {}
        void setFirst(const T1& t1) {
            first = t1;
        }
        T1 getFirst() const {
            return first;
        }
        void setSecond(const T2& t2) {
            second = t2;
        }
        T2 getSecond() const {
            return second;
        }
        void swap(Pair<T1, T2>& t) {
            Pair<T1, T2> temp;
            temp.first = first;
            temp.second = second;
            first = t.first;
            second = t.second;
            t.first = temp.first;
            t.second = temp.second;
        }
    private:
        T1 first;
        T2 second;
};

#endif


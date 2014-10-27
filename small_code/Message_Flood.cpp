#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cctype>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::set;
using std::vector;

int main() {
    int n;
    while (cin >> n && n) {
        int m;
        string name;
        vector<string> names;
        cin >> m;
        for (int i = 0; i < n; i++) {
            cin >> name;
            for (string::size_type i = 0; i < name.size(); i++)
                name[i] = tolower(name[i]);
            names.push_back(name);
        }
        set<string> remove_name;
        for (int i = 0; i < m; i++) {
            cin >> name;
            for (string::size_type i = 0; i < name.size(); i++)
                name[i] = tolower(name[i]);
            remove_name.insert(name);
        }
        vector<string>::iterator it = names.begin();
        while (it != names.end()) {
            if (remove_name.count(*it))
                n--;
            ++it;
        }
        cout << n << endl;
    }
    return 0;
}

#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    int m, n, sum;
    string name;
    set<string> sender;
    set<string> receiver;
    set<string>::iterator it;
    while (cin >> m && m) {
        cin >> n;
        for (int i = 0; i < m; ++i) {
            cin >> name;
            for (unsigned int j = 0; j < name.size(); ++j) {
                if (name[j] >= 'A' && name[j] <= 'Z')
                    name[j] = name[j] - ('A' - 'a');
            }
            sender.insert(name);
        }
        for (int i = 0; i < n; ++i) {
            cin >> name;
            for (unsigned int j = 0; j < name.size(); ++j) {
                if (name[j] >= 'A' && name[j] <= 'Z')
                    name[j] = name[j] - ('A' - 'a');
            }
            receiver.insert(name);
        }
        it = sender.begin();
        for (sum = 0; it != sender.end(); ++it) {
            if (receiver.find(*it) == receiver.end())
                sum++;
        }
        cout << sum << endl;
        sender.clear();
        receiver.clear();
    }
    return 0;
}

#include <string>
std::string change1(char *st) {
    std::string ss;
    for (int i = 0; st[i] != '\0'; i++)
        ss += st[i];
    return ss;
}

void change2(std::string st1, char *st2) {
    st1 += '\0';
    for (int i = 0; st1[i] != '\0'; i++) {
        st2[i] = st1[i];
    }
}


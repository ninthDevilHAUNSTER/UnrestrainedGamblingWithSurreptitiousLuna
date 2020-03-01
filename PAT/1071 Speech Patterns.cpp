#include <iostream>
#include <map>
#include <cctype>

using namespace std;
//[0-9 A-Z a-z]可以简写为cctype头⽂文件⾥里里⾯面的⼀一个函数isalnum～～
int main() {
    string s, t;
    getline(cin, s);
    map<string, int> m;
    for (int i = 0; i < s.length(); i++) {
        if (isalnum(s[i])) {
            s[i] = tolower(s[i]);
            t += s[i];
        }
        if (!isalnum(s[i]) || i == s.length() - 1) {
            if (t.length() != 0) m[t]++;
            t = "";
        }
    }
    int maxn = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
        if (it->second > maxn) {
            t = it->first;
            maxn = it->second;
        }
    }
    cout << t << " " << maxn;
    return 0;
}
//
// Created by shaob on 2020/2/28.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>

using namespace std;
string sum;
vector<string> s;
int N;

bool sort_cmp(const string &s1, const string &s2) {
    return s1 + s2 < s2 + s1;
}


bool cmp(const string &s1, const string &s2) {
    return s1 < s2;
}

int pat_solver() {
    scanf("%d", &N);
    string _t;
    for (int i = 0; i < N; ++i) {
        cin >> _t;
        s.push_back(_t);
//        for (int j = 0; j < _t.length(); ++j) {
        //不能直接把前导0给去了啊。如果放在中间的话那就有问题了
        //如 01 001
        /*
         * 答案应该是 00101==> 101
         * 而不是 11.
         */
//            if (_t[j] != '0') {
//                s.push_back(_t.substr(j, _t.length() - j));
//                break;
//            }
//        }
    }
    sort(s.begin(), s.end(), sort_cmp);
    for (int j = 0; j < N; j++) {
        sum = (cmp(s[j] + sum, sum + s[j])) ? (s[j] + sum) : (sum + s[j]);
    }
    while (sum.size() != 0 && sum[0] == '0') {
        sum.erase(sum.begin());
    }
    if (sum.size() == 0) cout << 0; else cout << sum;
}
//22932321321487
//22932132143287
//22932132143287
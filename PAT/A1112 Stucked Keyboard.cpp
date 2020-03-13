//
// Created by shaob on 2020/3/8.
//

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <cassert>
#include <cmath>
#include <unordered_set>

using namespace std;
#define INF 0x3fffffff
#define inf 0x3fffffff

bool sureNoBroken[256];
map<char, bool> m; // 统计连续出现的情况
unordered_set<char> printed;

int pat_solver() {
    int k, cnt = 1;
    scanf("%d", &k);
    fill(sureNoBroken, sureNoBroken + 256, false);
    string s;
    cin >> s;
    s = s + '#';
    char pre = '#';
    for (char i : s) {
        if (pre == i) {
            cnt++;
        } else {
            if (cnt % k != 0) {
                sureNoBroken[pre] = true;
            }
            cnt = 1;
        }
        if (i != s.length() - 1) m[i] = (cnt % k == 0);
        pre = i;
    }
    // sureNotBroken中存储这所有输出不超过K次的字符，也就是一定不会出错的字符.
    for (int i = 0; i < 256; i++) {
        if (sureNoBroken[i]) {
            m[char(i)] = false;
        }
    }
    for (int i = 0; i < s.length() - 1; i++) {
        if (m[s[i]] && printed.find(s[i]) == printed.end()) {
            printf("%c", s[i]);
            printed.insert(s[i]);
        }
    }
// 你细品一下自己Print的顺序是不是有问题？
//    for (auto &_:m) {
//        if (_.second)
//            printed.insert(_.first);
//    }
//    for (auto _:printed) {
//        printf("%c", _);
//    }
    printf("\n");
    for (int j = 0; j < s.length()-1; ++j) {
        printf("%c", s[j]);
        if (m[s[j]]) {
            j += k - 1;
        }
    }


    return 0;
}

/*
测试样例



*/
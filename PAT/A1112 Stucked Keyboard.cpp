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

using namespace std;
#define INF 0x3fffffff
#define inf 0x3fffffff

bool isBroken[256];
int K;
set<char> result;
map<char, bool> mayBroken;

int pat_solver() {
    cin >> K;
    string s;
    cin >> s;
//    if (s.length() == 1)
    int i = 0;
    int repeat = 1;
    while (i < s.length()) {
        if (i < s.length() && s[i] == s[i - 1]) {
            repeat++;
        } else {
            if (repeat % K == 0) {
                isBroken[int(s[i])] = true;
            }
            repeat = 1;
        }
        i++;
    }


    return 0;
}

/*
测试样例



*/
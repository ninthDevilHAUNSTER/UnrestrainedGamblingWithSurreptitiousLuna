//
// Created by shaob on 2020/3/14.
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
#include <unordered_map>

using namespace std;
#define INF 0x3fffffff
#define inf 0x3fffffff

/*
测试样例



*/
class Solution {

private:
    vector<int> memo;

    int max3(int a, int b, int c) {
        return max(a, max(b, c));
    }

    int res = 0;


    int breakInteger(int n) {
        // n >=2 && n<= 58
        // 将n分隔，分隔成两部分
        // 记忆化搜索
        if (n == 1)
            return 1;
        if (memo[n] != -1) return memo[n];

        for (int i = 1; i <= n - 1; ++i) {
            res = max3(res, i * (n - 1), i * breakInteger(n - 1));
        }
        memo[n] = res;
        return res;
    }

    int dp(int n) {
        memo[1] = 1;
        for (int i = 2; i <= n; ++i) {
            // 求解 memo [i]
            for (int j = 1; j < i - 1; ++j) {
                memo[i] = max3(memo[i], j * (i - j), j * memo[i - j]);
            }
        }
        return memo[n];
    }

public:
    int integerBreak(int n) {
        this->memo.resize(100, -1);
        return breakInteger(n);
    }
};
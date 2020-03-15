//
// Created by shaob on 2020/3/15.
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
public:
    int numSquares(int n) {
        /*
         * DP[i] 含义: 使得当前平方和为 i 的最小个数
         * 方程
         *
         * DP[i] = min(DP[i],DP[i-j*j]+1) i = 1..N ; j = 1.. sqrt(i) ;init:: DP[i] = i (i个1之和)
         */
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            dp[i] = i;
            for (int j = 1; i >= j * j; ++j) {
                dp[i] = min(dp[i], dp[i - j * j] + 1); // 显然,dp[i - j*j ] 的值已经更新过了
            }
        }
        return dp[n];
    }
};
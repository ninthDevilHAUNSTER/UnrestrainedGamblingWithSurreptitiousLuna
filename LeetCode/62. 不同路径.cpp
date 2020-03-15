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
private:
    int dp[128][128];
public:

    // 这个的解法和最小路径和那道题是一样的，只不过和换成了个数
    int uniquePaths(int C, int R) {
        C--, R--;
        int col = C, row = R;
        for (int i = 0; i <= C; ++i) {
            dp[0][i] = 1;
        }
        for (int j = 0; j <= R; ++j) {
            dp[j][0] = 1;
        }
        for (row = 1; row <= R; ++row) {
            for (col = 1; col <= C; ++col) {
                dp[row][col] = dp[row][col - 1] + dp[row - 1][col];
            }
        }
        return dp[R][C];
    }
};
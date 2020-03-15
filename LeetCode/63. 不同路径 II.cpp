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
    long long  dp[128][128];
public:
    long long  uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        if (obstacleGrid[0][0] == 1)
            return 0;
        dp[0][0] = 1;
        int R = obstacleGrid.size();
        int C = obstacleGrid[0].size();
        for (int i = 1; i < R; ++i) {
            dp[i][0] =  obstacleGrid[i][0] == 0 ?dp[i - 1][0]:0;
        }
        for (int j = 1; j < C; ++j) {
            dp[0][j] = obstacleGrid[0][j] == 0 ?dp[0][j - 1]:0;
        }
        for (int r = 1; r < R; ++r) {
            for (int c = 1; c < C; ++c) {
                dp[r][c] = (obstacleGrid[r][c] == 0 ? dp[r - 1][c] + dp[r][c - 1] : 0);
            }
        }
        return dp[R - 1][C - 1];
    }
};
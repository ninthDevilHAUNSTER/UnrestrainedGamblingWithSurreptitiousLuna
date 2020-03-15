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

class Solution {

public:
    int minPathSum(vector<vector<int>> &grid) {
        vector<int> dp(grid[0].size());
        int col, row;
        int C = int(grid[0].size() - 1), R = int(grid.size()) - 1;
        /* 一维DP. */
        for (row = R; row >= 0; --row) {
            for (col = C; col >= 0; --col) {
                if (col == C && row == R) {
                    dp[col] = grid[R][C];
                } else if (col == C && row != R) {
                    dp[col] = dp[col] + grid[row][col];
                } else if (col != C && row == R) {
                    dp[col] = dp[col + 1] + grid[row][col];
                } else {
                    dp[col] = min(dp[col + 1], dp[col]) + grid[row][col];
                }
            }
        }
        return dp[0];
    }

    int _minPathSum(vector<vector<int>> &grid) {
        int dp[1000][1000];
        fill(dp[0], dp[0] + 1000 * 1000, 0);
        int col, row;
        int C = int(grid[0].size() - 1), R = int(grid.size()) - 1;
        /* 二维DP. */
        for (row = R; row >= 0; --row) {
            for (col = C; col >= 0; --col) {
                if (col == C && row == R) {
                    dp[row][col] = grid[R][C];
                } else if (col == C && row != R) {
                    dp[row][col] = dp[col][row + 1] + grid[row][col];
                } else if (col != C && row == R) {
                    dp[row][col] = dp[col + 1][row] + grid[row][col];
                } else {
                    dp[row][col] = min(dp[row][col + 1], dp[row + 1][col]) + grid[row][col];
                }
            }
        }
        return dp[0][0];
    }
};
/*
 * 以下代码都是在放屁
while (col < grid.size() && row < grid.size()) {
    ans = grid[row][col];
    memo.push_back(ans); //
    if (col == grid[0].size() - 1) {
        row += 1;
    } else if (row == grid.size() - 1) {
        col += 1;
    } else {
        if (grid[row + 1][col] < grid[row][col + 1]) {
            row += 1;
        } else {
            col += 1;
        }
    }
}
return memo.back();
 */
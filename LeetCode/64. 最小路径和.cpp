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
        vector<int> memo[grid.size()];
        int col = grid[0].size() - 1, row = grid.size() - 1;
        int ans = 0;
        while (col >= 0 && row >= 0) {
            ans = grid[row][col];

        }



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
    }
};
/*
测试样例



*/
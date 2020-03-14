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
    int minimumTotal(vector <vector<int>> &triangle) {
        int h = triangle.size(); //高度

        vector<int> res(triangle[h - 1].begin(), triangle[h - 1].end());

        for (int i = h - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                res[j] = min(res[j], res[j + 1]) + triangle[i][j]; // 我一开始以为相邻的概念是是向下，向左，向右三个方向，年轻了...
            }
        }
        return res[0];
    }
};
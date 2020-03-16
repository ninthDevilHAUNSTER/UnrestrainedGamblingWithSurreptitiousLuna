//
// Created by shaob on 2020/3/16.
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
    // vector<pair<int, int>> dp; // 第一个为长度，第二个为已经翻转的1的个数
public:
    int longestOnes(vector<int> &A, int K) {
        // DP 不是很做得出，网上介绍了双指针的做法
        int r = 0, l = 0; // [l,r] 内有至多K个0.
        int res = 0;// 记录区间的长度
        int zero = 0; // 记录目前遍历到的0的个数
        for (l = 0; l < A.size(); l++) {
            if (A[l] == 0) zero++;
            while (zero > K) {
                if (A[r] == 0) {
                    zero--;
                }
                r++;
            }
            res = max(res, l - r + 1);
        }
        return res;
    }

    // int _longestOnes(vector<int> &A, int K) {
    //     // 实际上就是最长不下降子序列的长度？
    //     // 状态转移方程:
    //     // dp[i] = max(1,dp[j]+1) // A[j] > A[i]
    //     // 之后我们要改一改
    //     // 我觉得，需要继承上一个状态K的个数。
    //     // dp[i] = max(
    //     dp.resize(A.size(), pair<int, int>(0, 0));
    //     for (int i = 0; i < A.size(); ++i) {
    //         for (int j = 0; j < i; ++j) {

    //         }
    //     }
    // }
};
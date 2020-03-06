//
// Created by shaob on 2020/3/6.
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

using namespace std;
#define MaxSize 100010
#define MaxColor 256
int N, M, L;
int favourColor[MaxColor];
vector<int> seq;
int dp[MaxSize];

int LIS() {
    /*
     * 给定序列 seq，查找seq中的最长不下降子序列，按照 favourColor 的顺序。
     *
     * LIS DP[i] 含义 ： 加入seq[i] 后的序列其最长不下降子序列长度。
     * 状态转移方程：
     * DP[i] = max(1,1+DP[j]) j=0..i-1 && seq[j] <= seq[i].
     *
     */
    int ans = -1;
    for (int i = 0; i < seq.size(); ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (seq[i] >= seq[j]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int pat_solver() {
    fill(favourColor, favourColor + MaxColor, -1);
    scanf("%d%d", &N, &M);
    int _;
    for (int i = 0; i < M; ++i) {
        scanf("%d", &_);
        favourColor[_] = i; // i 越小代表越喜欢。
    }
    scanf("%d", &L);
    for (int j = 0; j < L; ++j) {
        scanf("%d", &_);
        if (favourColor[_] != -1) seq.push_back(favourColor[_]);
    }
    printf("%d", LIS());
    return 0;
}

/*
测试样例



*/

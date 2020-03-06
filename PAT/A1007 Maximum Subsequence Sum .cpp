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
#define MaxSize 0x3fff

int N;
vector<int> seq;
int dp[MaxSize]; // dp 表示包含第i个元素的子序列和。
int start[MaxSize]; // start[i] 代表了从dp[i] 是从哪个元素的下标开始的。
/*
 * 于是dp状态转移方程就为：
 *
 * dp[i] =max( dp[i-1] + seq[i] , seq[i])
 * 这里还需要输出初始和结束的下标。
 *
 * 注意一个样例
 *
 *
 2 -1 0 应输出 0 0 0

1 0 应输出 0 0 0

2 -1 -2 应输出0 -1 -2

    3
    -1 -2 -3

    >> 0 -2 -2
 */

int DP() {
    dp[0] = seq[0];
//    pair<int, int> result(0, 0);
    for (int i = 1; i < N; ++i) {
        if (dp[i - 1] + seq[i] > seq[i]) {
            // 更新
            dp[i] = dp[i - 1] + seq[i];
            start[i] = start[i - 1];
        } else {
            // 不更新
            dp[i] = seq[i];
            start[i] = i;
        }
    }
    return 0;
}

int pat_solver() {
    int _;
    bool flag = false;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &_);
        seq.push_back(_);
        if (_ >= 0) flag = true;
    }
    if (!flag) {
        printf("0 %d %d", seq.front(), seq.back());
        return 0;
    }
    if (seq.size() == 1) {
        printf("%d %d %d", seq.front(), seq.front(), seq.back());
        return 0;
    }
    DP();
    int best = -MaxSize;
    int best_base = 0;
    for (int j = 1; j < N; ++j) {
        if (dp[j] > best) { // 这样相等的不会更新
            best = dp[j];
            best_base = j;
        }
    }

    printf("%d %d %d", best, seq[start[best_base]], seq[best_base]);
    return 0;
}

/*
测试样例



*/
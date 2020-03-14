//
// Created by shaob on 2020/3/7.
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

int N, M;

/*
 * N个硬币，买M块钱的东西，输出需要用的Money。多种方案按照字典序最大输出。
 * 每个硬币的面值为 m.
 * 状态转移方程，相当于01背包问题，因为硬币取走了就没了
 * dp[v] = max(dp[v],dp[v - m[i] ]+m[i])
 *
 *
 */

int dp[10010];
bool choice[10010][110];
int w[10010];


int cmp(int a, int b) {
    return a > b; // 从大到小排列，这样就可以满足字典序了。
}

int pat_solver() {
//    fill(dp, dp + MaxAmount, 0);
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &w[i]);
    }
    sort(w + 1, w + N + 1, cmp);
    for (int i = 1; i <= N; ++i) {
        for (int v = M; v >= w[i]; --v) {
            if (dp[v] <= dp[v - w[i]] + w[i]) {
                cout << dp[v - w[i]] + w[i] << endl;
                dp[v] = dp[v - w[i]] + w[i];
                choice[i][v] = true;
            }
        }
    }
    if (dp[M] != M) printf("No Solution");
    else {
        int index = N, v = M;
        vector<int> result;
        while (v > 0) {
            if (choice[index][v]) {
                result.push_back(w[index]);
                v -= w[index];
            }
            index--;
        }
        for (int i = 0; i < result.size(); ++i) {
            printf("%d", result[i]);
            if (i < result.size() - 1)printf(" ");
        }
    }
    return 0;
}

/*
测试样例



*/
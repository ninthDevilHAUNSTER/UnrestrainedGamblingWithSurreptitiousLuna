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
#define MaxSize 1024

/*
 * 最长回文子串LPS
 *
 * dp[i][j] 含义： A[i..j]是的子序列是否回文(0,1表示)
 * 状态方程：
 *      if A[i] == A[j] : dp[i][j] = dp[i-1][j-1]
 *      if A[i] != A[j] : dp[i][j] = 0
 * 边界条件:
 *      A[i][i] = 1 A[i][i+1] = (S[i]==S[i+1])?1:0
 * 注意要点:
 *      从长度为3的子序列开始遍历，才能有效解决访问的时候dp还没更新的问题
 *      特判长度为1和2的情况，ans=2在初始化的时候更新，由于dp外循环遍历子序列长度，因此subLen<=seq.size();
 */
char buffer[MaxSize];
int dp[MaxSize][MaxSize];

int pat_solver() {
    fill(dp[0], dp[0] + MaxSize * MaxSize, 0);
    cin.getline(buffer, MaxSize);
    string input = buffer;
    // 特判长度为1,2,3的输入?
    int ans = 1;

    for (int i = 0; i < input.size(); ++i) {
        dp[i][i] = 1;
        if (i + 1 < input.size()) {
            if (input[i] == input[i + 1]) {
                dp[i][i + 1] = 1;
                ans = 2;
            }
        }
    }
    for (int subLen = 3; subLen <= input.size(); subLen++) {
        for (int i = 0; i + subLen - 1 < input.size(); ++i) {
            int j = i + subLen - 1;
            if (input[i] == input[j] && dp[i + 1][j - 1] == 1) {
                dp[i][j] = dp[i + 1][j - 1];
                ans = max(ans, subLen);
            }
        }
    }
    printf("%d", ans);
    return 0;
}

/*
测试样例



*/
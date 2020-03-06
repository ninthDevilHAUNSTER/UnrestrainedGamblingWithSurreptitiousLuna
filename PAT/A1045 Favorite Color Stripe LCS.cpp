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
vector<int> favorSeq;
vector<int> Seq;
int dp[MaxColor][MaxSize];

/*
 * 最长公共子序列（不含重复序列）
 * dp[i][j]
 *      A[i] 与 B[j] 之前的LCS长度
 * dp方程
 *      dp[i][j] =
 *      if A[i] == B[j] : dp[i-1][j-1]+1
 *      if A[i] != B[j] : max(dp[i][j-1],dp[i-1][j]}
 * 边界条件
 *      dp[i][0] = 0; dp[0][j] = 0;
 *
 * 现在需要转化为，可以包含重复序列的情况
 *
 * dp方程
 *      dp[i][j] =
 *      if A[i] == B[j] : max(dp[i][j-1],dp[i-1][j])+1
 *      if A[i] != B[j] : max(dp[i][j-1],dp[i-1][j]}
 *
 * 为啥呢？ 可以看这样的例子：
 *
 * A:: aa
 * B:: ab
 * 其最长公共子序列（不重复）应该是 a。
 *
 * 当 i=1 j=0 时，A[i] == B[j] == 'a' 此时，最长公共子序列应该为 'a'
 * 因此，dp[1][0] = dp[0][0] = 1
 *
 * 其最长公共子序列（可重复）应该是 aab。
 *
 * 当 i=1 j=0 时，A[i] == B[j] == 'a' 此时，最长公共子序列应该为 'aa'
 * 因此，dp[1][0] = dp[0][0] + 1 = 2
 *
 *
 */

int LCS() {
    for (int j = 0; j < favorSeq.size(); ++j) {
        dp[j][0] = 0;
    }
    for (int i = 0; i < Seq.size(); ++i) {
        dp[0][i] = 0;
    }
    for (int k = 1; k < favorSeq.size(); ++k) {
        for (int i = 1; i < Seq.size(); ++i) {
            if (favorSeq[k] == Seq[i]) {
                dp[k][i] = max(dp[k - 1][i], dp[k][i - 1]) + 1;
            } else {
                dp[k][i] = max(dp[k - 1][i], dp[k][i - 1]);
            }
        }
    }
    return dp[favorSeq.size() - 1][Seq.size() - 1];
}

int pat_solver() {
    scanf("%d%d", &N, &M);
    int _;
    favorSeq.push_back(-1); // 注意了，LCS的下标是从1开始的，LPS也是如此，巧妙的方法是先给vector push一个空值。
    Seq.push_back(-1);
    for (int i = 0; i < M; ++i) {
        scanf("%d", &_);
        favorSeq.push_back(_);
    }
    scanf("%d", &L);
    for (int j = 0; j < L; ++j) {
        scanf("%d", &_);
        Seq.push_back(_);
    }
    printf("%d", LCS());
    return 0;
}

/*
测试样例



*/
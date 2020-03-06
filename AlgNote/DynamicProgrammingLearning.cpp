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
#define MaxSize 0xfff

int dp_fibonacci[MaxSize] = {-1};

int FibonacciSetQuestion(int n) {
/*
 * 从斐波那数列的知识中可以看到，
 * 因为斐波那契额数列中有着重叠子问题，所以可以用动态规划
 */
    if (n == 0 || n == 1)return 1;
    if (dp_fibonacci[n] != -1) return dp_fibonacci[n];
    else {
        dp_fibonacci[n] = FibonacciSetQuestion(n - 1) + FibonacciSetQuestion(n - 2);
        return dp_fibonacci[n];
    }
}

int tower[MaxSize][MaxSize];
int dp_tower[MaxSize][MaxSize] = {-1};

void numberTowerSolutionNoneRecursion(int n) {
    for (int l = n - 1; l >= 1; --l) {
        for (int i = 1; i <= l; ++i) {
            dp_tower[l][i] = max(dp_tower[l + 1][i], dp_tower[l + 1][i + 1]) + tower[l][i];
        }
    }
}

int numberTowerSolutionRecursion(int n, int x, int y) {
    if (dp_tower[x][y] != -1) {
        return dp_tower[x][y];
    }
    if (x == n)
        return tower[x][y];
    dp_tower[x][y] = max(
            numberTowerSolutionRecursion(n, x + 1, y),
            numberTowerSolutionRecursion(n, x + 1, y + 1)) + tower[x][y];
    return dp_tower[x][y];
}

int numberTowerProblem() {
    /*
     * 从数字塔问题中，可以看出：如果一个问题的最优解可以由子问题的最优解有效构造出来，那么这个问题就拥有最优子结构。
     * 比如每个dp的值可以通过两个子问题中最大的结果推导出来。
     * 因此，一个问题有着重叠的子问题和最优子结构，才可以用DP来解决。
     */
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            scanf("%d", &tower[i][j]);
            dp_tower[i][j] = -1;
        }
    }
    for (int k = 1; k <= n; ++k) {
        dp_tower[n][k] = tower[n][k];
    }// DP 边界
    numberTowerSolutionRecursion(n, 1, 1);
    printf("%d\n", dp_tower[1][1]);
    return 0;
}

int seq[MaxSize] = {0};
int dp_CSS[MaxSize] = {0};

void MaxContinuousSubsequenceSumProblem() {
    /*
     * 最长子序列和问题。
     * dp的含义是，以seq[i]为结尾的子序列的和。
     * 那么有两种情况：
     * ① dp[i] = seq[i]
     * ② dp[i] = seq[i] + dp[i-1]
     * 求上述两个的最最值，实际上就是看前面的子序列和是否为负。
     */
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }
    dp_CSS[0] = seq[0]; // 初始设定为 相同
    for (int j = 1; j < n; ++j) {
        dp_CSS[j] = max(dp_CSS[j - 1], 0) + seq[j];
    }
    int best = 0;
    for (int k = 1; k < n; ++k) {
        if (dp_CSS[k] > dp_CSS[best]) {
            best = k;
        }
    }
    printf("%d", dp_CSS[best]);
    /*
     * 通过最长子序列问题，可以看到动态规划的难点。
     *
     * ————如何涉及状态和状态转移方程。并且该状态要具有无后性。
     * 所谓的无后性，就是指后面的状态的变化和前面状态的变化无关，
     * 对于最长子序列和问题，就是dp[i] 只和 dp[i-1]有关而必须和dp[i+1]无关。
     */
}

int dp_LIS[MaxSize];
int seq_LIS[MaxSize];

void LongestIncreasingSequenceProblem() {
    /*
     * 其dp的含义是：
     *      包含了第i个元素的子序列所能达到的最长非递减子序列的长度。
     * 其方程是这样的：
     *      dp[j] = max{1,dp[i] + 1} // assert(seq[j] >= seq[i],i=0...j-1)
     *      第一指标是当前的元素一定要大。（自己理解我靠）
     *      第二指标是选出最大的dp。
     */
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> seq_LIS[i];
    }
    int LIS_biggest = -1; // LIS中最大元素有多大呢？
    for (int j = 1; j < n; ++j) {
        dp_LIS[j] = 1;
        for (int i = 0; i < j; ++i) {
            if (seq_LIS[i] > seq_LIS[j] && (dp_LIS[i] + 1) > dp_LIS[j]) {
                dp_LIS[j] = dp_LIS[i] + 1;
            }
        }
        LIS_biggest = max(LIS_biggest, dp_LIS[j]);
    }
    printf("%d", LIS_biggest);
}

void LongestCommonSubsequenceProblem(){
    /*
     * 最长公共子序列。
     */
}

int alg_solver() {
    MaxContinuousSubsequenceSumProblem();
    return 0;
}

/*
测试样例

5
5
8 3
12 7 16
4 10 11 6
9 5 3 9 4


6
-2 11 -4 13 -5 -2

 >>> 20


*/
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
#define MaxSize 0x100

class Solver {

    int seq[MaxSize] = {0};
    int seq2[MaxSize] = {0};
    int seq2d[MaxSize][MaxSize]{};
    int dp[MaxSize]{};
    int pre[MaxSize];
    int dp2d[MaxSize][MaxSize]{};
public:
    Solver() {
        this->init();
    }

    void init(int _s = 0, int _s2 = 0, int _s2d = 0, int _d = 0, int _d2d = 0) {
        fill(this->seq, this->seq + MaxSize, _s);
        fill(this->seq2, this->seq2 + MaxSize, _s2);
        fill(this->seq2d[0], this->seq2d[0] + MaxSize, _s2d);
        fill(this->dp, this->dp + MaxSize, _d);
        fill(this->dp2d[0], this->dp2d[0] + MaxSize, _d2d);
    }

    int FibonacciSetQuestion(int n) {
        this->init();

/*
 * 从斐波那数列的知识中可以看到，
 * 因为斐波那契额数列中有着重叠子问题，所以可以用动态规划
 */
        if (n == 0 || n == 1)return 1;
        if (this->dp[n] != -1) return this->dp[n];
        else {
            this->dp[n] = FibonacciSetQuestion(n - 1) + FibonacciSetQuestion(n - 2);
            return this->dp[n];
        }
    }

    void numberTowerSolutionNoneRecursion(int n) {
        for (int l = n - 1; l >= 1; --l) {
            for (int i = 1; i <= l; ++i) {
                this->dp2d[l][i] = max(this->dp2d[l + 1][i], this->dp2d[l + 1][i + 1]) + this->seq2d[l][i];
            }
        }
    }

    int numberTowerSolutionRecursion(int n, int x, int y) {
        if (this->dp2d[x][y] != -1) {
            return this->dp2d[x][y];
        }
        if (x == n)
            return this->seq2d[x][y];
        this->dp2d[x][y] = max(
                numberTowerSolutionRecursion(n, x + 1, y),
                numberTowerSolutionRecursion(n, x + 1, y + 1)) + this->seq2d[x][y];
        return this->dp2d[x][y];
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
                scanf("%d", &this->seq2d[i][j]);
                this->dp2d[i][j] = -1;
            }
        }
        for (int k = 1; k <= n; ++k) {
            this->dp2d[n][k] = this->seq2d[n][k];
        }// DP 边界
        numberTowerSolutionRecursion(n, 1, 1);
        printf("%d\n", this->dp2d[1][1]);
        return 0;
    }

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
            cin >> this->seq[i];
        }
        this->dp[0] = seq[0]; // 初始设定为 相同
        for (int j = 1; j < n; ++j) {
            this->dp[j] = max(this->dp[j - 1], 0) + seq[j];
        }
        int best = 0;
        for (int k = 1; k < n; ++k) {
            if (this->dp[k] > this->dp[best]) {
                best = k;
            }
        }
        printf("%d", this->dp[best]);
        /*
         * 通过最长子序列问题，可以看到动态规划的难点。
         *
         * ————如何涉及状态和状态转移方程。并且该状态要具有无后性。
         * 所谓的无后性，就是指后面的状态的变化和前面状态的变化无关，
         * 对于最长子序列和问题，就是dp[i] 只和 dp[i-1]有关而必须和dp[i+1]无关。
         */
    }

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
            cin >> this->seq[i];
        }
        int LIS_biggest = -1; // LIS中最大元素有多大呢？
        for (int j = 1; j < n; ++j) {
            this->dp[j] = 1;
            for (int i = 0; i < j; ++i) {
                if (this->seq[i] > this->seq[j] && (this->dp[i] + 1) > this->dp[j]) {
                    this->dp[j] = this->dp[i] + 1;
                }
            }
            LIS_biggest = max(LIS_biggest, this->dp[j]);
        }
        printf("%d", LIS_biggest);
    }

    void LongestCommonSubsequenceProblem() {
        /*
         * 最长公共子序列。
         * dp[i][j]含义：
         *      A[i] 与 B[i] 之前的LCS长度。
         * dp状态方程
         *  dp[i][j] =
         *      if A[i] == B[i] : dp[i-1][j-1]+1
         *      if A[i] != B[i] : max(dp[i][j-1],dp[i-1][j])
         *
         */
        init();
        string _s1, _s2;
        string s1, s2;
        cin >> _s1 >> _s2;
        s1 = " " + _s1;
        s2 = " " + _s2;
        for (int i = 0; i < s1.length(); ++i) {
            this->dp2d[i][0] = 0;
        }
        for (int i = 0; i < s2.length(); ++i) {
            this->dp2d[0][i] = 0;
        }
        for (int i = 1; i < s1.length(); ++i) {
            for (int j = 1; j < s2.length(); ++j) {
                if (s1[i] == s2[j]) {
                    this->dp2d[i][j] = this->dp2d[i - 1][j - 1] + 1;
                } else {
                    this->dp2d[i][j] = max(this->dp2d[i - 1][j], this->dp2d[i][j - 1]);
                }
            }
        }
        printf("%d", dp2d[s1.length() - 1][s2.length() - 1]);
    }

    void LongestPalindromeSubstringProblem() {
        /*
         * 最长回文子串 LPS
         */
        string s;
        cin >> s;
        int ans = 1;
        this->init(); // 这里初始为全0了。
        for (int i = 0; i < s.length(); ++i) {
            this->dp2d[i][i] = 1;
            if (i + 1 < s.length()) {
                this->dp2d[i][i + 1] = (s[i] == s[i + 1]) ? 1 : 0;
                ans = (s[i] == s[i + 1]) ? 2 : 1;
            }
        }
        for (int subLen = 3; subLen <= s.length(); ++subLen) { // 这里是等号
            for (int i = 0; i + subLen - 1 < s.length(); ++i) {
                int j = i + subLen - 1;
                if (s[i] == s[j]) {
                    this->dp2d[i][j] = this->dp2d[i + 1][j - 1];
                    ans = subLen; // 说一下这里为啥能直接更新，因为subLen是不断递增上来的，所以能到这里的subLen一定是最大的。
                }
            }
        }
        printf("%d", ans);
    }

    int _DP(int i, int n) {
        if (this->dp[i] > 0) return this->dp[i];
        for (int j = 0; j < n; ++j) {
            int tmp = this->_DP(j, n) + this->seq2d[i][j];
            if (tmp > this->dp[i]) {
                this->dp[i] = tmp;
                this->pre[i] = j;
            }
        }
        return this->dp[i];
    }

    void DAGProblem() {
        init(0, 0, 0x3fffffff, 0, 0);

    }


    int OneZeroBagProblem() {
        /*
         * 01背包问题
         * 第i件物品重量 w[i] 价格c[i]
         *
         * 非优化的情况（二维数组）
         *
         * dp[i][j] 表示前i件物品恰好装入容量为v的背包，所能够获得的最大价值。
         * 1 <= i <= n
         * 0 <= j <= V
         *
         * 对于每件物品，有取或者不取两种情况，
         * 取：相当于求前i-1件物品恰好装入容量为v-w[i]的背包中所能取得的最大价值
         * dp[i][j] = dp[i-1][V - w[i]] + c[i]
         * 不取：相当于求解前i-1间物品恰好装入容量为v的背包中所能取得的最大价值
         * dp[i][j] = dp[i-1][V]
         *
         */
        int n, V;
        cin >> n >> V;
        this->init(); // 初始化的时候全为0。
        for (int i = 1; i <= n; ++i) {
            cin >> this->seq[i]; // seq 表示重量
        }
        for (int j = 1; j <= n; ++j) {
            cin >> this->seq2[j]; // seq2 表示价格
        }

        for (int i = 1; i <= n; ++i) {
            for (int v = V; v >= seq[i]; --v) {
                this->dp[v] = max(this->dp[v], this->dp[v - seq[i]] + seq2[i]);
            }
        }
        int max = 0;
        for (int v = 0; v <= V; ++v) {
            if (dp[v] > max) {
                max = dp[v];
            }
        }
        cout << max;
        /*
        for (int i = 1; i <= n; ++i) {
            for (int v = seq[i]; v <= V; ++v) {
                this->dp2d[i][v] = max(this->dp2d[i - 1][v],
                                       this->dp2d[i - 1][v - this->seq[i]] + this->seq2[i]);
            }
        }
         */
        /*
         * 之后，来考虑优化的情况
         * 由于 dp[i][v] 依赖于 dp[i-1][v ... w[i]] 的数据，也就是说，第一个维度可以完全省略
         * 于是就有了 dp[v] = max(dp[v],dp[v-w[i]] + c[i])
         * 但是，一定要逆序遍历v，为啥呢？看如下图。
         */

    }

};


int alg_solver() {
    Solver s;
    s.OneZeroBagProblem();
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

sadstory
adminsorry


 PATZJUJZTACCBCC

5 8
3 5 1 2 2
4 5 2 1 3

*/
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
    // 先写个暴力的，妥妥超时
    int sum = 0;
    int maxDepth = 0;
    int memo3d[5010][7][16] = {0};
    int memo2d[7][16] = {0};
    int max = 1e9 + 7;
    void DFS(int depth, int preId, int preCnt, vector<int> &rollMax) {
        if (rollMax[preId] < preCnt) return;
        if (depth == maxDepth) {
            sum++;
            return;
        } else {
            for (int i = 1; i <= 6; i++) {
                if (preId == i) {
                    DFS(depth + 1, i, preCnt + 1, rollMax);
                } else {
                    DFS(depth + 1, i, 1, rollMax);
                }
            }
        }
    }

public:
    int __dieSimulator(int n, vector<int> &rollMax) {
        rollMax.insert(rollMax.begin(), 0x3fff);
        maxDepth = n;
        DFS(0, 0, 1, rollMax);
        return sum;
    }

    int _dieSimulator(int n, vector<int> &rollMax) {
        // 三维DP的做法
        // DP[ni][i][t] 的含义是: 第ni次投掷的时候，投出点数i，且点数之前连续投出t次时，可能的投掷序列个数
        // 解决3个问题
        /*
         * 0. 如何初始化
         * 1. 如何计算最终结果
         * 2. 如何计算每次转移。
         *
         * 0： dp[0][i][1] = 1 i=1..6
         * 1 : result = sum(dp[n-1][i][t]) i=1...6;t=1...rollMax[i];
         * 2 : 这个比较复杂，但是我们不难得出，当前的 dp[ni][i][t] 应该可以由上一次的dp[ni-1][][]得出
         *  对此，我们需要记录上一次投出了啥，记录其为j(j=1...6。以及上次这个点数j重复了多少次，我们记录其为t(t=1...rollMax[j]))
         *  于是，转移方程如下
         *
         *  if i!=j : dp[ni][i][1] += dp[ni-1][j][t] t=1...rollMax[j]
         *  if i==j : dp[ni][i][t+1] += dp[ni-1][j][t] t=1...rollMax[j]-1
         *
         *
         */
        rollMax.insert(rollMax.begin(), 0x3fff);
        for (int i = 1; i <= 6; i++)
            memo3d[0][i][1] = 1;
        for (int ni = 1; ni < n; ni++) {
            for (int i = 1; i <= 6; i++) { // 当前出现的点数
                for (int j = 1; j <= 6; j++) {// 上次出现的点数
                    if (i != j) {
                        for (int t = 1; t <= rollMax[j]; t++) {
                            memo3d[ni][i][1] += memo3d[ni - 1][j][t];
                            memo3d[ni][i][1] %= max;
                        }
                    } else {
                        for (int t = 1; t < rollMax[j]; t++) {
                            memo3d[ni][i][t + 1] += memo3d[ni - 1][j][t];
                            memo3d[ni][i][t + 1] %= max;
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= 6; i++) {
            for (int t = 1; t <= rollMax[i]; t++) {
                sum += memo3d[n - 1][i][t];
                sum %= max;
            }
        }
        return sum;
    }

    int dieSimulator(int n, vector<int> &rollMax) {
        /*
         * 观察之前的dp方程
         *  if i!=j : dp[ni][i][1] += dp[ni-1][j][t] t=1...rollMax[j]
         *  if i==j : dp[ni][i][t+1] += dp[ni-1][j][t] t=1...rollMax[j]-1
         *  我们发现，其实dp[ni] 只与dp[ni-1]有关，因此可以采用滚轴数组的方法给dp降维
         *
         *  因而可以简化为:
         *
         *  if i!=j : dp[i][1] = dp[j][t]
         *  if i==j : dp[i][t+1] = dp[j][t]
         *
         *  滚轴数组中最需要考虑下标的遍历顺序问题。首先不难发现，上述两个条件是互斥的。
         *  先来考虑第一个条件，显然t是从1...rollMax[j]更新，而i!=j，两者之间不影响
         *  再来考虑第二个条件，简单来理解，这个操作就很像是将数组向右平移一个单位，因此顺序遍历即可。（对于这种写法而言）
         *  然而我的想法好像不太正确...哪里更新丢失了嘛。。。。不研究了。
         *
         *
         */
        rollMax.insert(rollMax.begin(), 0x3fff);
        for (int i = 1; i <= 6; i++)
            memo2d[i][1] = 1;
        for (int ni = 1; ni < n; ni++) {
            for (int i = 1; i <= 6; i++) { // 当前出现的点数
                for (int j = 1; j <= 6; j++) {// 上次出现的点数
                    if (i != j) {
                        for (int t = 1; t <= rollMax[j]; t++) {
                            memo2d[i][1] += memo2d[j][t];
                            memo2d[i][1] %= max;
                        }
                    } else {
                        for (int t = rollMax[j] - 1; t > 1; t--) {
                            memo2d[i][t + 1] += memo2d[j][t];
                            memo2d[i][t + 1] %= max;
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= 6; i++) {
            for (int t = 1; t <= rollMax[i]; t++) {
                sum += memo2d[i][t];
                sum %= max;
            }
        }
        return sum;
    }

};
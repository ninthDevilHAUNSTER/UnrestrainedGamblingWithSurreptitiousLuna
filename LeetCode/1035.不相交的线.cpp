//
// Created by shaob on 2020/3/21.
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
    int dp[512][512] = {0};
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        // 这不是最长公共子序列的问题么。正好复习一下
        // dp[i][j] 包含A[i]与B[j]的子串中，最长公共子序列的长度
        // 初始 dp[i][0] = 1 (if A[i] == B[0]) j相同
        // dp[i][j] = dp[i-1][j-1] +1  if A[i] == B[j]
        // dp[i][j] = max(dp[i-1][j],dp[i][j-1])
        for(int i=1;i<=A.size();i++){
            for(int j=1;j<=B.size();j++){
                if(A[i-1] == B[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[A.size()][B.size()];
    }
};
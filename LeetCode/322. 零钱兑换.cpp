//
// Created by shaob on 2020/3/15.
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

 无限背包

 将无线个质量为i的物品放到容量为v的背包中
 无限背包，更新新值，从前往后

*/
class Solution {
private:
    vector<int> dp;
public:



//    int coinChange(vector<int> &coins, int amount) {
//        dp.resize(amount + 1, amount); // 全都不装的情况.
//        for (int i = 1; i <= coins.size(); ++i) {
//            for (int j = coins[i]; j <= amount; ++j) {
//                dp[j] = max(dp[j], dp[j - coins[i]] + 1);
//            }
//        }
//    }
};
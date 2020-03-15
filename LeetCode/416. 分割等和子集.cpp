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

给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

注意:

每个数组中的元素不会超过 100
数组的大小不会超过 200

 100 * 200 = 2 0000 =>

*/

class Solution {
private:
    vector<bool> dp;
    int dp2d[20000][20000];

    int calsum(vector<int> &nums) {
        int res = 0;
        for (auto &i:nums) {
            assert(i > 0);
            res += i;
        }
        return res;
    }


public:
    int tryPartition(vector<int> &nums, int index, int sum) {
        // 使用nums[0..index[ 是否可以完全填充一个容量为sum的背包
        if (sum == 0) return true;
        if (sum < 0 || index < 0) return false;
        if (dp2d[index][sum] != -1) return dp2d[index][sum];
        dp2d[index][sum] = (tryPartition(nums, index - 1, sum)
                            || tryPartition(nums, index - 1, sum - nums[index])) ? 1 : 0;
        return dp2d[index][sum] == 1;
    }

    bool _canPartition(vector<int> &nums) {
        fill(dp2d[0], dp2d[0] + 20000 * 20000, -1);
        int sum = calsum(nums);
        tryPartition(nums, nums.size() - 1, sum / 2);
    }

    bool canPartition(vector<int> &nums) {
        int sum = calsum(nums);
        if (sum % 2 == 1)return false;
        sum /= 2;
        dp.resize(sum + 1, false);
        // 01背包，从后往前
        for (int j = 0; j <= sum; j++) {
            dp[j] = (nums[0] == j); // 初始条件.当前数字能否填满大小为sum的背包？
        }
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = sum; j >= nums[i]; --j) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp[sum];
    }
};
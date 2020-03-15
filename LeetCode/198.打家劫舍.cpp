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



*/
class Solution {
private:
    vector<int> memo;


    int tryRob(vector<int> &nums, int index) {
        // 考虑抢劫 nums[index,..,nums.size());
        if (index >= nums.size()) {
            return 0;
        }
        if (memo[index] != -1)
            return memo[index];
        int res = 0;
        for (int i = index; i < nums.size(); ++i) {
            res = max(res, nums[i] + tryRob(nums, i + 2));
        }
        memo[index] = res;
        return memo[index];
    }

    int _tryRob(vector<int> &nums, int index) {
        // 考虑抢劫 nums[index,..,nums.size());
        if (index >= nums.size()) {
            return 0;
        }
        int res = 0;
        for (int i = index; i < nums.size(); ++i) {
            res = max(res, nums[i] + tryRob(nums, i + 2));
        }
        return res;
    }

public:
    int _rob(vector<int> &nums) {
        memo.resize(nums.size(), -1);
        tryRob(nums, 0);
        return memo[nums.size()-1];
    }

    int rob_old(vector<int> &nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        memo.resize(nums.size(), -1);
        memo[n - 1] = nums[n - 1];
        for (int i = n - 2; i > 0; i--) {
            for (int j = i; j < n; j++) {
                memo[i] = max(memo[i], nums[j] + (j + 2 < n ? memo[j + 2] : 0));
            }
        }
        return memo[0];
    }

    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        memo.resize(nums.size(), -1);
        memo[0] = nums[0];
        for (int i = 1; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                memo[i] = max(memo[i], nums[j] + (j - 2 >= 0 ? memo[j - 2] : 0));
            }
        }
        return memo[n-1];
    }
};
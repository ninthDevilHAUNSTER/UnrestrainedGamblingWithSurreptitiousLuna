//
// Created by shaob on 2020/3/16.
//
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> memo;
public:

    int _rob(vector<int> &nums, int start, int end) {
        memo.clear();
        memo[start] = nums[start]; // 偷了第一家，不能偷最后一家
        for (int i = start + 1; i <= end; i++) {
            for (int j = i; j >= start; j--) {
                memo[i] = max(memo[i], nums[j] + ((j - 2 >= start) ? memo[j - 2] : 0));
            }
        }
        return memo[end];
    }

    int rob(vector<int> &nums) {
        /*
        * dp[i] = max(dp[i], 不偷
        i-2>=0 ? dp[j-2]:0 + nums[j] 偷;此时的dp应该是旧的dp
        )
        *
        */
        int n = nums.size();
        memo.resize(n, -1);
        if (n == 0) return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[1], nums[0]);
        return max(_rob(nums, 0, n - 2), _rob(nums, 1, n - 1));
    }
};
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
    int judge(string &i) {
        if ()
    }

public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+10, 0);
        if (s[0] == '0')
            return 0;
        dp[0] = 1; // 一定可以编码且只有一种方案
        int tmp;
        for (int i = 1; i < s.size(); ++i) {
            tmp = (s[i - 1] - '0') * 10 + s[i] - '0';//和前一个字符合起来的值
            if (s[i] > '0')
                dp[i + 1] = dp[i];//此处不为0，继承前一项的方法数
            if (tmp > 9 && tmp <= 26)
                dp[i + 1] += dp[i - 1];//如果和前面一项合起来在10~26直接，则再加上前两项的数
            if (dp[i + 1] == 0)
                return 0;//出现不合法直接返回0
        }
        return dp[s.size() - 1];
    }
};
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
public:
    static int lengthOfLongestSubstring(string s) {
        // 双指针解决问题
        int left = 0;
        int right = 0;
        unordered_set<char> memo;
        int max_len = 0;
        while(right<s.length() && left<s.length()){
            if(memo.empty() || memo.find(s[right])==memo.end()){
                memo.insert(s[right++]);
                max_len = max(max_len,right-left);
            }else{
                // 如果没找到，整体往左移动一格
                memo.erase(memo.find(s[left]));
                left++;
            }
        }
        return max_len;
    }
};
int main() {
    cout << Solution::lengthOfLongestSubstring("pwwkew");
    return 0;
}
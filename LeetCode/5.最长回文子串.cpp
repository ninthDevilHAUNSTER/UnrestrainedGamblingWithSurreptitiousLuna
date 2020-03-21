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
    int    dp[1024][1024] = {0};
public:
    string longestPalindrome(string s) {
        // 最长回文子串问题LPS
        // dp[i][j] 表示从s[i] - s[j] 的字符串是否回文
        // 注意其遍历的顺序，是从长度为1遍历到长度为s.len()/2
        // if s[i]==s[j] dp[i][j] = dp[i+1][j-1]
        // if s[i]!=s[j] dp[i][j] = 0
        // init for i=0..s.len-1
        // dp[i][i] = 1
        // dp[i][i+1] = 1/0
        int max_len = 1;
        if(s.length()==0) return "";
        else if(s.length() == 1) return s;
        for(int i=0;i<s.length()-1;i++){
            dp[i][i] = 1;
            if(s[i]==s[i+1]){
                dp[i][i+1] =1;
                max_len = 2;
            }
        }
        dp[s.length()-1][s.length()-1] = 1;
        for(int len=3;len<=s.length();len++){
            for(int i=0;i+len-1<s.length();i++){
                int j = i+len-1;
                if(s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1];
                    if(dp[i][j] == 1 ) max_len = len;
                }
            }
        }
        cout << max_len;
        for(int i=0;i+max_len-1<s.length();i++){
            if(dp[i][i+max_len-1] == 1){
                return s.substr(i,max_len);
            }
        }
        return s.substr(0,1);
    }
};
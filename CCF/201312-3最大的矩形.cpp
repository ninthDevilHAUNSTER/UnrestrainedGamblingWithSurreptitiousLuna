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
int N;
vector<int> input;
// 单调
int solve(vector<int> &heights) {
    int n = heights.size();
    vector<int> left(n), right(n);
    stack<int> stk;
    for (int i = 0; i < n; ++i) {
        while (!stk.empty() && heights[stk.top()] >= heights[i]) stk.pop();
        if (stk.empty()) left[i] = -1;
        else left[i] = stk.top();
        stk.push(i);
    }
    while (!stk.empty()) stk.pop();
    for (int j = n - 1; j >= 0; --j) {
        while (!stk.empty() && heights[stk.top()] >= heights[j]) stk.pop();
        if (stk.empty()) right[j] = n;
        else right[j] = stk.top();
        stk.push(j);
    }
    int res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, heights[i] * (right[i] - left[i] - 1));
    return res;
}


int csp_solver() {
    stack<int> ascStack;
    ascStack.push(0);
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int _i;
        scanf("%d", &_i);
        input.push_back(_i);
    }
//    int maxArea = -1;
//    for (int j = 0; j < input.size(); ++j) {
//        while (!ascStack.empty() && input[j] < input[ascStack.top()]) {
//            int top = ascStack.top();
//            ascStack.pop();
//            maxArea = max(maxArea, input[top] * (ascStack.empty() ? j : (j - ascStack.top() - 1)));
//        }
//        ascStack.push(j);
//    }
    printf("%d", solve(input));
    return 0;
}
/*
测试样例



*/
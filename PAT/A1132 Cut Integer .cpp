//
// Created by shaob on 2020/3/10.
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

using namespace std;
#define INF 0x3fffffff
#define inf 0x3fffffff

int pat_solver() {
    int N;
    string buffer;
    string left, right;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        cin >> buffer;
        left = buffer.substr(0, buffer.length() / 2);
        right = buffer.substr(buffer.length() / 2, buffer.length() / 2);
        long long n = stoll(buffer);
        long long nRight = stoll(left);
        long long nLeft = stoll(right);
        if (nRight * nLeft != 0 && n % (nRight * nLeft) == 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}

/*
测试样例



*/
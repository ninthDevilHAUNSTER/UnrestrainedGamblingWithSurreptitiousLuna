//
// Created by shaob on 2020/3/9.
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
#define MaxSize 100010
int input[MaxSize];
int dis[MaxSize]; // 第i天最
int N;

int a[MaxSize];

int pat_solver() {
    int n, e = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n, greater<>());
    while (e < n && a[e] > e + 1) e++;
    printf("%d", e);
    return 0;
}

/*
测试样例



*/
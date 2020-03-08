//
// Created by shaob on 2020/3/7.
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

using namespace std;
#define MaxSize 1024

int N;
int father[MaxSize];
int isRoot[MaxSize];
int course[MaxSize];

int init() {
    fill(isRoot, isRoot + MaxSize, 0);
    fill(course, course + MaxSize, 0);
    for (int i = 1; i < MaxSize; ++i) {
        father[i] = i;
    }
    return 0;
}

int findFather(int x) {
    if (father[x] == x) return x;
    else {
        int f = findFather(father[x]);
        father[x] = f;
        return f;
    }
}

int Union(int x, int y) {
    int r1 = findFather(x);
    int r2 = findFather(y);
    if (r1 != r2) {
        father[r1] = r2;
        return r2;
    } else {
        return -1;
    }
}

int cmp(int a, int b) {
    return a > b;
}


int pat_solver() {
    init();
    scanf("%d", &N);
    int _n, _c;
    int cnt = 0;
    for (int i = 1; i <= N; ++i) {
        scanf("%d:", &_n);
        for (int j = 0; j < _n; ++j) {
            scanf("%d", &_c);
            if (course[_c] == 0) {
                course[_c] = i;
            }
            Union(i, findFather(course[_c]));
        }
    }
    for (int k = 1; k <= N; ++k) {
        int s = findFather(k);
        isRoot[s]++;
    }
    for (int m = 1; m <= N; ++m) {
        if (isRoot[m] != 0) cnt++;
    }
    printf("%d\n", cnt);
    sort(isRoot, isRoot + N + 1, cmp);
    for (int l = 0; l < cnt; ++l) {
        printf("%d", isRoot[l]);
        if (l < cnt - 1) printf(" ");
    }
    return 0;
}

/*
测试样例



*/
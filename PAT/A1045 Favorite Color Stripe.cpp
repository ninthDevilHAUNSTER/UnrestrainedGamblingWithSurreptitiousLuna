//
// Created by shaob on 2020/3/6.
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
#define MaxSize 100010
#define MaxColor 256
int N, M, L;
int favour[MaxColor];
int hashfavour[MaxColor];
int seq[MaxSize];
int dp[MaxSize];

int LIS() {
    dp[0] = 1;
    for (int i = 0; i <; ++i) {

    }

    return 0;
}


int pat_solver() {
    int _;
    fill(hashfavour, hashfavour + MaxColor, -1);
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; ++i) {
        scanf("%d", &favour[i]);
        hashfavour[favour[i]] = i;
    }
    scanf("%d", &L);
    for (int j = 0; j < L; ++j) {
        scanf("%d", &_);
        if (hashfavour[_] > 0)
    }
    return 0;
}

/*
测试样例



*/

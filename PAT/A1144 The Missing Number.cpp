//
// Created by shaob on 2020/3/12.
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
map<int,bool> isExist;


int pat_solver() {
    int N, _i;
//    fill(isExist, isExist + 1000100, false);
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &_i);
        _i > 0 ? isExist[_i] = true : 0;
    }
    int z = 1;
    while (isExist[z]) z++;
    printf("%d", z);

    return 0;
}

/*
测试样例



*/
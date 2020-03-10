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
/*
 * 顶点覆盖集合，在这个集合里面，能够包含所有边的起点。
 *
 * 当然，不是让你求，而是让你判断啦。求的话我的理论知识还不够
 * 判断就好说了。遍历一层即可。
 *
 */
#define MaxSize 10010
int N, M, K;
vector<int> net[MaxSize];
bool edgeVisit[MaxSize * MaxSize]; // pre*MaxSize + now;

bool isCoverVertex() {
    for (int i = 0; i < N; ++i) {
        for (auto z: net[i]) {
            if (edgeVisit[z]) {
                continue;
            } else {
                return false;
            }
        }
    }
    return true;
}

int pat_solver() {
    scanf("%d%d", &N, &M);
    int _1, _2, _c;
    for (int i = 0; i < M; ++i) {
        scanf("%d%d", &_1, &_2);
        net[_1].push_back(i);
        net[_2].push_back(i);
    }
    scanf("%d", &K);
    for (int j = 0; j < K; ++j) {
        fill(edgeVisit, edgeVisit + M, false);
        scanf("%d", &_c);
        for (int i = 0; i < _c; ++i) {
            scanf("%d", &_1);
            for (auto z: net[_1]) {
                edgeVisit[z] = true;
            }
        }
        isCoverVertex() ? printf("Yes\n") : printf("No\n");
    }
    return 0;
}

/*
测试样例



*/
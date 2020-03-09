//
// Created by shaob on 2020/3/9.
//

/*
 * 当前环是否为哈密顿环（包含所有点的简单回路）
 *
 * undirected graph 无向图
 */
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
#define MaxSize 210
int N, M;
int Graph[MaxSize][MaxSize];
int vis[MaxSize];
vector<int> path;
set<int> s;

bool Judge() {
    assert(!path.empty());
    fill(vis, vis + MaxSize, -1);
    if (s.size() != N || path.size() != N + 1 || path.front() != path.back()) return false; // 回路大小一定为N+1
    vis[path.front()] = 1;
    for (int i = 1; i < path.size(); ++i) {
        if (Graph[path[i - 1]][path[i]] != INF) {
            vis[path[i]] = 1;
        } else {
            return false;
        }
    }
    return true;
}

int pat_solver() {
    fill(Graph[0], Graph[0] + MaxSize * MaxSize, INF);
    int _1, _2, K, _n;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; ++i) {
        scanf("%d%d", &_1, &_2);
        Graph[_1][_2] = Graph[_2][_1] = 1;
    }
    scanf("%d", &K);
    for (int j = 0; j < K; ++j) {
        path.clear();
        s.clear();
        scanf("%d", &_n);
        for (int i = 0; i < _n; ++i) {
            scanf("%d", &_1);
            path.push_back(_1);
            s.insert(_1); // 之前写的欠考虑，但是我也check是否所有的点都遍历了啊，为啥测试点1还是没过去呢，后来用了柳诺的办法，就AC了。
        }
        if (Judge()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}

/*
测试样例



*/



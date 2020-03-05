//
// Created by shaob on 2020/3/5.
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
/// 要点 DFS 求连通分量个数
int N, M, K; // city num; remain highway;city to be check;
vector<int> G[MaxSize];
bool vis[MaxSize];
int occupied_city;

void DFS(int node) {
    vis[node] = true;
    for (auto c:G[node]) {
        if (!vis[c]) DFS(c);
    }
}

int pat_solver() {
    int _1, _2;
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 0; i < M; ++i) {
        scanf("%d%d", &_1, &_2);
        G[_1].push_back(_2);
        G[_2].push_back(_1); // 无向图，两边走
    }
    for (int j = 0; j < K; ++j) {
        fill(vis, vis + MaxSize, false); /// 傻逼了我草，这边加了一个n，应该是加MaxSize
        scanf("%d", &occupied_city);
        vis[occupied_city] = true;
        int connection_component = 0;
        for (int i = 1; i <= N; ++i) { // 它是从1开始的。
            if (!vis[i]) {
                DFS(i);
                connection_component++;
            }
        }
        printf("%d\n", connection_component - 1);
    }
    return 0;
}

/*
测试样例



*/

//
// Created by shaob on 2020/2/23.
//
#include "PATMainHeader.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MaxSize = 512;
const int INF = 0x3fffffff;
int cost[MaxSize][MaxSize];
int distant[MaxSize][MaxSize]; // 优先考虑.
int N; // number of cities
int M; // number of highways;
int start;
int destination;
int d[MaxSize];
int c[MaxSize];
bool visit[MaxSize];
vector<int> pre[MaxSize];
vector<int> bestPath, tmpPath;
int preNode[MaxSize];
int tmpCost, BestCost;

int dj(int s) {
    d[s] = 0;
    c[s] = 0;
    for (int i = 0; i < N; ++i) {
        int v = -1, min = INF;
        for (int j = 0; j < N; ++j) {
            if (!visit[j] && d[j] < min) {
                min = d[j];
                v = j;
            }
        }
        if (v == -1)return 0;
        visit[v] = true;
        for (int k = 0; k < N; ++k) {
            if (!visit[k] && distant[v][k] != INF) {
                if (distant[v][k] + d[v] < d[k]) {
                    d[k] = distant[v][k] + d[v];
                    c[k] = cost[v][k] + c[v];
                    preNode[k] = v;
//                    pre[k].clear();
//                    pre[k].push_back(v);
                } else if (distant[v][k] + d[v] == d[k]) {
                    if (c[k] > cost[v][k] + c[v]) {
                        c[k] = cost[v][k] + c[v];
                        preNode[k] = v;
                    }
//                    pre[k].push_back(v);
                }
            }
        }
    }
}

//#pragma clang diagnostic push
//#pragma ide diagnostic ignored "InfiniteRecursion"

void print_pre(int v) {
    if (v == start) {
        printf("%d ", v);
        return;
    }
    print_pre(preNode[v]);
    printf("%d ", v);
}

//#pragma clang diagnostic pop

/*
void DFS(int v) {
    if (v == start) {
        tmpPath.push_back(v);
        cal_

    }
    tmpPath.push_back(v);
    for (int i = 0; i < pre[v].size(); ++i) {
        DFS(pre[v][i]);
    }
    tmpPath.pop_back();
}
*/


int _pat_solver() {
    fill(cost[0], cost[0] + MaxSize * MaxSize, INF);
    fill(distant[0], distant[0] + MaxSize * MaxSize, INF);
    fill(d, d + MaxSize, INF);
    fill(c, c + MaxSize, 0);
    fill(visit, visit + MaxSize, false);
    for (int j = 0; j < MaxSize; ++j) {
        preNode[j] = j;
    }
    cin >> N >> M >> start >> destination;
    int _c1, _c2;
    for (int i = 0; i < M; ++i) {
        cin >> _c1 >> _c2;
        cin >> distant[_c1][_c2];
        cin >> cost[_c1][_c2];
    }
    dj(start);
    print_pre(destination);
    printf("%d %d", d[destination], c[destination]);
    return 0;
}
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
//int c[MaxSize];
bool visit[MaxSize];
vector<int> pre[MaxSize];
vector<int> bestPath, tmpPath;
int optValue = INF; // 第二标尺最优值

int dj(int s) {
    d[s] = 0;
//    c[s] = 0;
    for (int i = 0; i < N; ++i) {
        int v = -1, min = INF;
        for (int j = 0; j < N; ++j) {
            if (!visit[j] && d[j] < min) {
                min = d[j];
                v = j;
            }
        }
        if (v == -1) break;
        visit[v] = true;
        for (int k = 0; k < N; ++k) {
            if (!visit[k] && distant[v][k] != INF) {
                if (distant[v][k] + d[v] < d[k]) {
                    d[k] = distant[v][k] + d[v];
                    pre[k].clear();
                    pre[k].push_back(v);
                } else if (distant[v][k] + d[v] == d[k]) {
                    pre[k].push_back(v);
                }
            }
        }
    }
}

int cal_path_sum() {
    int value = 0;
    for (auto i = int(tmpPath.size() - 1); i > 0; --i) {
        int id = tmpPath[i], idNext = tmpPath[i - 1];
        value += cost[id][idNext];
    }
    return value;
}

void DFS(int v) {
    // v 为当前节点，题目中的 destination
    if (v == start) {
        tmpPath.push_back(v); // 将起点加入临时路径的最后面
        int value = cal_path_sum(); // 第二尺度的值
        // calculate second ruler
        if (value < optValue) {
            optValue = value;
            bestPath = tmpPath;
        }
        tmpPath.pop_back();
        return;
    }
    tmpPath.push_back(v);
    for (int i = 0; i < pre[v].size(); ++i) {
        DFS(pre[v][i]);
    }
    tmpPath.pop_back();
}


int pat_solver() {
    fill(cost[0], cost[0] + MaxSize * MaxSize, INF);
    fill(distant[0], distant[0] + MaxSize * MaxSize, INF);
    fill(d, d + MaxSize, INF);
    fill(visit, visit + MaxSize, false);
    cin >> N >> M >> start >> destination;
    int _c1, _c2;
    for (int i = 0; i < M; ++i) {
        cin >> _c1 >> _c2;
        cin >> distant[_c1][_c2];
        cin >> cost[_c1][_c2];
    }
    dj(start);
    DFS(destination);
    for (unsigned long j = bestPath.size() - 1; j > 0; --j) {
        printf("%d ", bestPath[j]);
    } // 0 -1 会跳到 正无穷，所以这么操作一下。坑的一笔
    printf("%d ", bestPath[0]);
    printf("%d %d", d[destination], optValue);
    return 0;
}
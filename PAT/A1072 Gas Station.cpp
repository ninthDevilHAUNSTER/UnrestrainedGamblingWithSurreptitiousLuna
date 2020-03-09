//
// Created by shaob on 2020/3/8.
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

int N, M, K;
double DS;
double road_net[1024][1024];
double d[1024];
bool vis[1024];

vector<int> prePath[1024];

void dj(int start) {
    fill(vis, vis + 1024, false);
    fill(d, d + 1024, INF);
    d[start] = 0;
    for (int i = 0; i <= M + N + 10; ++i) {
        double MIN = INF;
        int v = -1;
        for (int j = 1; j <= M + N; ++j) {
            if (!vis[j] && d[j] < MIN) {
                v = j;
                MIN = d[j];
            }
        }
        if (v == -1)return;
        vis[v] = true;
        for (int k = 1; k <= M + N; ++k) {
            if (!vis[k] && road_net[v][k] != INF) {
                if (road_net[v][k] + d[v] < d[k]) {
                    d[k] = road_net[v][k] + d[v];
                }
            }
        }
    }
}

struct result {
    int gasId = -1;
    double closeDis = -1;
    double avgDis = INF;

    bool operator<(const result &b) {
        if (closeDis != b.closeDis) {
            return closeDis > b.closeDis;
        } else if (avgDis != b.avgDis) {
            return avgDis < b.avgDis;
        } else {
            return gasId < b.gasId;
        }
    }
} tmpResult, optResult;


int pat_solver() {
    fill(road_net[0], road_net[0] + 1024 * 1024, inf);
    fill(d, d + 1024, inf);
    scanf("%d%d%d%lf", &N, &M, &K, &DS);
    for (int i = 1; i <= K; ++i) {
        string p1, p2;
        int id1, id2, tmp;
        cin >> p1 >> p2 >> tmp;
        if (p1[0] == 'G') {
            id1 = N + stoi(p1.substr(1));
        } else {
            id1 = stoi(p1);
        }
        if (p2[0] == 'G') {
            id2 = N + stoi(p2.substr(1));
        } else {
            id2 = stoi(p2); // 这里写错了我debug了半天。。。
        }
        road_net[id2][id1] = road_net[id1][id2] = tmp;
    }
    for (int j = N + 1; j <= N + M; ++j) { // 没有G0
        dj(j);
        // 获取与居民房的最小距离与平均距离
        double tmp_minDis = INF;
        double tmp_sumDis = 0;
        bool able_flag = true;
        for (int i = 1; i <= N; ++i) {
            if (d[i] < tmp_minDis) tmp_minDis = d[i];
            if (d[i] > DS) {
                able_flag = false;
                break;
            }
            tmp_sumDis += d[i];
        }
        if (!able_flag) continue;
        tmpResult = {j, tmp_minDis, 1.00 * tmp_sumDis / N};
        if (tmpResult < optResult) optResult = tmpResult;
    }
    if (optResult.gasId == -1) printf("No Solution");
    else {
        printf("G%d\n%.1f %.1f", optResult.gasId - N, optResult.closeDis, optResult.avgDis);
    }
    return 0;
}

/*
测试样例



*/
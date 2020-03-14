//
// Created by shaob on 2020/2/23.
//

// #include "PATMainHeader.h"

#include <iostream>
#include <algorithm>

using namespace std;

#define MaxSize 510
#define INF 0x3fffffff

int N = 0; // number of city
int M = 0;// number of road
int C1 = 0;
int C2 = 0;
int rescue_team_number[MaxSize];
int road_net[MaxSize][MaxSize];
int dist[MaxSize];
bool visit[MaxSize];
int num[MaxSize];
int w[MaxSize];

int dj_modified(int s) {
    dist[s] = 0;
    num[s] = 1;
    w[s] = rescue_team_number[s];
    for (int i = 0; i < N; ++i) {
        int u = -1, min = INF;
        for (int j = 0; j < N; ++j) {
            if (!visit[j] && dist[j] < min) {
                u = j;
                min = dist[j];
            }
        }
        if (u == -1)return 0;
        visit[u] = true;
        for (int k = 0; k < N; ++k) {
            if (!visit[k] && road_net[u][k] != INF) {
                if (road_net[u][k] + dist[u] < dist[k]) { // 优化！
                    dist[k] = road_net[u][k] + dist[u];
                    num[k] = num[u];
                    w[k] = w[u] + rescue_team_number[k];
                } else if (road_net[u][k] + dist[u] == dist[k]) {
                    if (
                            w[k] < w[u] + rescue_team_number[k]
                            ) {
                        w[k] = w[u] + rescue_team_number[k];
                    }
                    num[k] += num[u];
                }
            }
        }
    }
    return 0;
}


int pat_solver() {
    fill(road_net[0], road_net[0] + MaxSize * MaxSize, INF);
    fill(dist, dist + MaxSize, INF);
    cin >> N >> M >> C1 >> C2;
    int _c1, _c2;
    for (int i = 0; i < N; ++i) {
        cin >> rescue_team_number[i];
    }
    for (int j = 0; j < M; ++j) {
        cin >> _c1 >> _c2;
        cin >> road_net[_c1][_c2];
        road_net[_c2][_c1] = road_net[_c1][_c2];
    }
    dj_modified(C1);
    printf("%d %d", num[C2], w[C2]);
    return 0;
};
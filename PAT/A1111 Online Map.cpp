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

/*
 * 找出最短路和最快路。有向图。点从0-N-1
 *
 * 如果最短路不唯一，那就找出最短路中的最快路
 *
 * 如果最快路不唯一，那就找出最快路中的最短路
 *
 */
#define MaxSize 512
int N, M; //N 点数，M 路数

struct intersections {
    int length = INF;
    int time = INF;
} net[MaxSize][MaxSize];
bool vis[MaxSize];
//int dis[MaxSize];
int d[MaxSize];
//int tim[MaxSize];
int t[MaxSize];
int start;
int destination;
int pre_bestT[MaxSize];
int pre_bestL[MaxSize];

void init() {
    fill(vis, vis + N, false);
    fill(d, d + N, INF);
    fill(t, t + N, INF);
    for (int i = 0; i < N; ++i) {
        pre_bestL[i] = i;
        pre_bestT[i] = i;
    }
}

vector<int> preDistanceVector[MaxSize];
vector<int> preTimeVector[MaxSize];

void dj_length(int s) {
    fill(vis, vis + MaxSize, false);
    d[s] = 0;
    for (int i = 0; i < N; ++i) {
        int MIN = INF, v = -1;
        for (int j = 0; j < N; ++j) {
            if (!vis[j] && d[j] < MIN) {
                MIN = d[j];
                v = j;
            }
        }
        if (v == -1)break;
        vis[v] = true;
        for (int k = 0; k < N; ++k) {
            if (!vis[k] && net[v][k].length != INF) {
                if (net[v][k].length + d[v] < d[k]) {
                    d[k] = net[v][k].length + d[v];
                    preDistanceVector[k].clear();
                    preDistanceVector[k].push_back(v);
                } else if (net[v][k].length + d[v] == d[k]) {
                    preDistanceVector[k].push_back(v);
                }
            }
        }
    }
}

void dj_time(int s) {
    fill(vis, vis + MaxSize, false);
    t[s] = 0;
    for (int i = 0; i < N; ++i) {
        int MIN = INF, v = -1;
        for (int j = 0; j < N; ++j) {
            if (!vis[j] && t[j] < MIN) {
                MIN = t[j];
                v = j;
            }
        }
        if (v == -1)break;
        vis[v] = true;
        for (int k = 0; k < N; ++k) {
            if (!vis[k] && net[v][k].time != INF) {
                if (net[v][k].time + t[v] < t[k]) {
                    t[k] = net[v][k].time + t[v];
                    preTimeVector[k].clear();
                    preTimeVector[k].push_back(v);
                } else if (net[v][k].time + t[v] == t[k]) {
                    preTimeVector[k].push_back(v);
                }
            }
        }
    }
}

vector<int> tmpPath, bestTimePath, bestDistancePath;
int optBestTimePathShortestDistanceCost = INF;
int optBestDistancePathShortestTimeCost = INF;

void DFS_t(int v) {
    if (v == start) {
        tmpPath.push_back(v);
        int tmpDisSum = 0;
        for (int i = int(tmpPath.size() - 1); i > 0; --i) {
            tmpDisSum += net[tmpPath[i]][tmpPath[i - 1]].length;
        }
        if (tmpDisSum <= optBestTimePathShortestDistanceCost) {
            optBestTimePathShortestDistanceCost = tmpDisSum;
            bestTimePath = tmpPath;
        }
        tmpPath.pop_back();
        return;
    }
    tmpPath.push_back(v);
    for (int i : preTimeVector[v]) {
        DFS_t(i);
    }
    tmpPath.pop_back();
}


void DFS_d(int v) {
    if (v == start) {
        tmpPath.push_back(v);
        int tmpTimSum = 0;
        for (int i = int(tmpPath.size() - 1); i > 0; --i) {
            tmpTimSum += net[tmpPath[i]][tmpPath[i - 1]].time;
        }
        if (tmpTimSum <= optBestDistancePathShortestTimeCost) {
            optBestDistancePathShortestTimeCost = tmpTimSum;
            bestDistancePath = tmpPath;
        }
        tmpPath.pop_back();
        return;
    }
    tmpPath.push_back(v);
    for (int i : preDistanceVector[v]) {
        DFS_d(i);
    }
    tmpPath.pop_back();
}


int pat_solver() {
    int _v1, _v2, _one_way, _length, _time;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; ++i) {
        scanf("%d%d%d%d%d", &_v1, &_v2, &_one_way, &_length, &_time);
        net[_v1][_v2] = {_length, _time};
        if (_one_way == 0) net[_v2][_v1] = {_length, _time};
    }
    init();
    scanf("%d%d", &start, &destination);
    dj_length(start);
    dj_time(start);
    DFS_d(destination);
    DFS_t(destination);

    bool flag = true;
    if (bestTimePath.size() == bestDistancePath.size()) {
        for (int i = 0; i < bestDistancePath.size(); ++i) {
            if (bestDistancePath[i] == bestTimePath[i]) continue;
            else {
                flag = false;
                break;
            }
        }
    }else{
        flag = false;
    }


    if (flag) {
        printf("Distance = %d; Time = %d:", optBestTimePathShortestDistanceCost, optBestDistancePathShortestTimeCost);
        for (int i = int(bestTimePath.size() - 1); i >= 0; --i) {
            printf(" %d", bestTimePath[i]);
            if (i > 0) printf(" ->");
        }
    } else {
        int optDis = 0, optTime = 0;
        for (int i = int(bestDistancePath.size() - 1); i > 0; --i) {
            optDis += net[bestDistancePath[i]][bestDistancePath[i - 1]].length;
        }
        printf("Distance = %d:", optDis);
        for (int i = int(bestDistancePath.size() - 1); i >= 0; --i) {
            printf(" %d", bestDistancePath[i]);
            if (i > 0) printf(" ->");
        }
        printf("\n");

        for (int i = int(bestTimePath.size() - 1); i > 0; --i) {
            optTime += net[bestTimePath[i]][bestTimePath[i - 1]].time;
        }
        printf("Time = %d:", optTime);
        for (int i = int(bestTimePath.size() - 1); i >= 0; --i) {
            printf(" %d", bestTimePath[i]);
            if (i > 0) printf(" ->");
        }
    }
    return 0;
}

/*
测试样例



*/
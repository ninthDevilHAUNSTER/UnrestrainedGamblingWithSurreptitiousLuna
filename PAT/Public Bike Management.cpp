//
// Created by shaob on 2020/2/24.
//

#include "PATMainHeader.h"
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

#define MAX_CAPACITY 128
#define MAX_STATION 512
#define INF 0x3fffffff

int Cmax = 0; // 每个站点最多能放多少车
int N = 0;// 站点数
int Sp = 0;// 出问题的车站
int M = 0; // 公路数
//int PBMC = 0;// 假定PBMC就是0


int s[MAX_STATION];
int road_time[MAX_STATION][MAX_STATION];

int dist[MAX_STATION];
bool visit[MAX_STATION];
vector<int> pre[MAX_STATION];
vector<int> tmpPath, bestPath;

int dj(int pbmc) {
    dist[pbmc] = 0;
    for (int i = 0; i <= N; ++i) { //对应的就要导致DJ中的所有遍历都要改变。
        int MIN = INF, v = -1;
        for (int j = 0; j <= N; ++j) {
            if (!visit[j] && dist[j] < MIN) {
                MIN = dist[j];
                v = j;
            }
        }
        if (v == -1)break;
        visit[v] = true;
        for (int k = 0; k <= N; ++k) {
            if (!visit[k] && road_time[v][k] != INF) {
                if (road_time[v][k] + dist[v] < dist[k]) {
                    dist[k] = road_time[v][k] + dist[v];
                    pre[k].clear();
                    pre[k].push_back(v);
                } else if (road_time[v][k] + dist[v] == dist[k]) {
                    pre[k].push_back(v);
                }
            }
        }
    }
    return 0;
}

int optNeed = INF;
int optBack = INF;

int cal_back_and_need_value() {
    int need = 0, back = 0;
    for (int i = int(tmpPath.size() - 1); i >= 0; --i) {
        int current_station_need = s[tmpPath[i]];
        if (current_station_need > 0) {
            back += s[tmpPath[i]];
        } else {
            //  current_station_need <0
            if (back > -current_station_need) {
                back += current_station_need; // 实际上是减去绝对值
            } else {
                need -= (back + current_station_need);// 实际上是负负得正
                back = 0;
            }
        }
    }
    if (need < optNeed) { // 先考虑能带出的
        optNeed = need;
        optBack = back;
        bestPath = tmpPath;
    } else if (need == optNeed && back < optBack) { // 再考虑带回的
        optBack = back;
        bestPath = tmpPath;
    }
    return 0;
}

int dfs(int end) {
    tmpPath.push_back(end);
    if (end == 0) {
        cal_back_and_need_value(); // DFS 的核心函数，计算了值并更新最佳路径和最佳门限值
        tmpPath.pop_back();
        return 0;
    }
    for (int i = 0; i < pre[end].size(); ++i) {
        dfs(pre[end][i]);
    }
    tmpPath.pop_back();
    return 0;
}

int pat_solver() {
    fill(dist, dist + MAX_STATION, INF);
    fill(visit, visit + MAX_STATION, false);
    fill(road_time[0], road_time[0] + MAX_STATION * MAX_STATION, INF);

    scanf("%d%d%d%d", &Cmax, &N, &Sp, &M);
    for (int i = 1; i <= N; ++i) { // 该题有1个坑点，就是得i从1开始计算。 给的N是从1...N。
        scanf("%d", &s[i]);
        s[i] -= Cmax / 2; // 关键点~
    }
    int _s1, _s2;
    for (int j = 0; j < M; ++j) {
        scanf("%d%d", &_s1, &_s2);
        scanf("%d", &road_time[_s1][_s2]);
        road_time[_s2][_s1] = road_time[_s1][_s2];
    }
    dj(0);
    dfs(Sp);
    printf("%d 0", optNeed);
    for (int k = int(bestPath.size() - 2); k >= 0; --k) {
        printf("->%d", bestPath[k]);
    }
    printf(" %d", optBack);
    return 0;
}
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
#define MaxSize 256
int net[MaxSize][MaxSize];
int N, M, K;
vector<int> path;
int vis[MaxSize];

/*
 * 旅行商环路：
 *
 * 1）每个点都访问
 * 2）最后回到原城市
 *
 * 当且仅当除了起点的每个点都访问一次的时候，是最简旅行商环路
 *
 */

bool allVisitOnce() {
    for (int i : path) {
        if (vis[i] != 1) return false;
    }
    return true;
}

bool allVisit(int &dis) {
    /*
     * 所有点都遍历到了，并且所有边都可达
     */
    bool rt_flag = true;
    for (int i = 1; i <= N; ++i) {
        if (vis[i] == 0) rt_flag = false;
    }
    for (int i = 1; i < path.size(); ++i) {
        if (net[path[i - 1]][path[i]] == INF) {
            dis = INF;
            return false;
        } else {
            dis += net[path[i - 1]][path[i]];
        }
    }
    return rt_flag;
}

int pat_solver() {
    int _c1, _c2, _d;
    fill(net[0], net[0] + MaxSize * MaxSize, INF);
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; ++i) {
        scanf("%d%d%d", &_c1, &_c2, &_d);
        net[_c1][_c2] = net[_c2][_c1] = _d;
    }
    scanf("%d", &K);
    int minDis = INF;
    int minPath = -1;
    for (int j = 1; j <= K; ++j) {
        fill(vis, vis + MaxSize, 0);
        path.clear();
        scanf("%d", &_d);
        for (int i = 0; i < _d; ++i) {
            scanf("%d", &_c1);
            path.push_back(_c1);
            vis[_c1]++;
        }
        int dis = 0;
        if (allVisit(dis) && path.front() == path.back()) {
            vis[path.front()]--;
            if (allVisitOnce()) {
                printf("Path %d: %d (TS simple cycle)\n", j, dis);
            } else {
                printf("Path %d: %d (TS cycle)\n", j, dis);
            }
            if (dis < minDis) {
                minDis = dis;
                minPath = j;
            }
        } else {
            printf("Path %d: %s (Not a TS cycle)\n", j, dis != INF ? to_string(dis).c_str() : "NA");
        }
    }
    printf("Shortest Dist(%d) = %d", minPath, minDis);
    return 0;
}

/*
测试样例

6 10
6 2 1
3 4 1
1 5 1
2 5 1
3 1 8
4 1 6
1 6 1
6 3 1
1 2 1
4 5 1
4
6 5 1 4 3 6 2
4 1 2 5 1
7 6 1 2 5 4 3 1
7 6 3 2 5 4 1 6


*/
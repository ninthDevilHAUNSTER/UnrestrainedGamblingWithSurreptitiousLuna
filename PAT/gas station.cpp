//
// Created by shaob on 2020/2/24.
//

/*

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
const int inf = 999999999;
int n, m, k, ds, station;
int e[1020][1020], dis[1020];
bool visit[1020];

int main() {
    fill(e[0], e[0] + 1020 * 1020, inf);
    fill(dis, dis + 1020, inf);
    scanf("%d%d%d%d", &n, &m, &k, &ds);
    for (int i = 0; i < k; i++) {
        int tempdis;
        string s, t;
        cin >> s >> t >> tempdis;
        int a, b;
        if (s[0] == 'G') {
            s = s.substr(1);
            a = n + stoi(s);
        } else {
            a = stoi(s);
        }
        if (t[0] == 'G') {
            t = t.substr(1);
            b = n + stoi(t);
        } else {
            b = stoi(t);
        }
        e[a][b] = e[b][a] = tempdis;
    }
    int ansid = -1;
    double ansdis = -1, ansaver = inf;
    for (int index = n + 1; index <= n + m; index++) {
        double mindis = inf, aver = 0;
        fill(dis, dis + 1020, inf);
        fill(visit, visit + 1020, false);
        dis[index] = 0;
        for (int i = 0; i < n + m; i++) {
            int u = -1, minn = inf;
            for (int j = 1; j <= n + m; j++) {
                if (!visit[j]&& dis[j] < minn) {
                    u = j;
                    minn = dis[j];
                }
            }
            if (u == -1) break;
            visit[u] = true;
            for (int v = 1; v <= n + m; v++) {
                if (!visit[v] && dis[v] > dis[u] + e[u][v])
                    dis[v] = dis[u] + e[u][v];
            }
        }
        for (int i = 1; i <= n; i++) {
            if (dis[i] > ds) {
                mindis = -1;
                break;
            }
            if (dis[i] < mindis) mindis = dis[i];
            aver += 1.0 * dis[i];
        }
        if (mindis == -1) continue;
        aver = aver / n;
        if (mindis > ansdis) {
            ansid = index;
            ansdis = mindis;
            ansaver = aver;
        } else if (mindis == ansdis && aver < ansaver) {
            ansid = index;
            ansaver = aver;
        }
    }
    if (ansid == -1)
        printf("No Solution");
    else
        printf("G%d\n%.1f %.1f", ansid - n, ansdis, ansaver);
    return 0;
}

 */

//#include "PATMainHeader.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int maxHouses = 1024; // consider 128 >> 103 + 10
const int maxGasStation = 10;
const int maxRoads = 128;
const int INF = 0x3fffffff;

int N = 0; // houses
int M = 0; // gas station candidate
int K = 0; // roads
int DS = 0; // max service range

int road_net[maxHouses][maxHouses];
int dist[maxHouses];
bool visit[maxHouses];
vector<int> pre[maxHouses];
bool ableFlag[maxHouses];

int dj(int s) {
    fill(visit, visit + maxHouses, false);
    fill(dist, dist + maxHouses, INF);
    dist[s] = 0;
    for (int i = 0; i <= N + M; ++i) {
        int MIN = INF, v = -1;
        for (int j = 1; j <= M + N; ++j) {
            if (!visit[j] && dist[j] < INF) {
                MIN = dist[j];
                v = j;
            }
        }
        if (v == -1)break;
        visit[v] = true;
        for (int k = 1; k <= M + N; ++k) {
            if (!visit[k] && road_net[v][k] != INF && road_net[v][k] + dist[v] < dist[k]) {
                dist[k] = road_net[v][k] + dist[v];
            }
        }
    }

    return 0;
}


int BestMinDis = -1;
double BestAvgDis = 0.0;
int BestLocation = -1;

int pat_solver() {
    fill(road_net[0], road_net[0] + maxHouses * maxHouses, INF);
    scanf("%d%d%d%d", &N, &M, &K, &DS);
    for (int i = 1; i <= K; ++i) {
        string p1, p2;
        int id1, id2;
        cin >> p1 >> p2;
        if (p1[0] == 'G') {
            id1 = N + stoi(p1.substr(1));
        } else {
            id1 = stoi(p1);
        }
        if (p2[0] == 'G') {
            id2 = N + stoi(p2.substr(1));
        } else {
            id2 = stoi(p1);
        }
        scanf("%d", &road_net[id1][id2]);
        road_net[id2][id1] = road_net[id1][id2];
    }
    for (int j = N + 1; j <= N + M; ++j) {
        int minDis = INF;
        int sum = 0;
        double avg = 0.0;
        dj(j);

        for (int i = 1; i <= N; ++i) {
            if (dist[i] > DS) {
                minDis = -1;
                break;
            } else {
                if (minDis > dist[i]) {
                    minDis = dist[i];
                }
                sum += dist[i];
                cout <<  dist[i] << "\t";
            }
        }
        avg = sum * 1.0 / N;
        cout << avg << endl;
        if (minDis == -1) continue;
        else {
            if (minDis > BestMinDis) {
                BestLocation = j;
                BestMinDis = minDis;
                BestAvgDis = avg;
            } else if (minDis == BestMinDis && BestAvgDis > avg) {
                BestLocation = j;
                BestAvgDis = avg;
            }
        }
    }
    if (BestLocation == -1) {
        printf("No Solution");
    } else {
        cout << "G" << BestLocation - N << endl;
        printf("%.1f %.1f", double(BestMinDis), BestAvgDis);
    }
    return 0;
}
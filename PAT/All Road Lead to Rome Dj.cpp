//
// Created by shaob on 2020/2/24.
//
#include <iostream>
#include <cstdio>
#include <unordered_map>

using namespace std;

#include <string>
#include <algorithm>

#define INF 0x3fffffff
#define MaxSize 200
int N = 0;//cities
int K = 0;//routes
unordered_map<string, int> name2id;
unordered_map<int, string> id2name;

int road[MaxSize][MaxSize];
int weight[MaxSize];
int visit[MaxSize];
int w[MaxSize];
int d[MaxSize];
vector<int> preVector[MaxSize];
int num[MaxSize];
int pre[MaxSize];
int pt[MaxSize];

int dj(int s) {
    fill(visit, MaxSize + visit, false);
    fill(num, num + MaxSize, 1);
    fill(w, w + MaxSize, INF);
    fill(d, d + MaxSize, INF);
    fill(pt, pt + MaxSize, 0);
    d[s] = 0;
    w[s] = 0;
    for (int i = 0; i < N; ++i) {
        int MIN = INF, v = -1;
        for (int j = 0; j < N; ++j) {
            if (!visit[j] && d[j] < MIN) {
                MIN = d[j];
                v = j;
            }
        }
        if (v == -1)break;
        visit[v] = true;
        for (int k = 0; k < N; ++k) {
            if (!visit[k] && road[v][k] != INF) {
                if (road[v][k] + d[v] < d[k]) {
                    d[k] = d[v] + road[v][k];
                    w[k] = w[v] + weight[k];
                    num[k] = num[v];
                    pt[k] = pt[v] + 1; // pt 代表了路径上的顶点个数
                    pre[k] = v;
                } else if (road[v][k] + d[v] == d[k]) {
                    num[k] += num[v];
                    if (w[k] < w[v] + weight[k]) {
                        w[k] = w[v] + weight[k];
                        pt[k] = pt[v] + 1;
                        pre[k] = v;
                    } else if (w[k] == w[v] + weight[k]) {
                        double avgNew = 1.0 * (w[v] + weight[k]) / (pt[v] + 1);
                        double avgOld = 1.0 * (w[k]) / pt[k];
                        if (avgNew > avgOld) {
                            pt[k] = pt[v] + 1;
                            pre[k] = v;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

void dfs(int s, const int id) {
    if (s == id) {
        printf("%s", (id2name[s]).c_str());
        return;
    }
    dfs(pre[s], id);
    printf("->%s", (id2name[s]).c_str());
}

int pat_solver() {
    // init
    fill(road[0], road[0] + MaxSize * MaxSize, INF);
    fill(weight, weight + MaxSize, 0);
    string cityName;
    string cityName2;
    int cityId = 0;
    int _dis = 0;
    int _h = 0;
    cin >> N >> K >> cityName;
    name2id[cityName] = cityId;
    id2name[cityId] = cityName;
    for (int i = 1; i < N; ++i) {
        cityId++;
        cin >> cityName;
        name2id[cityName] = cityId;
        id2name[cityId] = cityName;
        cin >> weight[cityId];
    }
    for (int j = 0; j < K; ++j) {
        cin >> cityName >> cityName2 >> _dis;
        road[name2id[cityName]][name2id[cityName2]] = _dis;
        road[name2id[cityName2]][name2id[cityName]] = _dis;
    }
    // calculate
    dj(0);
    int dstId = name2id["ROM"];
    printf("%d %d %d %d\n", num[dstId], d[dstId], w[dstId],w[dstId] / pt[dstId]);
    dfs(dstId, 0);
}
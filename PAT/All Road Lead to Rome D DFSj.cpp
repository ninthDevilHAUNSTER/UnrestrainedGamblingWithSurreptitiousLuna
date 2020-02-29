//
// Created by shaob on 2020/2/24.
//
#include <iostream>
#include <cstdio>
#include <unordered_map>

using namespace std;

#include <string>
#include <algorithm>
#include <vector>

#define INF 0x3fffffff
#define MaxSize 200
int N = 0;//cities
int K = 0;//routes
unordered_map<string, int> name2id;
unordered_map<int, string> id2name;

int road[MaxSize][MaxSize];
int weight[MaxSize];
int visit[MaxSize];
int d[MaxSize];
vector<int> preVector[MaxSize];

int dj(int s) {
    fill(visit, MaxSize + visit, false);
    fill(d, d + MaxSize, INF);
    d[s] = 0;
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
                    d[k] = road[v][k] + d[v];
                    preVector[k].clear();
                    preVector[k].push_back(v);
                } else if (road[v][k] + d[v] == d[k]) {
                    preVector[k].push_back(v);
                }
            }
        }
    }
    return 0;
}

vector<int> tmpPath, bestPath;
int numPath = 0;// 最短路径条数
double bestAvgWei = 0.0;
int bestWeiSum = 0;

int calculator() {
    numPath++; // 每调用一次计算器，就代表有1个最短路径返回。
    int currentWeiSum = 0;
    double currentAvgWei = 0;
    // 计算边权
    for (int i = int(tmpPath.size() - 2); i >= 0; i--) { // 最后一个点无权值，不算也罢,算了也是0
        currentWeiSum += weight[tmpPath[i]];
    }
    currentAvgWei = 1.0 * currentWeiSum / (int(tmpPath.size()) - 1);// 注意了，第一个点不参与运算
    if (currentWeiSum > bestWeiSum) {
        // renew
        bestWeiSum = currentWeiSum;
        bestAvgWei = currentAvgWei;
        bestPath = tmpPath;
    } else if (currentWeiSum == bestWeiSum) {
        if (bestAvgWei < currentAvgWei) {
            bestAvgWei = currentAvgWei;
            bestPath = tmpPath;
        }
    }
    return 0;
}


void DFS(int v) {
    if (v == 0) {
        tmpPath.push_back(v);
        calculator();
        tmpPath.pop_back();
        return;
    }
    tmpPath.push_back(v);
    for (int i = 0; i < preVector[v].size(); i++) {
        DFS(preVector[v][i]);
    }
    tmpPath.pop_back();
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
    DFS(dstId);
    printf("%d %d %d %d\n", numPath, d[dstId], bestWeiSum, int(bestAvgWei));
    for (int k = int(bestPath.size() - 1); k > 0; --k) {
        printf("%s->", (id2name[bestPath[k]]).c_str());
    }
    printf("%s", (id2name[bestPath[0]]).c_str());
}
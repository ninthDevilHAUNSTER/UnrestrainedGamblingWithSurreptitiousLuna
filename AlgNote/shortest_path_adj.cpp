//
// Created by shaob on 2020/2/23.
//

#include "AlgNoteMainHeader.h"

#include <iostream>
#include <vector>

using namespace std;
#define  INF 0x3ffffff
#define  MaxSize 0xfff

struct Node {
    int v = 0, dis = 0;

    Node(int _v, int _dis) {
        v = _v;
        dis = _dis;
    }
};

#include <set>

struct Graph {
    vector<Node> Adj[MaxSize];
    bool vis[MaxSize] = {};
    int n = 0;
    int d[MaxSize] = {};
    int pre[MaxSize] = {};
    set<int> preSet[MaxSize];

    Graph() {
        for (int i = 0; i < MaxSize; ++i) {
            pre[i] = i; // 每个点的前驱状态为自身
        }
        fill(d, d + MaxSize, INF);
        fill(vis, vis + MaxSize, false);
    }
};

bool BF_Adj(Graph &G, int s) {
    for (int i = 0; i < G.n - 1; ++i) {
        for (int u = 0; u < G.n; ++u) {
            for (int j = 0; j < G.Adj[u].size(); ++j) {
                int v = G.Adj[u][j].v;
                int dis = G.Adj[u][j].dis;
                if (G.d[u] + dis < G.d[v]) {
                    G.d[v] = G.d[u] + dis;
                }
            }
        }
    }
    for (int u = 0; u < G.n; ++u) {
        for (int j = 0; j < G.Adj[u].size(); ++j) {
            int v = G.Adj[u][j].v;
            int dis = G.Adj[u][j].dis;
            if (G.d[u] + dis < G.d[v]) {
                return false;
            }
        }
    }
    return true;
}

void Dj_Adj(Graph &G, int s) {
    G.d[s] = 0;
    for (int i = 0; i < G.n; ++i) { // 循环 n 次，其实i咋样不起作用。
        int min = INF, min_p = -1;
        for (int j = 0; j < G.n; ++j) {
            // 找到最短的 dist
            if (!G.vis[j] && G.d[j] < min) {
                min_p = j;
                min = G.d[j];
            }
        }
        if (min_p == -1)return;
        G.vis[min_p] = true;
        for (int k = 0; k < G.Adj[min_p].size(); ++k) {
            int v = G.Adj[min_p][k].v; //获得点
            if (!G.vis[v] && G.Adj[min_p][k].dis + G.d[min_p] < G.d[v]) {
                G.d[v] = G.d[min_p] + G.Adj[min_p][k].dis;
                G.pre[v] = min_p;
            }
        }
    }
}


int alg_solver() {
    Graph G;
    G.n = 6;
    G.Adj[0].emplace_back(1, 1);
    G.Adj[0].emplace_back(3, 4);
    G.Adj[0].emplace_back(4, 4);
    G.Adj[1].emplace_back(3, 2);
    G.Adj[2].emplace_back(5, 1);
    G.Adj[3].emplace_back(4, 3);
    G.Adj[3].emplace_back(2, 2);
    G.Adj[4].emplace_back(5, 3);
    Dj_Adj(G, 0);
    for (int i = 0; i < G.n; ++i) {
        cout << G.d[i] << "\t";
    }
    return 0;
}
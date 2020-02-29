//
// Created by shaob on 2020/2/23.
//

#include "AlgNoteMainHeader.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 0x3fff
#define MaxSize 100

struct MatrixGraph {
    int mat[MaxSize][MaxSize]{};
    int n{};
    bool vis[MaxSize]{};
    int d[MaxSize]{};
//    int pre[MaxSize]{};
    vector<int> pre[MaxSize]; // 优化的方案
    MatrixGraph() {
        fill(mat[0], mat[0] + MaxSize * MaxSize, INF);
        fill(d, d + MaxSize, INF);
//        fill(pre, pre + MaxSize, 0);
    }
};

void dj_Mat(MatrixGraph &G, int s) {
    G.d[s] = 0;
    for (int i = 0; i < G.n; ++i) {
        int min = INF, u = -1;
        for (int j = 0; j < G.n; ++j) {
            if (!G.vis[j] && G.d[j] < min) {
                min = G.d[j];
                u = j;
            }
        }
        if (u == -1)return;
        G.vis[u] = true;
        for (int k = 0; k < G.n; ++k) {
            if (!G.vis[k] && G.mat[u][k] != INF) {
                if (G.mat[u][k] + G.d[u] < G.d[k]) {
                    G.d[k] = G.mat[u][k] + G.d[u];
//                G.pre[k] = u;
                    G.pre[k].clear(); // 如果权值小，则一定要清空，因为之前的路径并不正确。
                    G.pre[k].push_back(u);
                } else if (G.mat[u][k] + G.d[u] == G.d[k]) {
                    G.pre[k].push_back(u);// 如果权值相等，则不用清空，因为以u为中介点找到的是一条完全相同的路径
                }
            }
        }
    }
}

int optvalue;// 最优值
vector<int> path, tmp_path;// 最优路径与临时路径
/*
void DFS(MatrixGraph &G, int v, int start_pt) {
    // 递归边界
    if (v == start_pt) {
        tmp_path.push_back(v);
        int value;
        // 计算路径
        if(value > opt){
            optvalue = value;
            path  = tempPath;
        }
        tempPath.popback();
        return;
    }
    tmp_path.push_back(v);
    for (int i = 0; i < G.pre[v].size(); ++i) {
        DFS(G, G.pre[v][i], 0);
    }
    tmp_path.pop_back();
}
*/

int alg_solver() {
    MatrixGraph G;
    G.mat[0][1] = 1;
    G.mat[0][3] = 4;
    G.mat[0][4] = 4;
    G.mat[2][5] = 5;
    G.mat[3][4] = 3;
    G.mat[3][2] = 2;
    G.mat[4][5] = 3;
    G.mat[0][1] = 1;
    G.n = 6;
    dj_Mat(G, 0);
    for (int i = 0; i < G.n; ++i) {
        cout << G.d[i] << "\t";
    }
    return 0;
}
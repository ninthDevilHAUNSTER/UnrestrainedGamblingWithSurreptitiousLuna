//
// Created by shaob on 2020/3/5.
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

using namespace std;
#define MaxSize 1024
/// 1 到 N 编号

/*
 * 带有深度的DFS问题
 */
struct node {
    int id = 0;
    int layer = 0;

    explicit node(int _i) : id(_i) {};

    node(int _i, int _l) : id(_i), layer(_l) {};

};

vector<node> adj[MaxSize];
bool vis[MaxSize];
int N, K, L;

/*
void DFS(int node, int depth, int &num) {
    if (depth > K) {
        return;
    } else {
        vis[node] = true;
    }
    for (int i = 1; i < N; ++i) {
        if (!vis[i] && net[node][i] != 0) {
            num++;
            DFS(i, depth + 1, num);
        }
    }
}
 */

int BFS(int i) {
    queue<node> q;
    node start(i);
    q.push(start);
    int sum = 0; // 自身不算转发数
    vis[i] = true;
    while (!q.empty()) {
        node tmp = q.front();
        q.pop();
        for (auto n: adj[tmp.id]) {
            node next(n.id, tmp.layer + 1);
            if (!vis[next.id] && next.layer <= L) {
                q.push(next);
                vis[next.id] = true;
                sum++;
            }
        }
    }
    return sum;
}

int Traverse(int node) {
    fill(vis, vis + MaxSize, false);
    int num = BFS(node);
    return num;
}

int pat_solver() {
//    fill(net[0], net[0] + MaxSize * MaxSize, 0);
    scanf("%d%d", &N, &L);
    int _c, _u;
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &_c);
        for (int j = 0; j < _c; ++j) {
            scanf("%d", &_u);
            adj[_u].emplace_back(i);
        }
    }
    scanf("%d", &K);
    for (int k = 0; k < K; ++k) {
        scanf("%d", &_u);
        int num = Traverse(_u);
        printf("%d\n", num);
    }
    return 0;
}

/*
测试样例



*/
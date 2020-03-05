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
#define Xmax 1300
#define Ymax 132
#define Zmax 80

int M, N, L, T;
/// M N 每片的大小，M * N; 1286 * 128 <max>
/// L 片数， T 门限值，低于此则不计数。

/// 然后给了L 片，每片 M* N (01) 1 代表病变，0代表正常。
/// 每片只需要数1就行了。 三维的BFS。

bool vis[Xmax][Ymax][Zmax] = {false};
int pixel[Xmax][Ymax][Zmax];

int X[6] = {1, 0, 0, -1, 0, 0};
int Y[6] = {0, 1, 0, 0, -1, 0};
int Z[6] = {0, 0, 1, 0, 0, -1};
// 利用一个for 循环可以解决6个方向的问题。

struct node {
    int x = 0;
    int y = 0;
    int z = 0;

    node() = default;

    node(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {};
};

bool valid(node v) {
    if (v.x < 0 || v.y < 0 || v.z < 0 || v.x >= M || v.y >= N || v.z >= L) return false;
    return !(pixel[v.x][v.y][v.z] == 0 || vis[v.x][v.y][v.z]);
}

int BFS(node v) {
    int count = 0;
    queue<node> q;
    q.push(v);
    vis[v.x][v.y][v.z] = true;
    while (!q.empty()) {
        node s = q.front();
        count++;
        q.pop();
        for (int i = 0; i < 6; ++i) {
            node new_node(s.x + X[i], s.y + Y[i], s.z + Z[i]); // 好TM愚蠢。。。这里s写成了v;;;;;;;
            if (valid(new_node)) {
                q.push(new_node);
                vis[new_node.x][new_node.y][new_node.z] = true;
            }
        }
    }
    return count >= T ? count : 0;
}

int BFSTraverse() {
    int ans = 0;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < N; k++) {
                if (pixel[j][k][i] == 1 && !vis[j][k][i])
                    ans += BFS(node(j, k, i));
            }
        }
    }
    return ans;
}

int pat_solver() {
    scanf("%d%d%d%d", &M, &N, &L, &T);
    for (int i = 0; i < L; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k < N; k++)
                scanf("%d", &pixel[j][k][i]);
    printf("%d", BFSTraverse());
    return 0;
}

/*
测试样例



*/